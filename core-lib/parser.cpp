#include "parser.h"
#include "declaration.h"
#include "statement.h"
#include "expression.h"
#include <cassert>
#include <iostream>
#include <string>
#include <unordered_set>
#include <stdexcept>

namespace lucy
{

using namespace ast;

parser::parser() {}
parser::~parser() {}

compilation_unit *parser::parse(std::istream &is)
{
    lex = new lexer(is);
    tk = next();

    std::vector<type_declaration *> ts;
    std::vector<method_declaration *> ms;
    std::vector<predicate_declaration *> ps;
    std::vector<statement *> ss;

    while (tk->sym != symbol::EOF_Symbol)
    {
        switch (tk->sym)
        {
        case symbol::TYPEDEF:
            ts.push_back(_typedef_declaration());
            break;
        case symbol::ENUM:
            ts.push_back(_enum_declaration());
            break;
        case symbol::CLASS:
            ts.push_back(_class_declaration());
            break;
        case symbol::PREDICATE:
            ps.push_back(_predicate_declaration());
            break;
        case symbol::VOID:
            ms.push_back(_method_declaration());
            break;
        case symbol::BOOL:
        case symbol::INT:
        case symbol::REAL:
        case symbol::STRING:
        case symbol::LBRACE:
        case symbol::FACT:
        case symbol::GOAL:
            ss.push_back(_statement());
            break;
        case symbol::ID:
        {
            size_t c_pos = pos;
            tk = next();
            while (match(symbol::DOT))
            {
                if (!match(symbol::ID))
                    error("expected identifier..");
            }
            if (match(symbol::ID) && match(symbol::LPAREN))
            {
                backtrack(c_pos);
                ms.push_back(_method_declaration());
            }
            else
            {
                backtrack(c_pos);
                ss.push_back(_statement());
            }
            break;
        }
        default:
            error("expected either 'typedef' or 'enum' or 'class' or 'predicate' or 'void' or identifier..");
        }
    }

    return new compilation_unit(ts, ms, ps, ss);
}

token *parser::next()
{
    while (pos >= tks.size())
    {
        token *c_tk = lex->next();
        tks.push_back(c_tk);
    }
    return tks[pos++];
}

bool parser::match(const symbol &sym)
{
    if (tk->sym == sym)
    {
        tk = next();
        return true;
    }
    else
    {
        return false;
    }
}

void parser::backtrack(const size_t &p)
{
    pos = p;
    tk = tks[pos - 1];
}

typedef_declaration *parser::_typedef_declaration()
{
    std::string n;
    std::string pt;
    expression *xpr;

    if (!match(symbol::TYPEDEF))
        error("expected 'typedef'..");

    switch (tk->sym)
    {
    case symbol::BOOL:
        pt = "bool";
        break;
    case symbol::INT:
        pt = "int";
        break;
    case symbol::REAL:
        pt = "real";
        break;
    case symbol::STRING:
        pt = "string";
        break;
    default:
        error("expected primitive type..");
    }
    tk = next();

    xpr = _expression();

    if (!match(symbol::ID))
        error("expected identifier..");
    n = static_cast<id_token *>(tks[pos - 2])->id;

    if (!match(symbol::SEMICOLON))
        error("expected ';'..");

    return new typedef_declaration(n, pt, xpr);
}

enum_declaration *parser::_enum_declaration()
{
    std::string n;
    std::vector<std::string> es;
    std::vector<std::vector<std::string>> trs;

    if (!match(symbol::ENUM))
        error("expected 'enum'..");

    if (!match(symbol::ID))
        error("expected identifier..");
    n = static_cast<id_token *>(tks[pos - 2])->id;

    do
    {
        switch (tk->sym)
        {
        case symbol::LBRACE:
            tk = next();
            if (!match(symbol::StringLiteral))
                error("expected string literal..");
            es.push_back(static_cast<string_token *>(tks[pos - 2])->str);

            while (match(symbol::COMMA))
            {
                if (!match(symbol::StringLiteral))
                    error("expected string literal..");
                es.push_back(static_cast<string_token *>(tks[pos - 2])->str);
            }

            if (!match(symbol::RBRACE))
                error("expected '}'..");
            break;
        case symbol::ID:
        {
            std::vector<std::string> ids;
            ids.push_back(static_cast<id_token *>(tk)->id);
            tk = next();
            while (match(symbol::DOT))
            {
                if (!match(symbol::ID))
                    error("expected identifier..");
                ids.push_back(static_cast<id_token *>(tks[pos - 2])->id);
            }
            trs.push_back(ids);
            break;
        }
        default:
            error("expected either '{' or identifier..");
        }
    } while (match(symbol::BAR));

    if (!match(symbol::SEMICOLON))
        error("expected ';'..");

    return new enum_declaration(n, es, trs);
}

class_declaration *parser::_class_declaration()
{
    std::string n;                             // the name of the class..
    std::vector<std::vector<std::string>> bcs; // the base classes..
    std::vector<field_declaration *> fs;       // the fields of the class..
    std::vector<constructor_declaration *> cs; // the constructors of the class..
    std::vector<method_declaration *> ms;      // the methods of the class..
    std::vector<predicate_declaration *> ps;   // the predicates of the class..
    std::vector<type_declaration *> ts;        // the types of the class..

    if (!match(symbol::CLASS))
        error("expected 'class'..");

    if (!match(symbol::ID))
        error("expected identifier..");
    n = static_cast<id_token *>(tks[pos - 2])->id;

    if (match(symbol::COLON))
    {
        do
        {
            std::vector<std::string> ids;
            do
            {
                if (!match(symbol::ID))
                    error("expected identifier..");
                ids.push_back(static_cast<id_token *>(tks[pos - 2])->id);
            } while (match(symbol::DOT));
            bcs.push_back(ids);
        } while (match(symbol::COMMA));
    }

    if (!match(symbol::LBRACE))
        error("expected '{'..");

    while (!match(symbol::RBRACE))
    {
        switch (tk->sym)
        {
        case symbol::TYPEDEF:
            ts.push_back(_typedef_declaration());
            break;
        case symbol::ENUM:
            ts.push_back(_enum_declaration());
            break;
        case symbol::CLASS:
            ts.push_back(_class_declaration());
            break;
        case symbol::PREDICATE:
            ps.push_back(_predicate_declaration());
            break;
        case symbol::VOID:
            ms.push_back(_method_declaration());
            break;
        case symbol::BOOL:
        case symbol::INT:
        case symbol::REAL:
        case symbol::STRING: // either a primitive type method or a field declaration..
        {
            size_t c_pos = pos;
            tk = next();
            if (!match(symbol::ID))
                error("expected identifier..");
            switch (tk->sym)
            {
            case symbol::LPAREN:
                backtrack(c_pos);
                ms.push_back(_method_declaration());
                break;
            case symbol::EQ:
            case symbol::SEMICOLON:
                backtrack(c_pos);
                fs.push_back(_field_declaration());
                break;
            default:
                error("expected either '(' or '=' or ';'..");
            }
            break;
        }
        case symbol::ID: // either a constructor, a method or a field declaration..
        {
            size_t c_pos = pos;
            tk = next();
            switch (tk->sym)
            {
            case symbol::LPAREN:
                backtrack(c_pos);
                cs.push_back(_constructor_declaration());
                break;
            case symbol::DOT:
                while (match(symbol::DOT))
                {
                    if (!match(symbol::ID))
                        error("expected identifier..");
                }
                if (!match(symbol::ID))
                    error("expected identifier..");
                switch (tk->sym)
                {
                case symbol::LPAREN:
                    backtrack(c_pos);
                    ms.push_back(_method_declaration());
                    break;
                case symbol::EQ:
                case symbol::SEMICOLON:
                    backtrack(c_pos);
                    fs.push_back(_field_declaration());
                    break;
                default:
                    error("expected either '(' or '=' or ';'..");
                }
                break;
            case symbol::ID:
                tk = next();
                switch (tk->sym)
                {
                case symbol::LPAREN:
                    backtrack(c_pos);
                    ms.push_back(_method_declaration());
                    break;
                case symbol::EQ:
                case symbol::SEMICOLON:
                    backtrack(c_pos);
                    fs.push_back(_field_declaration());
                    break;
                default:
                    error("expected either '(' or '=' or ';'..");
                }
                break;
            default:
                error("expected either '(' or '.' or an identifier..");
            }
            break;
        }
        default:
            error("expected either 'typedef' or 'enum' or 'class' or 'predicate' or 'void' or identifier..");
        }
    }

    return new class_declaration(n, bcs, fs, cs, ms, ps, ts);
}

field_declaration *parser::_field_declaration()
{
    std::vector<std::string> ids;
    std::string n;
    std::vector<variable_declaration *> ds;

    switch (tk->sym)
    {
    case symbol::BOOL:
        ids.push_back("bool");
        tk = next();
        break;
    case symbol::INT:
        ids.push_back("int");
        tk = next();
        break;
    case symbol::REAL:
        ids.push_back("real");
        tk = next();
        break;
    case symbol::STRING:
        ids.push_back("string");
        tk = next();
        break;
    case symbol::ID:
        ids.push_back(static_cast<id_token *>(tk)->id);
        tk = next();
        while (match(symbol::DOT))
        {
            if (!match(symbol::ID))
                error("expected identifier..");
            ids.push_back(static_cast<id_token *>(tks[pos - 2])->id);
        }
        break;
    default:
        error("expected either 'bool' or 'int' or 'real' or 'string' or an identifier..");
    }

    if (!match(symbol::ID))
        error("expected identifier..");
    n = static_cast<id_token *>(tks[pos - 2])->id;

    if (match(symbol::EQ))
        ds.push_back(new variable_declaration(n, _expression()));
    else
        ds.push_back(new variable_declaration(n));

    while (match(symbol::COMMA))
    {
        if (!match(symbol::ID))
            error("expected identifier..");
        n = static_cast<id_token *>(tks[pos - 2])->id;

        if (match(symbol::EQ))
            ds.push_back(new variable_declaration(n, _expression()));
        else
            ds.push_back(new variable_declaration(n));
    }

    if (!match(symbol::SEMICOLON))
        error("expected ';'..");

    return new field_declaration(ids, ds);
}

method_declaration *parser::_method_declaration()
{
    std::vector<std::string> ids;
    std::string n;
    std::vector<std::pair<std::vector<std::string>, std::string>> pars;
    std::vector<statement *> stmnts;

    if (!match(symbol::VOID))
    {
        do
        {
            if (!match(symbol::ID))
                error("expected identifier..");
            ids.push_back(static_cast<id_token *>(tks[pos - 2])->id);
        } while (match(symbol::DOT));
    }

    if (!match(symbol::ID))
        error("expected identifier..");
    n = static_cast<id_token *>(tks[pos - 2])->id;

    if (!match(symbol::LPAREN))
        error("expected '('..");

    if (!match(symbol::RPAREN))
    {
        do
        {
            std::vector<std::string> p_ids;
            switch (tk->sym)
            {
            case symbol::BOOL:
                p_ids.push_back("bool");
                tk = next();
                break;
            case symbol::INT:
                p_ids.push_back("int");
                tk = next();
                break;
            case symbol::REAL:
                p_ids.push_back("real");
                tk = next();
                break;
            case symbol::STRING:
                p_ids.push_back("string");
                tk = next();
                break;
            case symbol::ID:
                p_ids.push_back(static_cast<id_token *>(tk)->id);
                tk = next();
                while (match(symbol::DOT))
                {
                    if (!match(symbol::ID))
                        error("expected identifier..");
                    p_ids.push_back(static_cast<id_token *>(tks[pos - 2])->id);
                }
                break;
            default:
                error("expected either 'bool' or 'int' or 'real' or 'string' or an identifier..");
            }
            if (!match(symbol::ID))
                error("expected identifier..");
            std::string pn = static_cast<id_token *>(tks[pos - 2])->id;
            pars.push_back({p_ids, pn});
        } while (match(symbol::COMMA));

        if (!match(symbol::RPAREN))
            error("expected ')'..");
    }

    if (!match(symbol::LBRACE))
        error("expected '{'..");

    while (!match(symbol::RBRACE))
        stmnts.push_back(_statement());

    return new method_declaration(ids, n, pars, stmnts);
}

constructor_declaration *parser::_constructor_declaration()
{
    std::vector<std::pair<std::vector<std::string>, std::string>> pars;
    std::vector<std::pair<std::string, std::vector<expression *>>> il;
    std::vector<statement *> stmnts;

    if (!match(symbol::ID))
        error("expected identifier..");

    if (!match(symbol::LPAREN))
        error("expected '('..");

    if (!match(symbol::RPAREN))
    {
        do
        {
            std::vector<std::string> p_ids;
            switch (tk->sym)
            {
            case symbol::ID:
                p_ids.push_back(static_cast<id_token *>(tk)->id);
                tk = next();
                while (match(symbol::DOT))
                {
                    if (!match(symbol::ID))
                        error("expected identifier..");
                    p_ids.push_back(static_cast<id_token *>(tks[pos - 2])->id);
                }
                break;
            case symbol::BOOL:
                p_ids.push_back("bool");
                tk = next();
                break;
            case symbol::INT:
                p_ids.push_back("int");
                tk = next();
                break;
            case symbol::REAL:
                p_ids.push_back("real");
                tk = next();
                break;
            case symbol::STRING:
                p_ids.push_back("string");
                tk = next();
                break;
            }
            if (!match(symbol::ID))
                error("expected identifier..");
            std::string pn = static_cast<id_token *>(tks[pos - 2])->id;
            pars.push_back({p_ids, pn});
        } while (match(symbol::COMMA));

        if (!match(symbol::RPAREN))
            error("expected ')'..");
    }

    if (match(symbol::COLON))
    {
        do
        {
            std::string pn;
            std::vector<expression *> xprs;
            if (!match(symbol::ID))
                error("expected identifier..");
            pn = static_cast<id_token *>(tks[pos - 2])->id;

            if (!match(symbol::LPAREN))
                error("expected '('..");

            if (!match(symbol::RPAREN))
            {
                do
                {
                    xprs.push_back(_expression());
                } while (match(symbol::COMMA));

                if (!match(symbol::RPAREN))
                    error("expected ')'..");
            }
            il.push_back({pn, xprs});
        } while (match(symbol::COMMA));
    }

    if (!match(symbol::LBRACE))
        error("expected '{'..");

    while (!match(symbol::RBRACE))
        stmnts.push_back(_statement());

    return new constructor_declaration(pars, il, stmnts);
}

predicate_declaration *parser::_predicate_declaration()
{
    std::string n;
    std::vector<std::pair<std::vector<std::string>, std::string>> pars;
    std::vector<std::vector<std::string>> pl;
    std::vector<statement *> stmnts;

    if (!match(symbol::PREDICATE))
        error("expected 'predicate'..");

    if (!match(symbol::ID))
        error("expected identifier..");
    n = static_cast<id_token *>(tks[pos - 2])->id;

    if (!match(symbol::LPAREN))
        error("expected '('..");

    if (!match(symbol::RPAREN))
    {
        do
        {
            std::vector<std::string> p_ids;
            switch (tk->sym)
            {
            case symbol::BOOL:
                p_ids.push_back("bool");
                tk = next();
                break;
            case symbol::INT:
                p_ids.push_back("int");
                tk = next();
                break;
            case symbol::REAL:
                p_ids.push_back("real");
                tk = next();
                break;
            case symbol::STRING:
                p_ids.push_back("string");
                tk = next();
                break;
            case symbol::ID:
                p_ids.push_back(static_cast<id_token *>(tk)->id);
                tk = next();
                while (match(symbol::DOT))
                {
                    if (!match(symbol::ID))
                        error("expected identifier..");
                    p_ids.push_back(static_cast<id_token *>(tks[pos - 2])->id);
                }
                break;
            }
            if (!match(symbol::ID))
                error("expected identifier..");
            std::string pn = static_cast<id_token *>(tks[pos - 2])->id;
            pars.push_back({p_ids, pn});
        } while (match(symbol::COMMA));

        if (!match(symbol::RPAREN))
            error("expected ')'..");
    }

    if (match(symbol::COLON))
    {
        do
        {
            std::vector<std::string> p_ids;
            do
            {
                if (!match(symbol::ID))
                    error("expected identifier..");
                p_ids.push_back(static_cast<id_token *>(tks[pos - 2])->id);
            } while (match(symbol::DOT));
            pl.push_back(p_ids);
        } while (match(symbol::COMMA));
    }

    if (!match(symbol::LBRACE))
        error("expected '{'..");

    while (!match(symbol::RBRACE))
        stmnts.push_back(_statement());

    return new predicate_declaration(n, pars, pl, stmnts);
}

statement *parser::_statement()
{
    switch (tk->sym)
    {
    case symbol::BOOL:
    case symbol::INT:
    case symbol::REAL:
    case symbol::STRING: // a local field having a primitive type..
    {
        std::vector<std::string> ids;
        switch (tk->sym)
        {
        case symbol::BOOL:
            ids.push_back("bool");
            break;
        case symbol::INT:
            ids.push_back("int");
            break;
        case symbol::REAL:
            ids.push_back("real");
            break;
        case symbol::STRING:
            ids.push_back("string");
            break;
        }
        tk = next();

        if (!match(symbol::ID))
            error("expected identifier..");
        std::string n = static_cast<id_token *>(tks[pos - 2])->id;

        expression *e = nullptr;
        if (tk->sym == symbol::EQ)
        {
            tk = next();
            e = _expression();
        }

        if (!match(symbol::SEMICOLON))
            error("expected ';'..");

        return new local_field_statement(ids, n, e);
    }
    case symbol::ID: // either a local field, an assignment or an expression..
    {
        size_t c_pos = pos;
        std::vector<std::string> ids;
        ids.push_back(static_cast<id_token *>(tk)->id);
        tk = next();
        while (match(symbol::DOT))
        {
            if (!match(symbol::ID))
                error("expected identifier..");
            ids.push_back(static_cast<id_token *>(tks[pos - 2])->id);
        }

        switch (tk->sym)
        {
        case symbol::ID: // a local field..
        {
            std::string n = static_cast<id_token *>(tk)->id;
            expression *e = nullptr;
            tk = next();
            if (tk->sym == symbol::EQ)
            {
                tk = next();
                e = _expression();
            }

            if (!match(symbol::SEMICOLON))
                error("expected ';'..");

            return new local_field_statement(ids, n, e);
        }
        case symbol::EQ: // an assignment..
        {
            std::string id = ids.back();
            ids.pop_back();
            tk = next();
            expression *xpr = _expression();
            if (!match(symbol::SEMICOLON))
                error("expected ';'..");
            return new assignment_statement(ids, id, xpr);
        }
        case symbol::PLUS: // an expression..
        case symbol::MINUS:
        case symbol::STAR:
        case symbol::SLASH:
        case symbol::LT:
        case symbol::LTEQ:
        case symbol::EQEQ:
        case symbol::GTEQ:
        case symbol::GT:
        case symbol::BANGEQ:
        case symbol::IMPLICATION:
        case symbol::BAR:
        case symbol::AMP:
        case symbol::CARET:
        {
            backtrack(c_pos);
            expression *xpr = _expression();
            if (!match(symbol::SEMICOLON))
                error("expected ';'..");
            return new expression_statement(xpr);
        }
        default:
            error("expected either '=' or an identifier..");
        }
    }
    case symbol::LBRACE: // either a block or a disjunction..
    {
        tk = next();
        std::vector<const statement *> stmnts;
        do
        {
            stmnts.push_back(_statement());
        } while (!match(symbol::RBRACE));
        switch (tk->sym)
        {
        case symbol::LBRACKET:
        case symbol::OR: // a disjunctive statement..
        {
            std::vector<std::pair<std::vector<const statement *>, const expression *const>> disjs;
            expression *e = nullptr;
            if (match(symbol::LBRACKET))
            {
                e = _expression();
                if (!match(symbol::RBRACKET))
                    error("expected ']'..");
            }
            disjs.push_back({stmnts, e});
            while (match(symbol::OR))
            {
                stmnts.clear();
                e = nullptr;
                if (!match(symbol::LBRACE))
                    error("expected '{'..");
                do
                {
                    stmnts.push_back(_statement());
                } while (!match(symbol::RBRACE));
                if (match(symbol::LBRACKET))
                {
                    e = _expression();
                    if (!match(symbol::RBRACKET))
                        error("expected ']'..");
                }
                disjs.push_back({stmnts, e});
            }
            return new disjunction_statement(disjs);
        }
        default: // a block statement..
            return new block_statement(stmnts);
        }
    }
    case symbol::FACT:
    case symbol::GOAL:
    {
        bool isf = tk->sym == symbol::FACT;
        tk = next();
        std::string fn;
        std::vector<std::string> scp;
        std::string pn;
        std::vector<std::pair<std::string, const expression *>> assgns;

        if (!match(symbol::ID))
            error("expected identifier..");
        fn = static_cast<id_token *>(tks[pos - 2])->id;

        if (!match(symbol::EQ))
            error("expected '='..");

        if (!match(symbol::NEW))
            error("expected 'new'..");

        do
        {
            if (!match(symbol::ID))
                error("expected identifier..");
            scp.push_back(static_cast<id_token *>(tks[pos - 2])->id);
        } while (match(symbol::DOT));

        pn = scp.back();
        scp.pop_back();

        if (!match(symbol::LPAREN))
            error("expected '('..");

        if (!match(symbol::RPAREN))
        {
            do
            {
                if (!match(symbol::ID))
                    error("expected identifier..");
                std::string assgn_name = static_cast<id_token *>(tks[pos - 2])->id;

                if (!match(symbol::COLON))
                    error("expected ':'..");

                expression *xpr = _expression();
                assgns.push_back({assgn_name, xpr});
            } while (match(symbol::COMMA));

            if (!match(symbol::RPAREN))
                error("expected ')'..");
        }

        if (!match(symbol::SEMICOLON))
            error("expected ';'..");
        return new formula_statement(isf, fn, scp, pn, assgns);
    }
    case symbol::RETURN:
    {
        expression *xpr = _expression();
        if (!match(symbol::SEMICOLON))
            error("expected ';'..");
        return new return_statement(xpr);
    }
    default:
    {
        expression *xpr = _expression();
        if (!match(symbol::SEMICOLON))
            error("expected ';'..");
        return new expression_statement(xpr);
    }
    }
}

expression *parser::_expression(const size_t &pr)
{
    expression *e = nullptr;
    switch (tk->sym)
    {
    case symbol::TRUE:
    case symbol::FALSE:
        tk = next();
        e = new bool_literal_expression(tks[pos - 2]->sym == symbol::TRUE);
        break;
    case symbol::IntLiteral:
        tk = next();
        e = new int_literal_expression(static_cast<int_token *>(tks[pos - 2])->val);
        break;
    case symbol::RealLiteral:
        tk = next();
        e = new real_literal_expression(static_cast<real_token *>(tks[pos - 2])->val);
        break;
    case symbol::StringLiteral:
        tk = next();
        e = new string_literal_expression(static_cast<string_token *>(tks[pos - 2])->str);
        break;
    case symbol::LPAREN: // either a parenthesys expression or a cast..
    {
        tk = next();

        size_t c_pos = pos;
        do
        {
            if (!match(symbol::ID))
                error("expected identifier..");
        } while (match(symbol::DOT));

        if (match(symbol::RPAREN)) // a cast..
        {
            backtrack(c_pos);
            std::vector<std::string> ids;
            do
            {
                if (!match(symbol::ID))
                    error("expected identifier..");
                ids.push_back(static_cast<id_token *>(tks[pos - 2])->id);
            } while (match(symbol::DOT));

            if (!match(symbol::RPAREN))
                error("expected ')'..");
            expression *xpr = _expression();
            e = new cast_expression(ids, xpr);
        }
        else // a parenthesis..
        {
            backtrack(c_pos);
            expression *xpr = _expression();
            if (!match(symbol::RPAREN))
                error("expected ')'..");
            e = xpr;
        }
        break;
    }
    case symbol::PLUS:
        tk = next();
        e = new plus_expression(e);
        break;
    case symbol::MINUS:
        tk = next();
        e = new minus_expression(e);
        break;
    case symbol::BANG:
        tk = next();
        e = new not_expression(e);
        break;
    case symbol::LBRACKET:
    {
        tk = next();
        expression *min_e = _expression();
        expression *max_e = _expression();

        if (!match(symbol::RBRACKET))
            error("expected ']'..");

        e = new range_expression(min_e, max_e);
        break;
    }
    case symbol::NEW:
    {
        tk = next();
        std::vector<std::string> ids;
        do
        {
            if (!match(symbol::ID))
                error("expected identifier..");
            ids.push_back(static_cast<id_token *>(tks[pos - 2])->id);
        } while (match(symbol::DOT));

        std::vector<expression *> xprs;
        if (!match(symbol::LPAREN))
            error("expected '('..");

        if (!match(symbol::RPAREN))
        {
            do
            {
                xprs.push_back(_expression());
            } while (match(symbol::COMMA));

            if (!match(symbol::RPAREN))
                error("expected ')'..");
        }

        e = new constructor_expression(ids, xprs);
        break;
    }
    case symbol::ID:
    {
        std::vector<std::string> is;
        is.push_back(static_cast<id_token *>(tk)->id);
        tk = next();
        while (match(symbol::DOT))
        {
            if (!match(symbol::ID))
                error("expected identifier..");
            is.push_back(static_cast<id_token *>(tks[pos - 2])->id);
        }
        if (match(symbol::LPAREN))
        {
            tk = next();
            std::string fn = is.back();
            is.pop_back();
            std::vector<expression *> xprs;
            if (!match(symbol::LPAREN))
                error("expected '('..");

            if (!match(symbol::RPAREN))
            {
                do
                {
                    xprs.push_back(_expression());
                } while (match(symbol::COMMA));

                if (!match(symbol::RPAREN))
                    error("expected ')'..");
            }

            e = new function_expression(is, fn, xprs);
        }
        else
        {
            e = new id_expression(is);
        }
        break;
    }
    default:
        error("expected either '(' or '+' or '-' or '!' or '[' or 'new' or a literal or an identifier..");
    }

    std::unordered_set<symbol> la_set({symbol::PLUS, symbol::MINUS, symbol::STAR, symbol::SLASH, symbol::LT, symbol::LTEQ, symbol::EQEQ, symbol::GTEQ, symbol::GT, symbol::BANGEQ, symbol::IMPLICATION, symbol::BAR, symbol::AMP, symbol::CARET});
    while (la_set.find(tk->sym) != la_set.end())
    {
        if (0 >= pr)
        {
            switch (tk->sym)
            {
            case symbol::EQEQ:
                tk = next();
                return new eq_expression(e, _expression(1));
            case symbol::BANGEQ:
                tk = next();
                return new neq_expression(e, _expression(1));
            }
        }
        if (1 >= pr)
        {
            switch (tk->sym)
            {
            case symbol::LT:
            {
                tk = next();
                expression *l = e;
                expression *r = _expression(2);

                return new lt_expression(l, r);
            }
            case symbol::LTEQ:
            {
                tk = next();
                expression *l = e;
                expression *r = _expression(2);

                return new leq_expression(l, r);
            }
            case symbol::GTEQ:
            {
                tk = next();
                expression *l = e;
                expression *r = _expression(2);

                return new geq_expression(l, r);
            }
            case symbol::GT:
            {
                tk = next();
                expression *l = e;
                expression *r = _expression(2);

                return new gt_expression(l, r);
            }
            case symbol::IMPLICATION:
            {
                tk = next();
                expression *l = e;
                expression *r = _expression(2);

                return new implication_expression(l, r);
            }
            case symbol::BAR:
            {
                std::vector<expression *> xprs;
                xprs.push_back(e);

                while (match(symbol::BAR))
                    xprs.push_back(_expression(2));

                return new disjunction_expression(xprs);
            }
            case symbol::AMP:
            {
                std::vector<expression *> xprs;
                xprs.push_back(e);

                while (match(symbol::BAR))
                    xprs.push_back(_expression(2));

                return new conjunction_expression(xprs);
            }
            case symbol::CARET:
            {
                std::vector<expression *> xprs;
                xprs.push_back(e);

                while (match(symbol::BAR))
                    xprs.push_back(_expression(2));

                return new exct_one_expression(xprs);
            }
            }
        }
        if (2 >= pr)
        {
            switch (tk->sym)
            {
            case symbol::PLUS:
            {
                std::vector<expression *> xprs;
                xprs.push_back(e);

                while (match(symbol::PLUS))
                    xprs.push_back(_expression(3));

                return new addition_expression(xprs);
            }
            case symbol::MINUS:
            {
                std::vector<expression *> xprs;
                xprs.push_back(e);

                while (match(symbol::MINUS))
                    xprs.push_back(_expression(3));

                return new subtraction_expression(xprs);
            }
            }
        }
        if (3 >= pr)
        {
            switch (tk->sym)
            {
            case symbol::STAR:
            {
                std::vector<expression *> xprs;
                xprs.push_back(e);

                while (match(symbol::STAR))
                    xprs.push_back(_expression(4));

                return new multiplication_expression(xprs);
            }
            case symbol::SLASH:
            {
                std::vector<expression *> xprs;
                xprs.push_back(e);

                while (match(symbol::SLASH))
                    xprs.push_back(_expression(4));

                return new division_expression(xprs);
            }
            }
        }
    }

    return e;
}

void parser::error(const std::string &err) { throw std::invalid_argument("[" + std::to_string(tk->start_line) + ", " + std::to_string(tk->start_pos) + "] " + err); }
}