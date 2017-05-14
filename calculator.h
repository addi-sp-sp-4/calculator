//
// Created by david on 14-5-17.
//

#ifndef CALCULATOR_CALCULATOR_H
#define CALCULATOR_CALCULATOR_H

#include <string>
#include "infix2postfix.h"
#include "postfixeval.h"

class Calculator
{
    public:
        Calculator();
        std::string evaluate(std::string input);

    private:
        std::string stripspaces(const std::string input);
        bool checkparentheses(const std::string input);
        bool validateinput(std::string input);
        Infix2Postfix *infix;
        PostfixEval *result;



};


#endif //CALCULATOR_CALCULATOR_H
