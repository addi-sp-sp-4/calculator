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
    parser = new Parser;
}

std::string Calculator::evaluate(std::string input)
{

    std::vector<std::string> parsed = parser->parse(input);

    // Return if parsing failed
    if(parsed[0] == "Operator Mismatch" || parsed[0] == "Empty input" || parsed[0] == "Invalid characters in input!" || parsed[0] == "Amount of '('s doesn't match amount of ')'s")
    {
        return parsed[0];
    }

    std::vector<std::string> postfix = infix->evaluate(parsed);
    
    return result->evaluate(postfix);


}

