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

parser::parser(core &cr) : cr(cr) {}
parser::~parser() {}

void parser::parse(std::istream &is)
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
        }
    }

    for (const auto &s : ss)
    {
    }

    // cleanings..
    delete lex;
    for (const auto &t : ts)
        delete t;
    for (const auto &m : ms)
        delete m;
    for (const auto &p : ps)
        delete p;
    for (const auto &s : ss)
        delete s;
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
    {
        error("expected 'typedef'..");
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
    }
    tk = next();

    xpr = _expression();

    if (!match(symbol::ID))
    {
        error("expected identifier..");
    }
    n = dynamic_cast<id_token *>(tks[pos - 2])->id;

    if (!match(symbol::SEMICOLON))
    {
        error("expected ';'..");
    }

    return new typedef_declaration(n, pt, xpr);
}

enum_declaration *parser::_enum_declaration()
{
    std::string n;
    std::vector<std::string> es;
    std::vector<std::vector<std::string>> trs;

    if (!match(symbol::ENUM))
    {
        error("expected 'enum'..");
    }

    if (!match(symbol::ID))
    {
        error("expected identifier..");
    }
    n = dynamic_cast<id_token *>(tks[pos - 2])->id;

    switch (tk->sym)
    {
    case symbol::LBRACE:
        tk = next();
        if (!match(symbol::StringLiteral))
        {
            error("expected string literal..");
        }
        es.push_back(dynamic_cast<string_token *>(tks[pos - 2])->str);

        while (match(symbol::COMMA))
        {
            if (!match(symbol::StringLiteral))
            {
                error("expected string literal..");
            }
            es.push_back(dynamic_cast<string_token *>(tks[pos - 2])->str);
        }

        if (!match(symbol::RBRACE))
        {
            error("expected '}'..");
        }
        break;
    case symbol::ID:
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
        trs.push_back(ids);
        break;
    }
    default:
        error("expected either '{' or identifier..");
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
            }
            es.push_back(dynamic_cast<string_token *>(tks[pos - 2])->str);

            while (match(symbol::COMMA))
            {
                if (!match(symbol::StringLiteral))
                {
                    error("expected string literal..");
                }
                es.push_back(dynamic_cast<string_token *>(tks[pos - 2])->str);
            }

            if (!match(symbol::RBRACE))
            {
                error("expected '}'..");
            }
            break;
        case symbol::ID:
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
            trs.push_back(ids);
            break;
        }
        default:
            error("expected either '{' or identifier..");
        }
    }

    if (!match(symbol::SEMICOLON))
    {
        error("expected ';'..");
    }

    return new enum_declaration(n, es, trs);
}

class_declaration *parser::_class_declaration()
{
    std::string n;
    std::vector<std::vector<std::string>> bcs;
    std::vector<field_declaration *> fs;
    std::vector<constructor_declaration *> cs;
    std::vector<method_declaration *> ms;
    std::vector<predicate_declaration *> ps;
    std::vector<type_declaration *> ts;

    if (!match(symbol::CLASS))
    {
        error("expected 'class'..");
    }

    if (!match(symbol::ID))
    {
        error("expected identifier..");
    }
    n = dynamic_cast<id_token *>(tks[pos - 2])->id;

    if (match(symbol::COLON))
    {
        std::vector<std::string> ids;
        if (!match(symbol::ID))
        {
            error("expected identifier..");
        }
        ids.push_back(dynamic_cast<id_token *>(tks[pos - 2])->id);
        tk = next();
        while (match(symbol::DOT))
        {
            if (!match(symbol::ID))
            {
                error("expected identifier..");
            }
            ids.push_back(dynamic_cast<id_token *>(tks[pos - 2])->id);
        }
        bcs.push_back(ids);
        while (match(symbol::COMMA))
        {
            ids.clear();
            if (!match(symbol::ID))
            {
                error("expected identifier..");
            }
            ids.push_back(dynamic_cast<id_token *>(tks[pos - 2])->id);
            tk = next();
            while (match(symbol::DOT))
            {
                if (!match(symbol::ID))
                {
                    error("expected identifier..");
                }
                ids.push_back(dynamic_cast<id_token *>(tks[pos - 2])->id);
            }
            bcs.push_back(ids);
        }
    }

    if (!match(symbol::LBRACE))
    {
        error("expected '{'..");
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
                }
            }
            if (!match(symbol::ID))
            {
                error("expected identifier..");
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
            }
        default:
            error("expected either '(' or '.'..");
        }
    }
    default:
        error("expected either 'typedef' or 'enum' or 'class' or 'predicate' or 'void' or identifier..");
    }

    if (!match(symbol::RBRACE))
    {
        error("expected '}'..");
    }

    return new class_declaration(n, bcs, fs, cs, ms, ps, ts);
}

