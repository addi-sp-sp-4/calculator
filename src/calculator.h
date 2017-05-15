//
// Created by david on 14-5-17.
//

#ifndef CALCULATOR_CALCULATOR_H
#define CALCULATOR_CALCULATOR_H

#include <string>

#include "parser.h"
#include "infix2postfix.h"
#include "postfixeval.h"

class Calculator
{
    public:
        Calculator();
        std::string evaluate(std::string input);

    private:
        Infix2Postfix *infix;
        PostfixEval *result;
        Parser *parser;

};


#endif //CALCULATOR_CALCULATOR_H
