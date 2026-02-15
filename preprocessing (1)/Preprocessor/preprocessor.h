#pragma once
#include <string>
#include <vector>
#include <unorder_map>
#include <stack>

class Preprocessor {
private:
    remove_comments();
    //Postcondition: Removes comments
    handle_includes();
    //Postcondition: Handles statements such as #include
    expand_macros();
    //Postcondition: Handles object like macros such as #define NAME value
    evaluate_conditionals();
    //Postcondition: Evaluates conditionals
    run();
}