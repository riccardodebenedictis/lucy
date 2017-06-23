#include "parser.h"
#include <cassert>
#include <iostream>
#include <string>

namespace lucy
{

using namespace ast;

parser::parser() {}

parser::~parser()
{
    for (const auto &cu : cus)
    {
        delete cu;
    }
}

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
        case symbol::ID:
        {
            size_t c_pos = pos;
            tk = next();
            while (match(symbol::DOT))
            {
                if (!match(symbol::ID))
                {
                    error("expected identifier..");
                    return nullptr;
                }
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
            return nullptr;
        }
    }

    // cleanings..
    delete lex;

    compilation_unit *cu = new compilation_unit(ts, ms, ps, ss);
    cus.push_back(cu);
    return cu;
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
    expr *xpr;

    if (!match(symbol::TYPEDEF))
    {
        error("expected 'typedef'..");
        return nullptr;
    }

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
        return nullptr;
    }
    tk = next();

    xpr = _expr();

    if (!match(symbol::ID))
    {
        error("expected identifier..");
        return nullptr;
    }
    n = dynamic_cast<id_token *>(tks[pos - 2])->id;

    if (!match(symbol::SEMICOLON))
    {
        error("expected ';'..");
        return nullptr;
    }

    return new typedef_declaration(n, pt, xpr);
}

enum_declaration *parser::_enum_declaration()
{
    std::string n;
    std::vector<std::string> es;
    std::vector<type_ref *> trs;

    if (!match(symbol::ENUM))
    {
        error("expected 'enum'..");
        return nullptr;
    }

    if (!match(symbol::ID))
    {
        error("expected identifier..");
        return nullptr;
    }
    n = dynamic_cast<id_token *>(tks[pos - 2])->id;

    switch (tk->sym)
    {
    case symbol::LBRACE:
        tk = next();
        if (!match(symbol::StringLiteral))
        {
            error("expected string literal..");
            return nullptr;
        }
        es.push_back(dynamic_cast<string_token *>(tks[pos - 2])->str);

        while (match(symbol::COMMA))
        {
            if (!match(symbol::StringLiteral))
            {
                error("expected string literal..");
                return nullptr;
            }
            es.push_back(dynamic_cast<string_token *>(tks[pos - 2])->str);
        }

        if (!match(symbol::RBRACE))
        {
            error("expected '}'..");
            return nullptr;
        }
        break;
    case symbol::ID:
        trs.push_back(_type_ref());
        break;
    default:
        error("expected either '{' or identifier..");
        return nullptr;
    }

    while (match(symbol::BAR))
    {
        switch (tk->sym)
        {
        case symbol::LBRACE:
            tk = next();
            if (!match(symbol::StringLiteral))
            {
                error("expected string literal..");
                return nullptr;
            }
            es.push_back(dynamic_cast<string_token *>(tks[pos - 2])->str);

            while (match(symbol::COMMA))
            {
                if (!match(symbol::StringLiteral))
                {
                    error("expected string literal..");
                    return nullptr;
                }
                es.push_back(dynamic_cast<string_token *>(tks[pos - 2])->str);
            }

            if (!match(symbol::RBRACE))
            {
                error("expected '}'..");
                return nullptr;
            }
            break;
        case symbol::ID:
            trs.push_back(_type_ref());
            break;
        default:
            error("expected either '{' or identifier..");
            return nullptr;
        }
    }

    if (!match(symbol::SEMICOLON))
    {
        error("expected ';'..");
        return nullptr;
    }

    return new enum_declaration(n, es, trs);
}

class_declaration *parser::_class_declaration()
{
    std::string n;
    std::vector<type_ref *> bcs;
    std::vector<field_declaration *> fs;
    std::vector<constructor_declaration *> cs;
    std::vector<method_declaration *> ms;
    std::vector<predicate_declaration *> ps;
    std::vector<type_declaration *> ts;

    if (!match(symbol::CLASS))
    {
        error("expected 'class'..");
        return nullptr;
    }

    if (!match(symbol::ID))
    {
        error("expected identifier..");
        return nullptr;
    }
    n = dynamic_cast<id_token *>(tks[pos - 2])->id;

    if (match(symbol::COLON))
    {
        bcs.push_back(_type_ref());
        while (match(symbol::COMMA))
        {
            bcs.push_back(_type_ref());
        }
    }

    if (!match(symbol::LBRACE))
    {
        error("expected '{'..");
        return nullptr;
    }

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
    case symbol::ID:
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
                {
                    error("expected identifier..");
                    return nullptr;
                }
            }
            if (!match(symbol::ID))
            {
                error("expected identifier..");
                return nullptr;
            }
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
                return nullptr;
            }
        default:
            error("expected either '(' or '.'..");
            return nullptr;
        }
    }
    default:
        error("expected either 'typedef' or 'enum' or 'class' or 'predicate' or 'void' or identifier..");
        return nullptr;
    }

    if (!match(symbol::RBRACE))
    {
        error("expected '}'..");
        return nullptr;
    }

    return new class_declaration(n, bcs, fs, cs, ms, ps, ts);
}

