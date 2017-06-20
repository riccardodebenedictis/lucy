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
    }

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
    if (!xpr)
    {
        error("expected expression..");
        return nullptr;
    }

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
    }

    if (!match(symbol::RBRACE))
    {
        error("expected '}'..");
        return nullptr;
    }

    return new class_declaration(n, bcs, fs, cs, ms, ps, ts);
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