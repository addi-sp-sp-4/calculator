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

std::vector<std::string> Infix2Postfix::evaluate(std::string infix)
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
    for(unsigned i = 0; i < infix.length(); i++)
    {
        // Convert char to string
        std::string current_char(1, infix[i]);
        std::vector<std::string>a = postfix;

        // If current char is a digit OR current char = . and buffer length is higher than
        // or equal to 1: Add current char to buffer
        if(
              (isdigit(infix[i])
           || (current_char == "." && buffer.length() >= 1)
              )
          )
        {

            buffer += current_char;
        }

        // Else, if operators is either empty or the precedence of the current character is higher than the precedence of
        // the topmost character of operators, OR current char is (: push current char to operators
        else if(operators.empty()
                || precedence[operators.top()] < precedence[current_char]
                || current_char == "(")
        {
            // If buffer is not empty: add buffer to postfix and clear buffer
            if(!buffer.empty())
            {
                postfix.push_back(buffer);
                buffer = "";

            }

            operators.push(current_char);
        }

        // If current char = ): Until operators.top equals ( pop operators onto postfix
        // If no ( gets found return a
        else if(current_char == ")")
        {
            if(!buffer.empty())
            {
                postfix.push_back(buffer);
                buffer = "";

            }

            while(operators.top() != "(")
            {

                postfix.push_back(operators.top());
                operators.pop();
                if(operators.empty())
                {

                    break;
                }

            }

            operators.pop();


        }
        // Else
        else
        {
            // If buffer is not empty: add buffer to postfix and clear buffer
            if(!buffer.empty())
            {
                postfix.push_back(buffer);
                buffer = "";

            }

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

    // Add every character still in buffer and operators to postfix

    if(buffer.length() > 0)
    {
        postfix.push_back(buffer);
    }
    while(!operators.empty())
    {
        postfix.push_back(operators.top());
        operators.pop();
    }
    //Return postfix
    return postfix;
}

void Infix2Postfix::example()
{
    std::array<std::string, 5> infixes = {"5+6", "5*6-3", "90+4*7/6", "4-57-6-7", "4*56*4*0*9"};

    // Print every infix from infixes and the postfix result
    for(unsigned i = 0; i < infixes.size(); i++)
    {
        std::vector<std::string> result = evaluate(infixes[i]);


        for(unsigned j = 0; j < result.size(); j++)
        {
             std::cout << result[j] << ',' ;
        }
        std::cout << std::endl;
    }
}
