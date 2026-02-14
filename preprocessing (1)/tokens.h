#pragma once
#include <string>

enum class TokenType {HASH, IDENTIFIER, NUMBER, STRING, NEWLINE, SYMBOL, END_OF_FILE};

struct Token {
    TokenType type;
    std::string value;
    int line;
};