field_declaration *parser::_field_declaration()
{
    std::vector<std::string> ids;
    std::string n;
    std::vector<variable_declaration *> ds;

    if (!match(symbol::ID))
    {
        error("expected identifier..");
    }
    ids.push_back(dynamic_cast<id_token *>(tks[pos - 2])->id);
    tk = next();
    while (match(symbol::DOT))
    {
        if (!match(symbol::ID))
        {
            error("expected identifier..");
        }
        ids.push_back(dynamic_cast<id_token *>(tks[pos - 2])->id);
    }

    if (!match(symbol::ID))
    {
        error("expected identifier..");
    }
    n = dynamic_cast<id_token *>(tks[pos - 2])->id;

    if (match(symbol::EQ))
    {
        ds.push_back(new variable_declaration(n, _expression()));
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
        }
        n = dynamic_cast<id_token *>(tks[pos - 2])->id;

        if (match(symbol::EQ))
        {
            ds.push_back(new variable_declaration(n, _expression()));
        }
        else
        {
            ds.push_back(new variable_declaration(n));
        }
    }

    if (!match(symbol::SEMICOLON))
    {
        error("expected ';'..");
    }

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
        if (!match(symbol::ID))
        {
            error("expected identifier..");
        }
        ids.push_back(dynamic_cast<id_token *>(tks[pos - 2])->id);
        tk = next();
        while (match(symbol::DOT))
        {
            if (!match(symbol::ID))
            {
                error("expected identifier..");
            }
            ids.push_back(dynamic_cast<id_token *>(tks[pos - 2])->id);
        }
    }

    if (!match(symbol::ID))
    {
        error("expected identifier..");
    }
    n = dynamic_cast<id_token *>(tks[pos - 2])->id;

    if (!match(symbol::LPAREN))
    {
        error("expected '('..");
    }

    while (match(symbol::ID))
    {
        std::vector<std::string> p_ids;
        if (!match(symbol::ID))
        {
            error("expected identifier..");
        }
        p_ids.push_back(dynamic_cast<id_token *>(tks[pos - 2])->id);
        tk = next();
        while (match(symbol::DOT))
        {
            if (!match(symbol::ID))
            {
                error("expected identifier..");
            }
            p_ids.push_back(dynamic_cast<id_token *>(tks[pos - 2])->id);
        }
        if (!match(symbol::ID))
        {
            error("expected identifier..");
        }
        std::string pn = dynamic_cast<id_token *>(tks[pos - 2])->id;
        pars.push_back({p_ids, pn});
    }

    if (!match(symbol::RPAREN))
    {
        error("expected ')'..");
    }

    if (!match(symbol::LBRACE))
    {
        error("expected '{'..");
    }

    while (!match(symbol::RBRACE))
    {
        stmnts.push_back(_statement());
    }

    return new method_declaration(ids, n, pars, stmnts);
}

