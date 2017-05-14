//
// Created by david on 14-5-17.
//

#include "calculator.h"

#include <algorithm>
#include <iostream>

Calculator::Calculator()
{
    infix = new Infix2Postfix;
    result = new PostfixEval;
}

std::string Calculator::evaluate(std::string input)
{

    // Strip spaces from input
    input = stripspaces(input);

    // Return if input is empty
    if(input.empty())
    {
        return "Empty input!";
    }

    // Return if input isn't validated
    if(!validateinput(input))
    {
        return "Invalid input!";
    }

    // Return if non-even amount of parentheses
    if(!checkparentheses(input))
    {
        return "Parentheses mismatch!";
    }

    std::vector<std::string> postfix = infix->evaluate(input);


    // Debugging block; uncomment to get postfix string


    for(unsigned i = 0; i < postfix.size(); i++)
    {
        std::cout << postfix[i] << ",";
    }
    std::cout << std::endl;


    return result->evaluate(postfix);

}

std::string Calculator::stripspaces(const std::string input)
{

    std::string buffer;
    for(unsigned i = 0; i < input.length(); i++)
    {
        if(input[i] != ' ') buffer += input[i];
    }
    return buffer;

}

bool Calculator::checkparentheses(const std::string input)
{
    int left_parenthese_count = (int)std::count(input.begin(), input.end(), '(');
    int right_parenthese_count = (int)std::count(input.begin(), input.end(), ')');
    bool val = left_parenthese_count == right_parenthese_count;

    return val;

}

bool Calculator::validateinput(std::string input)
{
    // Return false if
    return input.find_first_not_of("0123456789.^*/%+-()") == std::string::npos;
}
