//
// Created by david on 13-5-17.
//

#ifndef CALCULATOR_POSTFIXEVAL_H
#define CALCULATOR_POSTFIXEVAL_H

#include <string>
#include <vector>

class PostfixEval
{
    public:
        PostfixEval();
        std::string evaluate(std::vector<std::string> postfix);
    private:
        std::string calculate(std::string oper, std::string x, std::string y);




};


#endif //CALCULATOR_POSTFIXEVAL_H