field_declaration *parser::_field_declaration()
{
    type_ref *tp = _type_ref();
    std::string n;
    std::vector<variable_declaration *> ds;

    if (!match(symbol::ID))
    {
        error("expected identifier..");
        return nullptr;
    }
    n = dynamic_cast<id_token *>(tks[pos - 2])->id;

    if (match(symbol::EQ))
    {
        ds.push_back(new variable_declaration(n, _expr()));
    }
    else
    {
        ds.push_back(new variable_declaration(n));
    }

    while (match(symbol::COMMA))
    {
        if (!match(symbol::ID))
        {
            error("expected identifier..");
            return nullptr;
        }
        n = dynamic_cast<id_token *>(tks[pos - 2])->id;

        if (match(symbol::EQ))
        {
            ds.push_back(new variable_declaration(n, _expr()));
        }
        else
        {
            ds.push_back(new variable_declaration(n));
        }
    }

    if (!match(symbol::SEMICOLON))
    {
        error("expected ';'..");
        return nullptr;
    }

    return new field_declaration(tp, ds);
}

method_declaration *parser::_method_declaration()
{
    type_ref *rt;
    std::string n;
    std::vector<std::pair<type_ref *, std::string>> pars;
    std::vector<statement *> stmnts;

    if (match(symbol::VOID))
    {
        rt = _type_ref();
    }
    else
    {
        rt = nullptr;
    }

    if (!match(symbol::ID))
    {
        error("expected identifier..");
        return nullptr;
    }
    n = dynamic_cast<id_token *>(tks[pos - 2])->id;

    if (!match(symbol::LPAREN))
    {
        error("expected '('..");
        return nullptr;
    }

    while (match(symbol::ID))
    {
        type_ref *t = _type_ref();
        if (!match(symbol::ID))
        {
            error("expected identifier..");
            return nullptr;
        }
        std::string pn = dynamic_cast<id_token *>(tks[pos - 2])->id;
        pars.push_back({t, pn});
    }

    if (!match(symbol::RPAREN))
    {
        error("expected ')'..");
        return nullptr;
    }

    if (!match(symbol::LBRACE))
    {
        error("expected '{'..");
        return nullptr;
    }

    while (!match(symbol::RBRACE))
    {
        stmnts.push_back(_statement());
    }

    return new method_declaration(rt, n, pars, stmnts);
}

constructor_declaration *parser::_constructor_declaration()
{
    std::vector<std::pair<type_ref *, std::string>> pars;
    std::vector<std::pair<std::string, std::vector<expr *>>> il;
    std::vector<statement *> stmnts;

    if (!match(symbol::ID))
    {
        error("expected identifier..");
        return nullptr;
    }

    if (!match(symbol::LPAREN))
    {
        error("expected '('..");
        return nullptr;
    }

    while (match(symbol::ID))
    {
        type_ref *t = _type_ref();
        if (!match(symbol::ID))
        {
            error("expected identifier..");
            return nullptr;
        }
        std::string pn = dynamic_cast<id_token *>(tks[pos - 2])->id;
        pars.push_back({t, pn});
    }

    if (!match(symbol::RPAREN))
    {
        error("expected ')'..");
        return nullptr;
    }

    if (match(symbol::COLON))
    {
        std::string pn;
        std::vector<expr *> xprs;
        if (!match(symbol::ID))
        {
            error("expected identifier..");
            return nullptr;
        }
        pn = dynamic_cast<id_token *>(tks[pos - 2])->id;

        if (!match(symbol::LPAREN))
        {
            error("expected '('..");
            return nullptr;
        }

        while (!match(symbol::RPAREN))
        {
            xprs.push_back(_expr());
        }
        il.push_back({pn, xprs});
    }

    if (!match(symbol::LBRACE))
    {
        error("expected '{'..");
        return nullptr;
    }

    while (!match(symbol::RBRACE))
    {
        stmnts.push_back(_statement());
    }

    return new constructor_declaration(pars, il, stmnts);
}

predicate_declaration *parser::_predicate_declaration()
{
    std::string n;
    std::vector<std::pair<type_ref *, std::string>> pars;
    std::vector<type_ref *> pl;
    std::vector<statement *> stmnts;

    if (!match(symbol::PREDICATE))
    {
        error("expected 'predicate'..");
        return nullptr;
    }

    if (!match(symbol::ID))
    {
        error("expected identifier..");
        return nullptr;
    }
    n = dynamic_cast<id_token *>(tks[pos - 2])->id;

    if (!match(symbol::LPAREN))
    {
        error("expected '('..");
        return nullptr;
    }

    while (match(symbol::ID))
    {
        type_ref *t = _type_ref();
        if (!match(symbol::ID))
        {
            error("expected identifier..");
            return nullptr;
        }
        std::string pn = dynamic_cast<id_token *>(tks[pos - 2])->id;
        pars.push_back({t, pn});
    }

    if (!match(symbol::RPAREN))
    {
        error("expected ')'..");
        return nullptr;
    }

    if (match(symbol::COLON))
    {
        pl.push_back(_type_ref());
        while (match(symbol::COMMA))
        {
            pl.push_back(_type_ref());
        }
    }

    if (!match(symbol::LBRACE))
    {
        error("expected '{'..");
        return nullptr;
    }

    while (!match(symbol::RBRACE))
    {
        stmnts.push_back(_statement());
    }

    return new predicate_declaration(n, pars, pl, stmnts);
}

