#pragma once
#include <string>
#include <vector>
#include <unordered_map>
#include <stack>
#include "tokens.h"

class Preprocessor {
public:
    std::vector<Token> process(const std::vector<Token>& tokens);
private:
    std::unordered_map<std::string, std::vector<Token>> macros;
    std::stack<bool> conditionalStack;

    void handle_directive(const std::vector<Token>& tokens, size_t& index, std::vector<Token>& output);

    void handle_define(const std::vector<Token>& tokens, size_t& index);

    void handle_ifndef(const std::vector<Token>& tokens, size_t& index, bool negated);

    void handle_endif();

    void handle_include(const std::vector<Token>& tokens, size_t& index, std::vector<Token>& output);

    void expand_macro(const Token& token, std::vector<Token>& output);

};
inline std::vector<Token> Preprocessor::process(const std::vector<Token> &tokens)
{

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
