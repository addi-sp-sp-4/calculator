//
// Created by david on 13-5-17.
//

#include "infix2postfix.h"
#include <iostream>
#include <stack>
#include <map>

// Empty constructor
Infix2Postfix::Infix2Postfix()
{

}

// Also called the Shunting-yard algorithm: https://en.wikipedia.org/wiki/Shunting-yard_algorithm

std::vector<std::string> Infix2Postfix::evaluate(std::vector<std::string> infix)
{
    std::vector<std::string> postfix;
    std::stack<std::string> operators;
    std::map<std::string, int> precedence;
    std::string buffer = "";


    // Add precedences
    precedence["^"] = 3;
    precedence["*"] = 2;
    precedence["/"] = 2;
    precedence["-"] = 1;
    precedence["+"] = 1;
    precedence["%"] = 2;

    // For every char in infix
    for(unsigned i = 0; i < infix.size(); i++)
    {
        // Convert char to string
        std::string current_char = infix[i];


        // If current char is operand

        if(isoperand(current_char))
        {

            postfix.push_back(current_char);

        }


        // Else, if operators is either empty or the precedence of the current character is higher than the precedence of
        // the topmost character of operators, OR current char is (: push current char to operators
        else if(operators.empty()
                || precedence[operators.top()] < precedence[current_char]
                || current_char == "(")
        {

            operators.push(current_char);
        }

        // If current char = ): Until operators.top equals ( pop operators onto postfix

        else if(current_char == ")")
        {

            while(operators.top() != "(")
            {

                postfix.push_back(operators.top());

                operators.pop();

            }

            operators.pop();

        }
        // Else
        else
        {

            // Loop until broken
            while(true)
            {
                // If the precedence of the topmost character of operators is higher than OR equal to the precedence of
                // The current char: add topmost value of operators to postfix and pop operators
                if(precedence[operators.top()] >= precedence[current_char])
                {

                    postfix.push_back(operators.top());

                    operators.pop();

                    // If operators is empty: push current char to operators and break the loop;
                    if(operators.empty())
                    {

                        operators.push(current_char);
                        break;
                    }
                }

                // Else push current char to operators and break the loop
                else
                {

                    operators.push(current_char);
                    break;
                }
            }
        }


    }

    // Add every character still in operators to postfix

    while(!operators.empty())
    {
        postfix.push_back(operators.top());
        operators.pop();
    }
    //Return postfix
    return postfix;
}

bool Infix2Postfix::isoperand(std::string input)
{
    std::string validchars = "0123456789.-";

    // If only validchats in input and input is not just a -: return true
    return (input.find_first_not_of(validchars) == std::string::npos) && input != "-";
}
