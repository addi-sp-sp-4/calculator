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
    bool failed;
    std::vector<std::string> parsed = parser->parse(input, failed);

    // Return if parsing failed
    if(failed)
    {
        return parsed[0];
    }

    std::vector<std::string> postfix = infix->evaluate(parsed);

    return result->evaluate(postfix);


}

