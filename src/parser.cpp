//
// Created by david on 15-5-17.
//


#include "parser.h"


#include <algorithm>
#include <iostream>
// Empty constructor
Parser::Parser()
{

}

std::vector<std::string> Parser::parse(std::string unparsed, bool &failed)
{
    failed = false;

    std::vector<std::string> parsed;

    std::string buffer;

    // Strip spaces from unparsed
    unparsed = stripspaces(unparsed);
    std::string returnment;
    if(!isvalidated(unparsed, returnment))
    {
        failed = true;
        // Ugly
        parsed = {returnment};
        return parsed;
    }

    for(unsigned i = 0; i < unparsed.length(); i++)
    {
        std::string current_char(1, unparsed[i]);

        // If current char is a digit
        if(isdigit(unparsed[i]) || (i == 0 && current_char == "-"))
        {
            buffer += current_char;
        }

        else if(buffer.length() > 0 && current_char == ".")
        {
            buffer += current_char;
        }

        else if(buffer.length() == 0 &&
                current_char == "-" &&
                isdigit(unparsed[i + 1]) &&
                !isdigit(unparsed[i - 1]) &&
                unparsed[i - 1] != ')')
        {

                buffer += current_char;

        }

        // Is not number
        else
        {

            // If first char is operator; exit
            if(i == 0 && isoperator(unparsed[i]))
            {
                failed = true;

                parsed = {"Operator mismatch"};
                return parsed;
            }

            // If two operators after eachother
            if(isoperator(unparsed[i]) && isoperator(unparsed[i+1]) && unparsed[i +1] != '-')
            {
                failed = true;

                parsed = {"Operator mismatch"};
                return parsed;
            }


            // add numbers to parsed
            if(buffer.size() != 0)
            {
                parsed.push_back(buffer);
                buffer.clear();
            }

            parsed.push_back(current_char);
        }

    }
    if(buffer.empty() && parsed.back() != ")")
    {
        failed = true;

        parsed = {"Operator mismatch"};
        return parsed;
    }
    if(!buffer.empty())
    {
        parsed.push_back(buffer);
    }

    return parsed;



}

// Does what the name says
std::string Parser::stripspaces(std::string input)
{
    std::string buffer;
    for(unsigned i = 0; i < input.length(); i++)
    {
        if(input[i] != ' ') buffer += input[i];
    }
    return buffer;
}


bool Parser::isvalidated(std::string input, std::string &message)
{

    std::string validchars = "0123456789.^*/%+-()";

    // If input consists only of validchars;
    if (input == "")
    {

        message = "Empty input";
        return false;

    }
    if (input.find_first_not_of(validchars) != std::string::npos)
    {
        message = "Invalid characters in input!";
        return false;
    }
    // Count of ('s and )'s
    int left_parenthese_count = (int) std::count(input.begin(), input.end(), '(');
    int right_parenthese_count = (int) std::count(input.begin(), input.end(), ')');

    if (left_parenthese_count != right_parenthese_count)
    {
        message = "Amount of '('s doesn't match amount of ')'s";
        return false;
    }

    // Return false
    for(unsigned i = 0; i < input.size(); i++)
    {
        if(input[i] == '(')
        {
            if(input[i+1] == ')')
            {
                message = "Empty parentheses";
                return false;
            }
        }
    }

    return true;
}

bool Parser::isoperator(char input)
{
    return !isdigit(input) && input != '(' && input != ')';
}
