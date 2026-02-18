#ifndef TOKENIZER_H
#define TOKENIZER_H
#include "tokens.h"
class Tokenizer {
public:
    Tokenizer(const std::string& input);
    std::vector<Token> tokenize();
    void skipWhitespace();
    Token nextToken();
    bool isAtEnd() const;
    char current() const;
    char peek() const;
    void advance();
private:
    std::string input;
    size_t position;
};

#endif // TOKENIZER_H
