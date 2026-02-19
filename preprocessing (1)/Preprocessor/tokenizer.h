#ifndef TOKENIZER_H
#define TOKENIZER_H
#include "tokens.h"

//created to tokenize a file's content into tokens
class Tokenizer {
public:
    Tokenizer(const std::string& input);
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

inline Tokenizer::Tokenizer(const std::string &input)
{
    std::vector<Token> tokens;

    while (!isAtEnd()) {
        skipWhitespace();

        if (isAtEnd())
            break;

        tokens.push_back(nextToken());
    }

    tokens.push_back(Token{TokenType::END_OF_FILE, ""});
    return tokens;
}

inline std::vector<Token> Tokenizer::tokenize()
{
    std::vector<Token> tokens;

    while (!isAtEnd()) {
        skipWhitespace();

        if (isAtEnd())
            break;

        tokens.push_back(nextToken());
    }

    tokens.push_back(Token{TokenType::END_OF_FILE, ""});
    return tokens;
}

inline void Tokenizer::skip_whitespace()
{

}

inline Token Tokenizer::next_token()
{
    while (!isAtEnd() && std::isspace(current()) && current() != '\n') {
        advance();
    }
}

inline bool Tokenizer::is_at_end() const
{
    return position >= input.length();
}

inline char Tokenizer::current() const
{

}

inline char Tokenizer::peek() const
{

}

inline void Tokenizer::advance()
{
    position++;
}

#endif // TOKENIZER_H
