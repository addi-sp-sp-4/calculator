//
// Created by david on 13-5-17.
//

#include "postfixeval.h"


#include <stack>
#include <map>
#include <iostream>
#include <cmath>

// Empty constructor
PostfixEval::PostfixEval()
{

}


std::string PostfixEval::evaluate(std::vector<std::string> postfix)
{
    std::stack<std::string> operands;


    // For every char in postfix
    for(unsigned i = 0; i < postfix.size(); i++)
    {
        //Make the char a std::string

        std::string current_char = postfix[i];

        // If current char is a digit: push current char to operands
        // The if statement is a check for if the string is a number
        // Also check if current char isn't just -
        if(current_char.find_first_not_of("0123456789.-") == std::string::npos && current_char != "-")
        {
            operands.push(current_char);

        }

        // Else (current char is an operator)
        else
        {
            std::cout ;
            // Get the two topmost chars from operands and store them in x and y respectively
            // Remember: the stack always has at least 2 numbers in it (1 when finished though!), so no need to check
            // for that

            std::string x = operands.top();
            operands.pop();
            std::string y = operands.top();
            operands.pop();

            // Calculate x (current_char) y and put it in result
            // y before x, because we're getting those variables from operands reserved
            std::string result = calculate(current_char, y, x);

            // Push result
            operands.push(result);


        }
    }
    // Return float of evaluated value

    std::string return_val = operands.top();

    return return_val;
}

std::string PostfixEval::calculate(std::string oper, std::string x, std::string y)
{

    double _x = std::stod(x);
    double _y = std::stod(y);
    double _z;

    // Evaluate different possibilities
    if(oper == "*") _z = _x * _y;
    else if(oper == "/") _z = _x / _y;
    else if(oper == "+") _z = _x + _y;
    else if(oper == "-") _z = _x - _y;

    
    else if(oper == "%") _z = fmod(_x, _y);
    else if(oper == "^") _z = pow(_x, _y);

    // Return correct string
    std::string returnval = std::to_string(_z);

    return returnval;

}
