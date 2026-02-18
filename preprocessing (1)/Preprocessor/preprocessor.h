#pragma once
#include <string>
#include <vector>
#include <unordered_map>
#include <stack>
#include <fstream>
#include <stdexcept>
#include "tokens.h"

class Preprocessor {
public:
    std::vector<Token> process(const std::vector<Token>& tokens);
    //Postcondition: Processes tokens to handle preprocessor directives such as #define, #include, etc
    //and also expand macros.
    //It iterates through tokens and when it finds # at the beginning of a line, it called handle_directive()
private:
    std::unordered_map<std::string, std::vector<Token>> macros;
    std::stack<bool> conditionalStack;

    void handle_directive(const std::vector<Token>& tokens, size_t& index, std::vector<Token>& output);

    void handle_define(const std::vector<Token>& tokens, size_t& index);
    //Postcondition: The macro name define and it's replacement tokens are extracted from the token stream and stored in the macros
    //map. The index is moved to the end of the macro definition.

    void handle_ifndef(const std::vector<Token>& tokens, size_t& index, bool negated);
    //Postcondition: index is incremented by 1. If the negated is false then the value indicates that the identifier exists in the macros map.
    //If the negated is true then the value indicates that the identifier does not exist in the macros map.

    void handle_endif();
    //Postcondition: The top element from conditionalStack is removed

    void handle_include(const std::vector<Token>& tokens, size_t& index, std::vector<Token>& output);

    void expand_macro(const Token& token, std::vector<Token>& output);
    //Postcondition: Takes a macro name and replaces it with allthe tokens that were defined for that macro, adding those tokens to the output vector.

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
    index++;

    if (tokens[index].type != TokenType::IDENTIFIER)
        throw std::runtime_error("Expected an identifier after #define");

    std::string name = tokens[index].value;
    index++;

    std::vector<Token> replacement;

    while (tokens[index].type != TokenType::NEWLINE && tokens[index].type != TokenType::END_OF_FILE) {
        replacement.push_back(tokens[index]);
        index++;
    }

    macros[name] = replacement;
}

inline void Preprocessor::handle_ifndef(const std::vector<Token> &tokens, size_t &index, bool negated)
{
    index++;

    if (tokens[index].type != TokenType::IDENTIFIER) //checks if the current index pos is not an identifier type and stops execution
        throw std::runtime_error("Expected identifier after #ifndef");

    bool defined = macros.count(tokens[index].value); //checks if the macro name exists in the macros map. count() returns 1 if the macro is found and 0 if it isn't.
    bool result = negated ? !defined : defined; //ternary operator to decide what boolean value is stored

    conditionalStack.push(result); //Adds boolean result onto the conditionalStack.
}

inline void Preprocessor::handle_endif()
{
    if (conditionalStack.empty()) {
        throw std::runtime_error("Unmatched #endif");
    }
    conditionalStack.pop();
}

inline void Preprocessor::handle_include(const std::vector<Token> &tokens, size_t &index, std::vector<Token> &output)
{
    index++;

    if (tokens[index].type != TokenType::STRING)
        throw std::runtime_error("Expected filename after #include");

    std::string filename = tokens[index].value;
    index++;

    std::ifstream file(filename); //reads file and tokenises it
    if (!file.is_open())
        throw std::runtime_error("Cannot open file: " + filename);

    std::string content((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
    file.close();

    T
}

inline void Preprocessor::expand_macro(const Token &token, std::vector<Token> &output)
{
    const auto& replacement = macros[token.value];

    for (const auto& t : replacement) {
        output.push_back(t);
    }
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