statement *parser::_statement()
{
    switch (tk->sym)
    {
    case symbol::ID: // either an assignment or a local field..
    {
        std::vector<std::string> ids;
        ids.push_back(dynamic_cast<id_token *>(tk)->id);
        tk = next();
        while (match(symbol::DOT))
        {
            if (!match(symbol::ID))
            {
                error("expected identifier..");
                return nullptr;
            }
            ids.push_back(dynamic_cast<id_token *>(tks[pos - 2])->id);
        }

        switch (tk->sym)
        {
        case symbol::ID: // a local field..
        {
            std::string n = dynamic_cast<id_token *>(tk)->id;
            tk = next();
            if (tk->sym == symbol::EQ)
            {
                return new local_field_statement(new type_ref(ids), n, _expr());
            }
            else
            {
                return new local_field_statement(new type_ref(ids), n);
            }
        }
        case symbol::EQ: // an assignment..
        {
            tk = next();
            expr *xpr = _expr();
            if (!match(symbol::SEMICOLON))
            {
                error("expected ';'..");
                return nullptr;
            }
            return new assignment_statement(ids, xpr);
        }
        }
        break;
    }
    case symbol::LBRACE: // either a block or a disjunction..
    {
        tk = next();
        std::vector<statement *> stmnts;
        while (!match(symbol::RBRACE))
        {
            stmnts.push_back(_statement());
        }
        if (tk->sym == symbol::OR)
        {
            std::vector<block_statement *> disjs;
            disjs.push_back(new block_statement(stmnts));
            while (match(symbol::OR))
            {
                stmnts.clear();
                while (!match(symbol::RBRACE))
                {
                    stmnts.push_back(_statement());
                }
                disjs.push_back(new block_statement(stmnts));
            }
            if (!match(symbol::SEMICOLON))
            {
                error("expected ';'..");
                return nullptr;
            }
            return new disjunction_statement(disjs);
        }
        else
        {
            if (!match(symbol::SEMICOLON))
            {
                error("expected ';'..");
                return nullptr;
            }
            return new block_statement(stmnts);
        }
    }
        return nullptr;
    case symbol::FACT:
    case symbol::GOAL:
    {
        tk = next();
        bool isf = tk->sym == symbol::FACT;
        std::string fn;
        std::vector<std::string> scp;
        std::string pn;
        std::vector<std::pair<std::string, expr *>> assgns;

        if (!match(symbol::ID))
        {
            error("expected identifier..");
            return nullptr;
        }
        fn = dynamic_cast<id_token *>(tks[pos - 2])->id;

        if (!match(symbol::EQ))
        {
            error("expected '='..");
            return nullptr;
        }

        if (!match(symbol::ID))
        {
            error("expected identifier..");
            return nullptr;
        }
        scp.push_back(dynamic_cast<id_token *>(tks[pos - 2])->id);

        while (match(symbol::DOT))
        {
            if (!match(symbol::ID))
            {
                error("expected identifier..");
                return nullptr;
            }
            scp.push_back(dynamic_cast<id_token *>(tks[pos - 2])->id);
        }
        pn = scp.back();
        scp.pop_back();

        if (!match(symbol::LPAREN))
        {
            error("expected '('..");
            return nullptr;
        }

        while (match(symbol::ID))
        {
            if (!match(symbol::ID))
            {
                error("expected identifier..");
                return nullptr;
            }
            assgns.push_back({dynamic_cast<id_token *>(tks[pos - 2])->id, _expr()});
        }

        if (!match(symbol::RPAREN))
        {
            error("expected ')'..");
            return nullptr;
        }

        if (!match(symbol::SEMICOLON))
        {
            error("expected ';'..");
            return nullptr;
        }
        return new formula_statement(isf, fn, scp, pn, assgns);
    }
    case symbol::RETURN:
    {
        expr *xpr = _expr();
        if (!match(symbol::SEMICOLON))
        {
            error("expected ';'..");
            return nullptr;
        }
        return new return_statement(xpr);
    }
    default:
        error("expected either 'fact' or 'goal' or '{' or 'return' or identifier..");
        return nullptr;
    }
}

expr *parser::_expr(const size_t &pr)
{
    return nullptr;
}

ast::type_ref *parser::_type_ref()
{
    std::vector<std::string> ids;
    ids.push_back(dynamic_cast<id_token *>(tk)->id);
    tk = next();
    while (match(symbol::DOT))
    {
        if (!match(symbol::ID))
        {
            error("expected identifier..");
            return nullptr;
        }
        ids.push_back(dynamic_cast<id_token *>(tks[pos - 2])->id);
    }
    return new type_ref(ids);
}

void parser::error(const std::string &err) { std::cerr << "[" << std::to_string(tk->start_line) << ", " << std::to_string(tk->start_pos) << "] " << err << std::endl; }
}