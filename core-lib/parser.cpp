#include "parser.h"
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
    expr *xpr;

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

    xpr = _expr();

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
    std::vector<std::pair<std::string, std::vector<expr *>>> il;
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
        std::vector<expr *> xprs;
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
            xprs.push_back(_expr());
            while (!match(symbol::RPAREN))
            {
                if (!match(symbol::COMMA))
                {
                    error("expected ','..");
                }
                xprs.push_back(_expr());
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
            expr *e = nullptr;
            tk = next();
            if (tk->sym == symbol::EQ)
            {
                tk = next();
                e = _expr();
            }
            if (!match(symbol::SEMICOLON))
            {
                error("expected ';'..");
            }
            return new local_field_statement(ids, n, _expr());
        }
        case symbol::EQ: // an assignment..
        {
            tk = next();
            expr *xpr = _expr();
            if (!match(symbol::SEMICOLON))
            {
                error("expected ';'..");
            }
            return new assignment_statement(ids, xpr);
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
            }
            return new disjunction_statement(disjs);
        }
        else
        {
            if (!match(symbol::SEMICOLON))
            {
                error("expected ';'..");
            }
            return new block_statement(stmnts);
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
        std::vector<std::pair<std::string, expr *>> assgns;

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
            assgns.push_back({dynamic_cast<id_token *>(tks[pos - 2])->id, _expr()});
        }

        if (!match(symbol::RPAREN))
        {
            error("expected ')'..");
        }

        if (!match(symbol::SEMICOLON))
        {
            error("expected ';'..");
        }
        return new formula_statement(isf, fn, scp, pn, assgns);
    }
    case symbol::RETURN:
    {
        expr *xpr = _expr();
        if (!match(symbol::SEMICOLON))
        {
            error("expected ';'..");
        }
        return new return_statement(xpr);
    }
    default:
        return new expression_statement(dynamic_cast<bool_expr *>(_expr()));
    }
}

