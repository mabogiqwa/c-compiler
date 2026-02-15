#pragma once
#include <string>
#include <vector>
#include <unordered_map>
#include <stack>
#include <stdexcept>
#include "tokens.h"

class Preprocessor {
public:
    std::vector<Token> process(const std::vector<Token>& tokens);
    //Postcondition: Processes tokens to handle preprocessor directive such as #define, #include, etc
    //and also expand macros.
    //It iterates through tokens and when it finds # at the beginning of a line, it called handle_directive()
private:
    std::unordered_map<std::string, std::vector<Token>> macros;
    std::stack<bool> conditionalStack;

    void handle_directive(const std::vector<Token>& tokens, size_t& index, std::vector<Token>& output);

    void handle_define(const std::vector<Token>& tokens, size_t& index);

    void handle_ifndef(const std::vector<Token>& tokens, size_t& index, bool negated);

    void handle_endif();

    void handle_include(const std::vector<Token>& tokens, size_t& index, std::vector<Token>& output);

    void expand_macro(const Token& token, std::vector<Token>& output);

    bool isActive() const;
    //Postcondition: Determines if code should be compiled or skipped based on directives such as #ifndef,
    //#ifdef, #if, #else, #endif
};

inline std::vector<Token> Preprocessor::process(const std::vector<Token> &tokens)
{
    std::vector<Token> output;

    for (size_t i = 0; i < tokens.size(); i++) {
        const Token& tok = tokens[i];

        if (tok.type == TokenType::HASH && (i == 0 || tokens[i-1].type == TokenType::NEWLINE)) {
            handle_directive(tokens, i, output);
            continue;
        }
    }

    if (!isActive()) {
        continue;
    }

    if (tok.type == TokenType::IDENTIFIER && macros.count(tok.value)) {
        expandMacro(tok, output);
    } else {
        output.push_back(tok);
    }
}

inline void Preprocessor::handle_directive(const std::vector<Token> &tokens, size_t &index, std::vector<Token> &output)
{

}

inline void Preprocessor::handle_define(const std::vector<Token> &tokens, size_t &index)
{

}

inline void Preprocessor::handle_ifndef(const std::vector<Token> &tokens, size_t &index, bool negated)
{

}

inline void Preprocessor::handle_endif()
{

}

inline void Preprocessor::handle_include(const std::vector<Token> &tokens, size_t &index, std::vector<Token> &output)
{

}

inline void Preprocessor::expand_macro(const Token &token, std::vector<Token> &output)
{

}

inline bool Preprocessor::isActive() const
{
    std::stack<bool> copy= conditionalStack;
    while (!copy.empty()) {
        if (!copy.top())
            return false;
        copy.pop();
    }
    return true;
}