constructor_declaration *parser::_constructor_declaration()
{
    std::vector<std::pair<std::vector<std::string>, std::string>> pars;
    std::vector<std::pair<std::string, std::vector<expression *>>> il;
    std::vector<statement *> stmnts;

    if (!match(symbol::ID))
    {
        error("expected identifier..");
    }

    if (!match(symbol::LPAREN))
    {
        error("expected '('..");
    }

    while (match(symbol::ID))
    {
        std::vector<std::string> p_ids;
        if (!match(symbol::ID))
        {
            error("expected identifier..");
        }
        p_ids.push_back(dynamic_cast<id_token *>(tks[pos - 2])->id);
        tk = next();
        while (match(symbol::DOT))
        {
            if (!match(symbol::ID))
            {
                error("expected identifier..");
            }
            p_ids.push_back(dynamic_cast<id_token *>(tks[pos - 2])->id);
        }
        if (!match(symbol::ID))
        {
            error("expected identifier..");
        }
        std::string pn = dynamic_cast<id_token *>(tks[pos - 2])->id;
        pars.push_back({p_ids, pn});
    }

    if (!match(symbol::RPAREN))
    {
        error("expected ')'..");
    }

    if (match(symbol::COLON))
    {
        std::string pn;
        std::vector<expression *> xprs;
        if (!match(symbol::ID))
        {
            error("expected identifier..");
        }
        pn = dynamic_cast<id_token *>(tks[pos - 2])->id;

        if (!match(symbol::LPAREN))
        {
            error("expected '('..");
        }

        if (!match(symbol::RPAREN))
        {
            xprs.push_back(_expression());
            while (!match(symbol::RPAREN))
            {
                if (!match(symbol::COMMA))
                {
                    error("expected ','..");
                }
                xprs.push_back(_expression());
            }
        }
        il.push_back({pn, xprs});
    }

    if (!match(symbol::LBRACE))
    {
        error("expected '{'..");
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
    std::vector<std::pair<std::vector<std::string>, std::string>> pars;
    std::vector<std::vector<std::string>> pl;
    std::vector<statement *> stmnts;

    if (!match(symbol::PREDICATE))
    {
        error("expected 'predicate'..");
    }

    if (!match(symbol::ID))
    {
        error("expected identifier..");
    }
    n = dynamic_cast<id_token *>(tks[pos - 2])->id;

    if (!match(symbol::LPAREN))
    {
        error("expected '('..");
    }

    while (match(symbol::ID))
    {
        std::vector<std::string> p_ids;
        if (!match(symbol::ID))
        {
            error("expected identifier..");
        }
        p_ids.push_back(dynamic_cast<id_token *>(tks[pos - 2])->id);
        tk = next();
        while (match(symbol::DOT))
        {
            if (!match(symbol::ID))
            {
                error("expected identifier..");
            }
            p_ids.push_back(dynamic_cast<id_token *>(tks[pos - 2])->id);
        }
        if (!match(symbol::ID))
        {
            error("expected identifier..");
        }
        std::string pn = dynamic_cast<id_token *>(tks[pos - 2])->id;
        pars.push_back({p_ids, pn});
    }

    if (!match(symbol::RPAREN))
    {
        error("expected ')'..");
    }

    if (match(symbol::COLON))
    {
        std::vector<std::string> p_ids;
        if (!match(symbol::ID))
        {
            error("expected identifier..");
        }
        p_ids.push_back(dynamic_cast<id_token *>(tks[pos - 2])->id);
        tk = next();
        while (match(symbol::DOT))
        {
            if (!match(symbol::ID))
            {
                error("expected identifier..");
            }
            p_ids.push_back(dynamic_cast<id_token *>(tks[pos - 2])->id);
        }
        pl.push_back(p_ids);
        while (match(symbol::COMMA))
        {
            p_ids.clear();
            if (!match(symbol::ID))
            {
                error("expected identifier..");
            }
            p_ids.push_back(dynamic_cast<id_token *>(tks[pos - 2])->id);
            tk = next();
            while (match(symbol::DOT))
            {
                if (!match(symbol::ID))
                {
                    error("expected identifier..");
                }
                p_ids.push_back(dynamic_cast<id_token *>(tks[pos - 2])->id);
            }
            pl.push_back(p_ids);
        }
    }

    if (!match(symbol::LBRACE))
    {
        error("expected '{'..");
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
            }
            ids.push_back(dynamic_cast<id_token *>(tks[pos - 2])->id);
        }

        switch (tk->sym)
        {
        case symbol::ID: // a local field..
        {
            std::string n = dynamic_cast<id_token *>(tk)->id;
            expression *e = nullptr;
            tk = next();
            if (tk->sym == symbol::EQ)
            {
                tk = next();
                e = _expression();
            }
            if (!match(symbol::SEMICOLON))
            {
                error("expected ';'..");
            }
            return new local_field_statement(cr, ids, n, _expression());
        }
        case symbol::EQ: // an assignment..
        {
            std::string id = ids.back();
            ids.pop_back();
            tk = next();
            expression *xpr = _expression();
            if (!match(symbol::SEMICOLON))
            {
                error("expected ';'..");
            }
            return new assignment_statement(cr, ids, id, xpr);
        }
        default:
            error("expected either '=' or an identifier..");
        }
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
            disjs.push_back(new block_statement(cr, stmnts));
            while (match(symbol::OR))
            {
                stmnts.clear();
                while (!match(symbol::RBRACE))
                {
                    stmnts.push_back(_statement());
                }
                disjs.push_back(new block_statement(cr, stmnts));
            }
            if (!match(symbol::SEMICOLON))
            {
                error("expected ';'..");
            }
            return new disjunction_statement(cr, disjs);
        }
        else
        {
            if (!match(symbol::SEMICOLON))
            {
                error("expected ';'..");
            }
            return new block_statement(cr, stmnts);
        }
    }
    case symbol::FACT:
    case symbol::GOAL:
    {
        tk = next();
        bool isf = tk->sym == symbol::FACT;
        std::string fn;
        std::vector<std::string> scp;
        std::string pn;
        std::vector<std::pair<std::string, expression *>> assgns;

        if (!match(symbol::ID))
        {
            error("expected identifier..");
        }
        fn = dynamic_cast<id_token *>(tks[pos - 2])->id;

        if (!match(symbol::EQ))
        {
            error("expected '='..");
        }

        if (!match(symbol::ID))
        {
            error("expected identifier..");
        }
        scp.push_back(dynamic_cast<id_token *>(tks[pos - 2])->id);

        while (match(symbol::DOT))
        {
            if (!match(symbol::ID))
            {
                error("expected identifier..");
            }
            scp.push_back(dynamic_cast<id_token *>(tks[pos - 2])->id);
        }
        pn = scp.back();
        scp.pop_back();

        if (!match(symbol::LPAREN))
        {
            error("expected '('..");
        }

        while (match(symbol::ID))
        {
            if (!match(symbol::ID))
            {
                error("expected identifier..");
            }
            assgns.push_back({dynamic_cast<id_token *>(tks[pos - 2])->id, _expression()});
        }

        if (!match(symbol::RPAREN))
        {
            error("expected ')'..");
        }

        if (!match(symbol::SEMICOLON))
        {
            error("expected ';'..");
        }
        return new formula_statement(cr, isf, fn, scp, pn, assgns);
    }
    case symbol::RETURN:
    {
        expression *xpr = _expression();
        if (!match(symbol::SEMICOLON))
        {
            error("expected ';'..");
        }
        return new return_statement(cr, xpr);
    }
    default:
        return new expression_statement(cr, dynamic_cast<bool_expression *>(_expression()));
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
        e = new bool_literal_expression(cr, tks[pos - 2]->sym == symbol::TRUE);
    case symbol::NumericLiteral:
        tk = next();
        e = new arith_literal_expression(cr, dynamic_cast<numeric_token *>(tks[pos - 2])->val);
    case symbol::StringLiteral:
        tk = next();
        e = new string_literal_expression(cr, dynamic_cast<string_token *>(tks[pos - 2])->str);
    case symbol::LPAREN: // either a parenthesys expression or a cast..
    {
        tk = next();
        switch (tk->sym)
        {
        case symbol::ID:
        {
            size_t c_pos = pos;
            tk = next();
            while (match(symbol::DOT))
            {
                if (!match(symbol::ID))
                {
                    error("expected identifier..");
                }
            }
            if (match(symbol::RPAREN)) // a cast..
            {
                backtrack(c_pos);
                std::vector<std::string> ids;
                ids.push_back(dynamic_cast<id_token *>(tk)->id);
                tk = next();
                while (match(symbol::DOT))
                {
                    if (!match(symbol::ID))
                    {
                        error("expected identifier..");
                    }
                    ids.push_back(dynamic_cast<id_token *>(tks[pos - 2])->id);
                }
                if (!match(symbol::RPAREN))
                {
                    error("expected ')'..");
                }
                expression *xpr = _expression();
                e = new cast_expression(cr, ids, xpr);
            }
            else // a parenthesis..
            {
                backtrack(c_pos);
                expression *xpr = _expression();
                if (!match(symbol::RPAREN))
                {
                    error("expected ')'..");
                }
                e = xpr;
            }
        }
        }
    }
    case symbol::PLUS:
        tk = next();
        if (arith_expression *ae = dynamic_cast<arith_expression *>(_expression()))
        {
            e = new plus_expression(cr, ae);
        }
        else
        {
            error("expected arithmetic expression..");
        }
    case symbol::MINUS:
        tk = next();
        if (arith_expression *ae = dynamic_cast<arith_expression *>(_expression()))
        {
            e = new minus_expression(cr, ae);
        }
        else
        {
            error("expected arithmetic expression..");
        }
    case symbol::BANG:
        tk = next();
        if (bool_expression *be = dynamic_cast<bool_expression *>(_expression()))
        {
            e = new not_expression(cr, be);
        }
        else
        {
            error("expected boolean expression..");
        }
    case symbol::LBRACKET:
    {
        tk = next();
        arith_expression *min_e;
        arith_expression *max_e;
        if (arith_expression *e = dynamic_cast<arith_expression *>(_expression()))
        {
            min_e = e;
        }
        else
        {
            error("expected arithmetic expression..");
        }
        if (!match(symbol::COMMA))
        {
            error("expected ','..");
        }
        if (arith_expression *e = dynamic_cast<arith_expression *>(_expression()))
        {
            max_e = e;
        }
        else
        {
            error("expected arithmetic expression..");
        }
        if (!match(symbol::RBRACKET))
        {
            error("expected ']'..");
        }
        e = new range_expression(cr, min_e, max_e);
    }
    case symbol::NEW:
    {
        tk = next();
        std::vector<std::string> ids;
        ids.push_back(dynamic_cast<id_token *>(tk)->id);
        tk = next();
        while (match(symbol::DOT))
        {
            if (!match(symbol::ID))
            {
                error("expected identifier..");
            }
            ids.push_back(dynamic_cast<id_token *>(tks[pos - 2])->id);
        }

        std::vector<expression *> xprs;
        if (!match(symbol::LPAREN))
        {
            error("expected '('..");
        }
        if (!match(symbol::RPAREN))
        {
            xprs.push_back(_expression());
            while (!match(symbol::RPAREN))
            {
                if (!match(symbol::COMMA))
                {
                    error("expected ','..");
                }
                xprs.push_back(_expression());
            }
        }
        e = new constructor_expression(cr, ids, xprs);
    }
    case symbol::ID:
    {
        std::vector<std::string> is;
        is.push_back(dynamic_cast<id_token *>(tk)->id);
        tk = next();
        while (match(symbol::DOT))
        {
            if (!match(symbol::ID))
            {
                error("expected identifier..");
            }
            is.push_back(dynamic_cast<id_token *>(tks[pos - 2])->id);
        }
        if (match(symbol::LPAREN))
        {
            tk = next();
            std::string fn = is.back();
            is.pop_back();
            std::vector<expression *> xprs;
            if (!match(symbol::RPAREN))
            {
                xprs.push_back(_expression());
                while (!match(symbol::RPAREN))
                {
                    if (!match(symbol::COMMA))
                    {
                        error("expected ','..");
                    }
                    xprs.push_back(_expression());
                }
            }
            e = new function_expression(cr, is, fn, xprs);
        }
        else
        {
            e = new id_expression(cr, is);
        }
    }
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
                return new eq_expression(cr, e, _expression(1));
            case symbol::BANGEQ:
                tk = next();
                return new neq_expression(cr, e, _expression(1));
            }
        }
        if (1 >= pr)
        {
            switch (tk->sym)
            {
            case symbol::LT:
            {
                tk = next();
                arith_expression *l = nullptr;
                arith_expression *r = nullptr;
                if (arith_expression *c_e = dynamic_cast<arith_expression *>(e))
                {
                    l = c_e;
                }
                else
                {
                    error("expected arithmetic expression..");
                }
                if (arith_expression *c_e = dynamic_cast<arith_expression *>(_expression(2)))
                {
                    r = c_e;
                }
                else
                {
                    error("expected arithmetic expression..");
                }
                return new lt_expression(cr, l, r);
            }
            case symbol::LTEQ:
            {
                tk = next();
                arith_expression *l = nullptr;
                arith_expression *r = nullptr;
                if (arith_expression *c_e = dynamic_cast<arith_expression *>(e))
                {
                    l = c_e;
                }
                else
                {
                    error("expected arithmetic expression..");
                }
                if (arith_expression *c_e = dynamic_cast<arith_expression *>(_expression(2)))
                {
                    r = c_e;
                }
                else
                {
                    error("expected arithmetic expression..");
                }
                return new leq_expression(cr, l, r);
            }
            case symbol::GTEQ:
            {
                tk = next();
                arith_expression *l = nullptr;
                arith_expression *r = nullptr;
                if (arith_expression *c_e = dynamic_cast<arith_expression *>(e))
                {
                    l = c_e;
                }
                else
                {
                    error("expected arithmetic expression..");
                }
                if (arith_expression *c_e = dynamic_cast<arith_expression *>(_expression(2)))
                {
                    r = c_e;
                }
                else
                {
                    error("expected arithmetic expression..");
                }
                return new geq_expression(cr, l, r);
            }
            case symbol::GT:
            {
                tk = next();
                arith_expression *l = nullptr;
                arith_expression *r = nullptr;
                if (arith_expression *c_e = dynamic_cast<arith_expression *>(e))
                {
                    l = c_e;
                }
                else
                {
                    error("expected arithmetic expression..");
                }
                if (arith_expression *c_e = dynamic_cast<arith_expression *>(_expression(2)))
                {
                    r = c_e;
                }
                else
                {
                    error("expected arithmetic expression..");
                }
                return new gt_expression(cr, l, r);
            }
            case symbol::IMPLICATION:
            {
                tk = next();
                bool_expression *l = nullptr;
                bool_expression *r = nullptr;
                if (bool_expression *c_e = dynamic_cast<bool_expression *>(e))
                {
                    l = c_e;
                }
                else
                {
                    error("expected boolean expression..");
                }
                if (bool_expression *c_e = dynamic_cast<bool_expression *>(_expression(2)))
                {
                    r = c_e;
                }
                else
                {
                    error("expected boolean expression..");
                }
                return new implication_expression(cr, l, r);
            }
            case symbol::BAR:
            {
                tk = next();
                std::vector<bool_expression *> xprs;
                if (bool_expression *c_e = dynamic_cast<bool_expression *>(e))
                {
                    xprs.push_back(c_e);
                }
                else
                {
                    error("expected boolean expression..");
                }
                while (match(symbol::BAR))
                {
                    if (bool_expression *c_e = dynamic_cast<bool_expression *>(_expression(2)))
                    {
                        xprs.push_back(c_e);
                    }
                    else
                    {
                        error("expected boolean expression..");
                    }
                }
                return new disjunction_expression(cr, xprs);
            }
            case symbol::AMP:
            {
                tk = next();
                std::vector<bool_expression *> xprs;
                if (bool_expression *c_e = dynamic_cast<bool_expression *>(e))
                {
                    xprs.push_back(c_e);
                }
                else
                {
                    error("expected boolean expression..");
                }
                while (match(symbol::AMP))
                {
                    if (bool_expression *c_e = dynamic_cast<bool_expression *>(_expression(2)))
                    {
                        xprs.push_back(c_e);
                    }
                    else
                    {
                        error("expected boolean expression..");
                    }
                }
                return new conjunction_expression(cr, xprs);
            }
            case symbol::CARET:
            {
                tk = next();
                std::vector<bool_expression *> xprs;
                if (bool_expression *c_e = dynamic_cast<bool_expression *>(e))
                {
                    xprs.push_back(c_e);
                }
                else
                {
                    error("expected boolean expression..");
                }
                while (match(symbol::AMP))
                {
                    if (bool_expression *c_e = dynamic_cast<bool_expression *>(_expression(2)))
                    {
                        xprs.push_back(c_e);
                    }
                    else
                    {
                        error("expected boolean expression..");
                    }
                }
                return new exct_one_expression(cr, xprs);
            }
            }
        }
        if (3 >= pr)
        {
            switch (tk->sym)
            {
            case symbol::PLUS:
            {
                tk = next();
                std::vector<arith_expression *> xprs;
                if (arith_expression *c_e = dynamic_cast<arith_expression *>(e))
                {
                    xprs.push_back(c_e);
                }
                else
                {
                    error("expected arithmetic expression..");
                }
                while (match(symbol::PLUS))
                {
                    if (arith_expression *c_e = dynamic_cast<arith_expression *>(_expression(4)))
                    {
                        xprs.push_back(c_e);
                    }
                    else
                    {
                        error("expected arithmetic expression..");
                    }
                }
                return new addition_expression(cr, xprs);
            }
            case symbol::MINUS:
            {
                tk = next();
                std::vector<arith_expression *> xprs;
                if (arith_expression *c_e = dynamic_cast<arith_expression *>(e))
                {
                    xprs.push_back(c_e);
                }
                else
                {
                    error("expected arithmetic expression..");
                }
                while (match(symbol::MINUS))
                {
                    if (arith_expression *c_e = dynamic_cast<arith_expression *>(_expression(4)))
                    {
                        xprs.push_back(c_e);
                    }
                    else
                    {
                        error("expected arithmetic expression..");
                    }
                }
                return new subtraction_expression(cr, xprs);
            }
            }
        }
        if (5 >= pr)
        {
            switch (tk->sym)
            {
            case symbol::STAR:
            {
                tk = next();
                std::vector<arith_expression *> xprs;
                if (arith_expression *c_e = dynamic_cast<arith_expression *>(e))
                {
                    xprs.push_back(c_e);
                }
                else
                {
                    error("expected arithmetic expression..");
                }
                while (match(symbol::STAR))
                {
                    if (arith_expression *c_e = dynamic_cast<arith_expression *>(_expression(4)))
                    {
                        xprs.push_back(c_e);
                    }
                    else
                    {
                        error("expected arithmetic expression..");
                    }
                }
                return new multiplication_expression(cr, xprs);
            }
            case symbol::SLASH:
            {
                tk = next();
                std::vector<arith_expression *> xprs;
                if (arith_expression *c_e = dynamic_cast<arith_expression *>(e))
                {
                    xprs.push_back(c_e);
                }
                else
                {
                    error("expected arithmetic expression..");
                }
                while (match(symbol::SLASH))
                {
                    if (arith_expression *c_e = dynamic_cast<arith_expression *>(_expression(4)))
                    {
                        xprs.push_back(c_e);
                    }
                    else
                    {
                        error("expected arithmetic expression..");
                    }
                }
                return new division_expression(cr, xprs);
            }
            }
        }
    }

    return e;
}

void parser::error(const std::string &err) { throw std::invalid_argument("[" + std::to_string(tk->start_line) + ", " + std::to_string(tk->start_pos) + "] " + err); }
}