#include "lexer.h"
#include <iostream>
#include <stdexcept>

namespace lucy
{

bool is_id_part(const char &ch) { return ch == '_' || (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9'); }

lexer::lexer(std::istream &is) : is(is) {}

lexer::~lexer() {}

token *lexer::next()
{
    ch = static_cast<char>(is.get());
    switch (ch)
    {
    case '"': // string literal
    {
        std::vector<char> str;
        end_pos++;
        while (true)
        {
            ch = static_cast<char>(is.get());
            switch (ch)
            {
            case '"':
                end_pos++;
                return mk_string_token(std::string(str.begin(), str.end()));
            case '\\':
                // read escaped char
                end_pos++;
                ch = static_cast<char>(is.get());
                str.push_back(ch);
                break;
            case '\r':
            case '\n':
                error("newline in string literal..");
            case EOF:
                error("invalid string literal..");
            default:
                str.push_back(ch);
            }
        }
    }
    case '/':
        end_pos++;
        ch = static_cast<char>(is.get());
        switch (ch)
        {
        case '/': // in single-line comment
            end_pos++;
            while (true)
            {
                ch = static_cast<char>(is.get());
                end_pos++;
                switch (ch)
                {
                case '\r':
                    if (is.get() != '\n')
                        is.unget();
                case '\n':
                    end_line++;
                    end_pos = 0;
                    return next();
                case EOF:
                    return mk_token(EOF_ID);
                }
            }
        case '*': // in multi-line comment
            end_pos++;
            while (true)
            {
                ch = static_cast<char>(is.get());
                end_pos++;
                switch (ch)
                {
                case '*':
                    ch = static_cast<char>(is.get());
                    end_pos++;
                    if (ch == '/')
                        return next();
                    break;
                case '\r':
                    if (is.get() != '\n')
                        is.unget();
                case '\n':
                    end_line++;
                    end_pos = 0;
                }
            }
        }
        is.unget();
        end_pos--;
        return mk_token(SLASH_ID);
    case '=':
        end_pos++;
        ch = static_cast<char>(is.get());
        if (ch == '=')
        {
            end_pos++;
            return mk_token(EQEQ_ID);
        }
        is.unget();
        return mk_token(EQ_ID);
    case '>':
        end_pos++;
        ch = static_cast<char>(is.get());
        if (ch == '=')
        {
            end_pos++;
            return mk_token(GTEQ_ID);
        }
        is.unget();
        return mk_token(GT_ID);
    case '<':
        end_pos++;
        ch = static_cast<char>(is.get());
        if (ch == '=')
        {
            end_pos++;
            return mk_token(LTEQ_ID);
        }
        is.unget();
        return mk_token(LT_ID);
    case '+':
        end_pos++;
        return mk_token(PLUS_ID);
    case '-':
        end_pos++;
        return mk_token(MINUS_ID);
    case '|':
        end_pos++;
        return mk_token(BAR_ID);
    case '&':
        end_pos++;
        return mk_token(AMP_ID);
    case '^':
        end_pos++;
        return mk_token(CARET_ID);
    case '!':
        end_pos++;
        return mk_token(BANG_ID);
    case '.':
        end_pos++;
        ch = static_cast<char>(is.get());
        end_pos++;
        if ('0' <= ch && ch <= '9') // in a number literal..
        {
            std::vector<char> dec;
            dec.push_back(ch);
            while (true)
            {
                ch = static_cast<char>(is.get());
                switch (ch)
                {
                case '0':
                case '1':
                case '2':
                case '3':
                case '4':
                case '5':
                case '6':
                case '7':
                case '8':
                case '9':
                    end_pos++;
                    dec.push_back(ch);
                    break;
                case '.':
                    error("invalid numeric literal..");
                default:
                    is.unget();
                    return mk_rational_token("", std::string(dec.begin(), dec.end()));
                }
            }
        }
        is.unget();
        end_pos--;
        return mk_token(DOT_ID);
    case ',':
        end_pos++;
        return mk_token(COMMA_ID);
    case ';':
        end_pos++;
        return mk_token(SEMICOLON_ID);
    case ':':
        end_pos++;
        return mk_token(COLON_ID);
    case '(':
        end_pos++;
        return mk_token(LPAREN_ID);
    case ')':
        end_pos++;
        return mk_token(RPAREN_ID);
    case '[':
        end_pos++;
        return mk_token(LBRACKET_ID);
    case ']':
        end_pos++;
        return mk_token(RBRACKET_ID);
    case '{':
        end_pos++;
        return mk_token(LBRACE_ID);
    case '}':
        end_pos++;
        return mk_token(RBRACE_ID);
    case '0': // in a number literal..
    case '1':
    case '2':
    case '3':
    case '4':
    case '5':
    case '6':
    case '7':
    case '8':
    case '9':
    {
        end_pos++;
        std::vector<char> intgr; // the integer part..
        intgr.push_back(ch);
        while (true)
        {
            ch = static_cast<char>(is.get());
            switch (ch)
            {
            case '0':
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':
                end_pos++;
                intgr.push_back(ch);
                break;
            case '.':
            {
                end_pos++;
                std::vector<char> dcml; // the decimal part..
                while (true)
                {
                    ch = static_cast<char>(is.get());
                    switch (ch)
                    {
                    case '0':
                    case '1':
                    case '2':
                    case '3':
                    case '4':
                    case '5':
                    case '6':
                    case '7':
                    case '8':
                    case '9':
                        end_pos++;
                        dcml.push_back(ch);
                        break;
                    case '.':
                        error("invalid numeric literal..");
                        break;
                    default:
                        is.unget();
                        return mk_rational_token(std::string(intgr.begin(), intgr.end()), std::string(dcml.begin(), dcml.end()));
                    }
                }
            }
            default:
                is.unget();
                return mk_integer_token(std::string(intgr.begin(), intgr.end()));
            }
        }
    }
    case 'b':
    {
        end_pos++;
        std::vector<char> str;
        str.push_back(ch);
        ch = static_cast<char>(is.get());
        if (ch != 'o')
        {
            is.unget();
            return finish_id(str);
        }
        end_pos++;
        str.push_back(ch);
        ch = static_cast<char>(is.get());
        if (ch != 'o')
        {
            is.unget();
            return finish_id(str);
        }
        end_pos++;
        str.push_back(ch);
        ch = static_cast<char>(is.get());
        if (ch != 'l')
        {
            is.unget();
            return finish_id(str);
        }
        end_pos++;
        str.push_back(ch);
        ch = static_cast<char>(is.get());
        if (!is_id_part(ch))
        {
            is.unget();
            return mk_token(BOOL_ID);
        }
        else
        {
            is.unget();
            return finish_id(str);
        }
    }
    case 'c':
    {
        end_pos++;
        std::vector<char> str;
        str.push_back(ch);
        ch = static_cast<char>(is.get());
        if (ch != 'l')
        {
            is.unget();
            return finish_id(str);
        }
        end_pos++;
        str.push_back(ch);
        ch = static_cast<char>(is.get());
        if (ch != 'a')
        {
            is.unget();
            return finish_id(str);
        }
        end_pos++;
        str.push_back(ch);
        ch = static_cast<char>(is.get());
        if (ch != 's')
        {
            is.unget();
            return finish_id(str);
        }
        end_pos++;
        str.push_back(ch);
        ch = static_cast<char>(is.get());
        if (ch != 's')
        {
            is.unget();
            return finish_id(str);
        }
        end_pos++;
        str.push_back(ch);
        ch = static_cast<char>(is.get());
        if (!is_id_part(ch))
        {
            is.unget();
            return mk_token(CLASS_ID);
        }
        else
        {
            is.unget();
            return finish_id(str);
        }
    }
    case 'e':
    {
        end_pos++;
        std::vector<char> str;
        str.push_back(ch);
        ch = static_cast<char>(is.get());
        if (ch != 'n')
        {
            is.unget();
            return finish_id(str);
        }
        end_pos++;
        str.push_back(ch);
        ch = static_cast<char>(is.get());
        if (ch != 'u')
        {
            is.unget();
            return finish_id(str);
        }
        end_pos++;
        str.push_back(ch);
        ch = static_cast<char>(is.get());
        if (ch != 'm')
        {
            is.unget();
            return finish_id(str);
        }
        end_pos++;
        str.push_back(ch);
        ch = static_cast<char>(is.get());
        if (!is_id_part(ch))
        {
            is.unget();
            return mk_token(ENUM_ID);
        }
        else
        {
            is.unget();
            return finish_id(str);
        }
    }
    case 'f':
    {
        end_pos++;
        std::vector<char> str;
        str.push_back(ch);
        ch = static_cast<char>(is.get());
        if (ch != 'a')
        {
            is.unget();
            return finish_id(str);
        }
        end_pos++;
        str.push_back(ch);
        ch = static_cast<char>(is.get());
        switch (ch)
        {
        case 'c':
            end_pos++;
            str.push_back(ch);
            ch = static_cast<char>(is.get());
            if (ch != 't')
            {
                is.unget();
                return finish_id(str);
            }
            end_pos++;
            str.push_back(ch);
            ch = static_cast<char>(is.get());
            if (!is_id_part(ch))
            {
                is.unget();
                return mk_token(FACT_ID);
            }
            else
            {
                is.unget();
                return finish_id(str);
            }
        case 'l':
            end_pos++;
            str.push_back(ch);
            ch = static_cast<char>(is.get());
            if (ch != 's')
            {
                is.unget();
                return finish_id(str);
            }
            end_pos++;
            str.push_back(ch);
            ch = static_cast<char>(is.get());
            if (ch != 'e')
            {
                is.unget();
                return finish_id(str);
            }
            end_pos++;
            str.push_back(ch);
            ch = static_cast<char>(is.get());
            if (!is_id_part(ch))
            {
                is.unget();
                return mk_token(FALSE_ID);
            }
            else
            {
                is.unget();
                return finish_id(str);
            }
        }
        is.unget();
        return finish_id(str);
    }
    case 'g':
    {
        end_pos++;
        std::vector<char> str;
        str.push_back(ch);
        ch = static_cast<char>(is.get());
        if (ch != 'o')
        {
            is.unget();
            return finish_id(str);
        }
        end_pos++;
        str.push_back(ch);
        ch = static_cast<char>(is.get());
        if (ch != 'a')
        {
            is.unget();
            return finish_id(str);
        }
        end_pos++;
        str.push_back(ch);
        ch = static_cast<char>(is.get());
        if (ch != 'l')
        {
            is.unget();
            return finish_id(str);
        }
        end_pos++;
        str.push_back(ch);
        ch = static_cast<char>(is.get());
        if (!is_id_part(ch))
        {
            is.unget();
            return mk_token(GOAL_ID);
        }
        else
        {
            is.unget();
            return finish_id(str);
        }
    }
    case 'i':
    {
        end_pos++;
        std::vector<char> str;
        str.push_back(ch);
        ch = static_cast<char>(is.get());
        if (ch != 'n')
        {
            is.unget();
            return finish_id(str);
        }
        end_pos++;
        str.push_back(ch);
        ch = static_cast<char>(is.get());
        if (ch != 't')
        {
            is.unget();
            return finish_id(str);
        }
        end_pos++;
        str.push_back(ch);
        ch = static_cast<char>(is.get());
        if (!is_id_part(ch))
        {
            is.unget();
            return mk_token(INT_ID);
        }
        else
        {
            is.unget();
            return finish_id(str);
        }
    }
    case 'n':
    {
        end_pos++;
        std::vector<char> str;
        str.push_back(ch);
        ch = static_cast<char>(is.get());
        if (ch != 'e')
        {
            is.unget();
            return finish_id(str);
        }
        end_pos++;
        str.push_back(ch);
        ch = static_cast<char>(is.get());
        if (ch != 'w')
        {
            is.unget();
            return finish_id(str);
        }
        end_pos++;
        str.push_back(ch);
        ch = static_cast<char>(is.get());
        if (!is_id_part(ch))
        {
            is.unget();
            return mk_token(NEW_ID);
        }
        else
        {
            is.unget();
            return finish_id(str);
        }
    }
    case 'o':
    {
        end_pos++;
        std::vector<char> str;
        str.push_back(ch);
        ch = static_cast<char>(is.get());
        if (ch != 'r')
        {
            is.unget();
            return finish_id(str);
        }
        end_pos++;
        str.push_back(ch);
        ch = static_cast<char>(is.get());
        if (!is_id_part(ch))
        {
            is.unget();
            return mk_token(OR_ID);
        }
        else
        {
            is.unget();
            return finish_id(str);
        }
    }
    case 'p':
    {
        end_pos++;
        std::vector<char> str;
        str.push_back(ch);
        ch = static_cast<char>(is.get());
        if (ch != 'r')
        {
            is.unget();
            return finish_id(str);
        }
        end_pos++;
        str.push_back(ch);
        ch = static_cast<char>(is.get());
        if (ch != 'e')
        {
            is.unget();
            return finish_id(str);
        }
        end_pos++;
        str.push_back(ch);
        ch = static_cast<char>(is.get());
        if (ch != 'd')
        {
            is.unget();
            return finish_id(str);
        }
        end_pos++;
        str.push_back(ch);
        ch = static_cast<char>(is.get());
        if (ch != 'i')
        {
            is.unget();
            return finish_id(str);
        }
        end_pos++;
        str.push_back(ch);
        ch = static_cast<char>(is.get());
        if (ch != 'c')
        {
            is.unget();
            return finish_id(str);
        }
        end_pos++;
        str.push_back(ch);
        ch = static_cast<char>(is.get());
        if (ch != 'a')
        {
            is.unget();
            return finish_id(str);
        }
        end_pos++;
        str.push_back(ch);
        ch = static_cast<char>(is.get());
        if (ch != 't')
        {
            is.unget();
            return finish_id(str);
        }
        end_pos++;
        str.push_back(ch);
        ch = static_cast<char>(is.get());
        if (ch != 'e')
        {
            is.unget();
            return finish_id(str);
        }
        end_pos++;
        str.push_back(ch);
        ch = static_cast<char>(is.get());
        if (!is_id_part(ch))
        {
            is.unget();
            return mk_token(PREDICATE_ID);
        }
        else
        {
            is.unget();
            return finish_id(str);
        }
    }
    case 'r':
    {
        end_pos++;
        std::vector<char> str;
        str.push_back(ch);
        ch = static_cast<char>(is.get());
        if (ch != 'e')
        {
            is.unget();
            return finish_id(str);
        }
        end_pos++;
        str.push_back(ch);
        ch = static_cast<char>(is.get());
        switch (ch)
        {
        case 'a':
            end_pos++;
            str.push_back(ch);
            ch = static_cast<char>(is.get());
            if (ch != 'l')
            {
                is.unget();
                return finish_id(str);
            }
            end_pos++;
            str.push_back(ch);
            ch = static_cast<char>(is.get());
            if (!is_id_part(ch))
            {
                is.unget();
                return mk_token(REAL_ID);
            }
            else
            {
                is.unget();
                return finish_id(str);
            }
        case 't':
            end_pos++;
            str.push_back(ch);
            ch = static_cast<char>(is.get());
            if (ch != 'u')
            {
                is.unget();
                return finish_id(str);
            }
            end_pos++;
            str.push_back(ch);
            ch = static_cast<char>(is.get());
            if (ch != 'r')
            {
                is.unget();
                return finish_id(str);
            }
            end_pos++;
            str.push_back(ch);
            ch = static_cast<char>(is.get());
            if (ch != 'n')
            {
                is.unget();
                return finish_id(str);
            }
            end_pos++;
            str.push_back(ch);
            ch = static_cast<char>(is.get());
            if (!is_id_part(ch))
            {
                is.unget();
                return mk_token(RETURN_ID);
            }
            else
            {
                is.unget();
                return finish_id(str);
            }
        }
        is.unget();
        return finish_id(str);
    }
    case 's':
    {
        end_pos++;
        std::vector<char> str;
        str.push_back(ch);
        ch = static_cast<char>(is.get());
        if (ch != 't')
        {
            is.unget();
            return finish_id(str);
        }
        end_pos++;
        str.push_back(ch);
        ch = static_cast<char>(is.get());
        if (ch != 'r')
        {
            is.unget();
            return finish_id(str);
        }
        end_pos++;
        str.push_back(ch);
        ch = static_cast<char>(is.get());
        if (ch != 'i')
        {
            is.unget();
            return finish_id(str);
        }
        end_pos++;
        str.push_back(ch);
        ch = static_cast<char>(is.get());
        if (ch != 'n')
        {
            is.unget();
            return finish_id(str);
        }
        end_pos++;
        str.push_back(ch);
        ch = static_cast<char>(is.get());
        if (ch != 'g')
        {
            is.unget();
            return finish_id(str);
        }
        end_pos++;
        str.push_back(ch);
        ch = static_cast<char>(is.get());
        if (!is_id_part(ch))
        {
            is.unget();
            return mk_token(STRING_ID);
        }
        else
        {
            is.unget();
            return finish_id(str);
        }
    }
    case 't':
    {
        end_pos++;
        std::vector<char> str;
        str.push_back(ch);
        ch = static_cast<char>(is.get());
        switch (ch)
        {
        case 'r':
            end_pos++;
            str.push_back(ch);
            ch = static_cast<char>(is.get());
            if (ch != 'u')
            {
                is.unget();
                return finish_id(str);
            }
            end_pos++;
            str.push_back(ch);
            ch = static_cast<char>(is.get());
            if (ch != 'e')
            {
                is.unget();
                return finish_id(str);
            }
            end_pos++;
            str.push_back(ch);
            ch = static_cast<char>(is.get());
            if (!is_id_part(ch))
            {
                is.unget();
                return mk_token(TRUE_ID);
            }
            else
            {
                is.unget();
                return finish_id(str);
            }
        case 'y':
            end_pos++;
            str.push_back(ch);
            ch = static_cast<char>(is.get());
            if (ch != 'p')
            {
                is.unget();
                return finish_id(str);
            }
            end_pos++;
            str.push_back(ch);
            ch = static_cast<char>(is.get());
            if (ch != 'e')
            {
                is.unget();
                return finish_id(str);
            }
            end_pos++;
            str.push_back(ch);
            ch = static_cast<char>(is.get());
            if (ch != 'd')
            {
                is.unget();
                return finish_id(str);
            }
            end_pos++;
            str.push_back(ch);
            ch = static_cast<char>(is.get());
            if (ch != 'e')
            {
                is.unget();
                return finish_id(str);
            }
            end_pos++;
            str.push_back(ch);
            ch = static_cast<char>(is.get());
            if (ch != 'f')
            {
                is.unget();
                return finish_id(str);
            }
            end_pos++;
            str.push_back(ch);
            ch = static_cast<char>(is.get());
            if (!is_id_part(ch))
            {
                is.unget();
                return mk_token(TYPEDEF_ID);
            }
            else
            {
                is.unget();
                return finish_id(str);
            }
        }
        is.unget();
        return finish_id(str);
    }
    case 'v':
    {
        end_pos++;
        std::vector<char> str;
        str.push_back(ch);
        ch = static_cast<char>(is.get());
        if (ch != 'o')
        {
            is.unget();
            return finish_id(str);
        }
        end_pos++;
        str.push_back(ch);
        ch = static_cast<char>(is.get());
        if (ch != 'i')
        {
            is.unget();
            return finish_id(str);
        }
        end_pos++;
        str.push_back(ch);
        ch = static_cast<char>(is.get());
        if (ch != 'd')
        {
            is.unget();
            return finish_id(str);
        }
        end_pos++;
        str.push_back(ch);
        ch = static_cast<char>(is.get());
        if (!is_id_part(ch))
        {
            is.unget();
            return mk_token(VOID_ID);
        }
        else
        {
            is.unget();
            return finish_id(str);
        }
    }
    case 'a':
    case 'd':
    case 'h':
    case 'j':
    case 'k':
    case 'l':
    case 'm':
    case 'q':
    case 'u':
    case 'w':
    case 'x':
    case 'y':
    case 'z':
    case 'A':
    case 'B':
    case 'C':
    case 'D':
    case 'E':
    case 'F':
    case 'G':
    case 'H':
    case 'I':
    case 'J':
    case 'K':
    case 'L':
    case 'M':
    case 'N':
    case 'O':
    case 'P':
    case 'Q':
    case 'R':
    case 'S':
    case 'T':
    case 'U':
    case 'V':
    case 'W':
    case 'X':
    case 'Y':
    case 'Z':
    case '_':
    {
        end_pos++;
        std::vector<char> str;
        str.push_back(ch);
        return finish_id(str);
    }
    case '\t':
        start_pos += 4 - (start_pos % 4);
        end_pos += 4 - (end_pos % 4);
        return finish_whitespaces();
    case ' ':
        start_pos++;
        end_pos++;
        return finish_whitespaces();
    case '\r':
        if (is.get() != '\n')
            is.unget();
    case '\n':
        end_line++;
        end_pos = 0;
        return finish_whitespaces();
    case EOF:
        return mk_token(EOF_ID);
    default:
        error("invalid token..");
        return nullptr;
    }
}

token *lexer::finish_id(std::vector<char> &str)
{
    while (true)
    {
        ch = static_cast<char>(is.get());
        if (str.empty() && ch >= '0' && ch <= '9')
            error("identifiers cannot start with numbers..");
        if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || ch == '_' || (ch >= '0' && ch <= '9'))
        {
            end_pos++;
            str.push_back(ch);
        }
        else
        {
            is.unget();
            return mk_id_token(std::string(str.begin(), str.end()));
        }
    }
}

token *lexer::finish_whitespaces()
{
    while (true)
    {
        ch = static_cast<char>(is.get());
        switch (ch)
        {
        case '\t':
            start_pos += 4 - (start_pos % 4);
            end_pos += 4 - (end_pos % 4);
            break;
        case ' ':
            start_pos++;
            end_pos++;
            break;
        case '\r':
            if (is.get() != '\n')
                is.unget();
        case '\n':
            end_line++;
            end_pos = 0;
            break;
        case EOF:
            return mk_token(EOF_ID);
        default:
            is.unget();
            return next();
        }
    }
}

void lexer::error(const std::string &err) { throw std::invalid_argument("[" + std::to_string(start_line) + ", " + std::to_string(start_pos) + "] " + err); }
}