expr *parser::_expr(const size_t &pr)
{
    expr *e = nullptr;
    switch (tk->sym)
    {
    case symbol::TRUE:
    case symbol::FALSE:
        tk = next();
        e = new bool_literal_expr(tks[pos - 2]->sym == symbol::TRUE);
    case symbol::NumericLiteral:
        tk = next();
        e = new arith_literal_expr(dynamic_cast<numeric_token *>(tks[pos - 2])->val);
    case symbol::StringLiteral:
        tk = next();
        e = new string_literal_expr(dynamic_cast<string_token *>(tks[pos - 2])->str);
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
                expr *xpr = _expr();
                e = new cast_expr(ids, xpr);
            }
            else // a parenthesis..
            {
                backtrack(c_pos);
                expr *xpr = _expr();
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
        if (arith_expr *ae = dynamic_cast<arith_expr *>(_expr()))
        {
            e = new plus_expr(ae);
        }
        else
        {
            error("expected arithmetic expression..");
        }
    case symbol::MINUS:
        tk = next();
        if (arith_expr *ae = dynamic_cast<arith_expr *>(_expr()))
        {
            e = new minus_expr(ae);
        }
        else
        {
            error("expected arithmetic expression..");
        }
    case symbol::BANG:
        tk = next();
        if (bool_expr *be = dynamic_cast<bool_expr *>(_expr()))
        {
            e = new not_expr(be);
        }
        else
        {
            error("expected boolean expression..");
        }
    case symbol::LBRACKET:
    {
        tk = next();
        arith_expr *min_e;
        arith_expr *max_e;
        if (arith_expr *e = dynamic_cast<arith_expr *>(_expr()))
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
        if (arith_expr *e = dynamic_cast<arith_expr *>(_expr()))
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
        e = new range_expr(min_e, max_e);
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

        std::vector<expr *> xprs;
        if (!match(symbol::LPAREN))
        {
            error("expected '('..");
        }
        if (!match(symbol::RPAREN))
        {
            xprs.push_back(_expr());
            while (!match(symbol::RPAREN))
            {
                if (!match(symbol::COMMA))
                {
                    error("expected ','..");
                }
                xprs.push_back(_expr());
            }
        }
        e = new constructor_expr(ids, xprs);
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
            std::vector<expr *> xprs;
            if (!match(symbol::RPAREN))
            {
                xprs.push_back(_expr());
                while (!match(symbol::RPAREN))
                {
                    if (!match(symbol::COMMA))
                    {
                        error("expected ','..");
                    }
                    xprs.push_back(_expr());
                }
            }
            e = new function_expr(is, fn, xprs);
        }
        else
        {
            e = new id_expr(is);
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
                return new eq_expr(e, _expr(1));
            case symbol::BANGEQ:
                tk = next();
                return new neq_expr(e, _expr(1));
            }
        }
        if (1 >= pr)
        {
            switch (tk->sym)
            {
            case symbol::LT:
            {
                tk = next();
                arith_expr *l = nullptr;
                arith_expr *r = nullptr;
                if (arith_expr *c_e = dynamic_cast<arith_expr *>(e))
                {
                    l = c_e;
                }
                else
                {
                    error("expected arithmetic expression..");
                }
                if (arith_expr *c_e = dynamic_cast<arith_expr *>(_expr(2)))
                {
                    r = c_e;
                }
                else
                {
                    error("expected arithmetic expression..");
                }
                return new lt_expr(l, r);
            }
            case symbol::LTEQ:
            {
                tk = next();
                arith_expr *l = nullptr;
                arith_expr *r = nullptr;
                if (arith_expr *c_e = dynamic_cast<arith_expr *>(e))
                {
                    l = c_e;
                }
                else
                {
                    error("expected arithmetic expression..");
                }
                if (arith_expr *c_e = dynamic_cast<arith_expr *>(_expr(2)))
                {
                    r = c_e;
                }
                else
                {
                    error("expected arithmetic expression..");
                }
                return new leq_expr(l, r);
            }
            case symbol::GTEQ:
            {
                tk = next();
                arith_expr *l = nullptr;
                arith_expr *r = nullptr;
                if (arith_expr *c_e = dynamic_cast<arith_expr *>(e))
                {
                    l = c_e;
                }
                else
                {
                    error("expected arithmetic expression..");
                }
                if (arith_expr *c_e = dynamic_cast<arith_expr *>(_expr(2)))
                {
                    r = c_e;
                }
                else
                {
                    error("expected arithmetic expression..");
                }
                return new geq_expr(l, r);
            }
            case symbol::GT:
            {
                tk = next();
                arith_expr *l = nullptr;
                arith_expr *r = nullptr;
                if (arith_expr *c_e = dynamic_cast<arith_expr *>(e))
                {
                    l = c_e;
                }
                else
                {
                    error("expected arithmetic expression..");
                }
                if (arith_expr *c_e = dynamic_cast<arith_expr *>(_expr(2)))
                {
                    r = c_e;
                }
                else
                {
                    error("expected arithmetic expression..");
                }
                return new gt_expr(l, r);
            }
            case symbol::IMPLICATION:
            {
                tk = next();
                bool_expr *l = nullptr;
                bool_expr *r = nullptr;
                if (bool_expr *c_e = dynamic_cast<bool_expr *>(e))
                {
                    l = c_e;
                }
                else
                {
                    error("expected boolean expression..");
                }
                if (bool_expr *c_e = dynamic_cast<bool_expr *>(_expr(2)))
                {
                    r = c_e;
                }
                else
                {
                    error("expected boolean expression..");
                }
                return new implication_expr(l, r);
            }
            case symbol::BAR:
            {
                tk = next();
                std::vector<bool_expr *> xprs;
                if (bool_expr *c_e = dynamic_cast<bool_expr *>(e))
                {
                    xprs.push_back(c_e);
                }
                else
                {
                    error("expected boolean expression..");
                }
                while (match(symbol::BAR))
                {
                    if (bool_expr *c_e = dynamic_cast<bool_expr *>(_expr(2)))
                    {
                        xprs.push_back(c_e);
                    }
                    else
                    {
                        error("expected boolean expression..");
                    }
                }
                return new disjunction_expr(xprs);
            }
            case symbol::AMP:
            {
                tk = next();
                std::vector<bool_expr *> xprs;
                if (bool_expr *c_e = dynamic_cast<bool_expr *>(e))
                {
                    xprs.push_back(c_e);
                }
                else
                {
                    error("expected boolean expression..");
                }
                while (match(symbol::AMP))
                {
                    if (bool_expr *c_e = dynamic_cast<bool_expr *>(_expr(2)))
                    {
                        xprs.push_back(c_e);
                    }
                    else
                    {
                        error("expected boolean expression..");
                    }
                }
                return new conjunction_expr(xprs);
            }
            case symbol::CARET:
            {
                tk = next();
                std::vector<bool_expr *> xprs;
                if (bool_expr *c_e = dynamic_cast<bool_expr *>(e))
                {
                    xprs.push_back(c_e);
                }
                else
                {
                    error("expected boolean expression..");
                }
                while (match(symbol::AMP))
                {
                    if (bool_expr *c_e = dynamic_cast<bool_expr *>(_expr(2)))
                    {
                        xprs.push_back(c_e);
                    }
                    else
                    {
                        error("expected boolean expression..");
                    }
                }
                return new exct_one_expr(xprs);
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
                std::vector<arith_expr *> xprs;
                if (arith_expr *c_e = dynamic_cast<arith_expr *>(e))
                {
                    xprs.push_back(c_e);
                }
                else
                {
                    error("expected arithmetic expression..");
                }
                while (match(symbol::PLUS))
                {
                    if (arith_expr *c_e = dynamic_cast<arith_expr *>(_expr(4)))
                    {
                        xprs.push_back(c_e);
                    }
                    else
                    {
                        error("expected arithmetic expression..");
                    }
                }
                return new addition_expr(xprs);
            }
            case symbol::MINUS:
            {
                tk = next();
                std::vector<arith_expr *> xprs;
                if (arith_expr *c_e = dynamic_cast<arith_expr *>(e))
                {
                    xprs.push_back(c_e);
                }
                else
                {
                    error("expected arithmetic expression..");
                }
                while (match(symbol::MINUS))
                {
                    if (arith_expr *c_e = dynamic_cast<arith_expr *>(_expr(4)))
                    {
                        xprs.push_back(c_e);
                    }
                    else
                    {
                        error("expected arithmetic expression..");
                    }
                }
                return new subtraction_expr(xprs);
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
                std::vector<arith_expr *> xprs;
                if (arith_expr *c_e = dynamic_cast<arith_expr *>(e))
                {
                    xprs.push_back(c_e);
                }
                else
                {
                    error("expected arithmetic expression..");
                }
                while (match(symbol::STAR))
                {
                    if (arith_expr *c_e = dynamic_cast<arith_expr *>(_expr(4)))
                    {
                        xprs.push_back(c_e);
                    }
                    else
                    {
                        error("expected arithmetic expression..");
                    }
                }
                return new multiplication_expr(xprs);
            }
            case symbol::SLASH:
            {
                tk = next();
                std::vector<arith_expr *> xprs;
                if (arith_expr *c_e = dynamic_cast<arith_expr *>(e))
                {
                    xprs.push_back(c_e);
                }
                else
                {
                    error("expected arithmetic expression..");
                }
                while (match(symbol::SLASH))
                {
                    if (arith_expr *c_e = dynamic_cast<arith_expr *>(_expr(4)))
                    {
                        xprs.push_back(c_e);
                    }
                    else
                    {
                        error("expected arithmetic expression..");
                    }
                }
                return new division_expr(xprs);
            }
            }
        }
    }

    return e;
}

void parser::error(const std::string &err) { throw std::invalid_argument("[" + std::to_string(tk->start_line) + ", " + std::to_string(tk->start_pos) + "] " + err); }
}