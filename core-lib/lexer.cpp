#include "lexer.h"
#include <vector>
#include <iostream>
#include <string>

namespace lucy
{

lexer::lexer(std::istream &is) : is(is) {}

lexer::~lexer() {}

token lexer::next()
{
    while (true)
    {
        ch = is.get();
        switch (ch)
        {
        case '"': // string literal
        {
            std::vector<char> str;
            end_pos++;
            while (true)
            {
                ch = is.get();
                switch (ch)
                {
                case '"':
                    end_pos++;
                    return mk_string_token(std::string(str.begin(), str.end()));
                case '\\':
                    // read escaped char
                    end_pos++;
                    ch = is.get();
                    str.push_back(ch);
                    break;
                case '\r':
                case '\n':
                    error("newline in string literal..");
                    return mk_token(symbol::ERROR);
                case EOF:
                    error("invalid string literal..");
                    return mk_token(symbol::ERROR);
                default:
                    str.push_back(ch);
                }
            }
        }
        case '/':
            end_pos++;
            ch = is.get();
            switch (ch)
            {
            case '/': // in single-line comment
                end_pos++;
                while (true)
                {
                    ch = is.get();
                    end_pos++;
                    switch (ch)
                    {
                    case '\r':
                        if (is.get() != '\n')
                        {
                            is.unget();
                        }
                    case '\n':
                        end_line++;
                        end_pos = 0;
                    case EOF:
                        return mk_token(symbol::COMMENT);
                    }
                }
            case '*': // in multi-line comment
                end_pos++;
                while (true)
                {
                    ch = is.get();
                    end_pos++;
                    switch (ch)
                    {
                    case '*':
                        ch = is.get();
                        end_pos++;
                        if (ch == '/')
                        {
                            return mk_token(symbol::COMMENT);
                        }
                        break;
                    case '\r':
                        if (is.get() != '\n')
                        {
                            is.unget();
                        }
                    case '\n':
                        end_line++;
                        end_pos = 0;
                    }
                }
            }
            is.unget();
        case '\r':
            if (is.get() != '\n')
            {
                is.unget();
            }
        case '\n':
            end_line++;
            end_pos = 0;
            break;
        default:
            error("invalid token..");
            return mk_token(symbol::ERROR);
        }
    }
}

void lexer::error(const std::string &err) { std::cerr << "[" << std::to_string(start_line) << ", " << std::to_string(start_pos) << err << std::endl; }
}