#ifndef TOKENIZER_H
#define TOKENIZER_H
#include "tokens.h"
#include <cctype>
#include <vector>

//created to tokenize a file's content into tokens
class Tokenizer {
public:
    Tokenizer(const std::string& input) : input(input), position(0) {}
    std::vector<Token> tokenize();
private:
    std::string input;
    size_t position;
    void skip_whitespace();
    Token next_token();
    bool is_at_end() const;
    char current() const;
    char peek() const;
    void advance();
};

inline std::vector<Token> Tokenizer::tokenize()
{
    std::vector<Token> tokens;

    while (!is_at_end()) {
        skip_whitespace();

        if (is_at_end())
            break;

        tokens.push_back(next_token());
    }

    tokens.push_back(Token{TokenType::END_OF_FILE, ""});
    return tokens;
}

inline void Tokenizer::skip_whitespace()
{
    while (!is_at_end() && std::isspace(current()) && current() != '\n') {
        advance();
    }
}

inline Token Tokenizer::next_token()
{
    while (!is_at_end() && std::isspace(current()) && current() != '\n') {
        advance();
    }
}

inline bool Tokenizer::is_at_end() const
{
    return position >= input.length();
}

inline char Tokenizer::current() const
{
    return is_at_end() ? '\0' : input[position];
}

inline char Tokenizer::peek() const
{
    return position + 1 >= input.length() ? '\0' : input[position+1];
}

inline void Tokenizer::advance()
{
    position++;
}

#endif // TOKENIZER_H
