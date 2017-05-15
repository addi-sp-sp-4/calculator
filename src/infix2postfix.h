//
// Created by david on 13-5-17.
//

#ifndef INFIX_TO_POSTFIX_INFIX2POSTFIX_H
#define INFIX_TO_POSTFIX_INFIX2POSTFIX_H


#include <vector>
#include <string>

class Infix2Postfix {

    public:
        Infix2Postfix();
        std::vector<std::string> evaluate(std::vector<std::string> infix);


    private:
        bool isoperand(std::string input);



};


#endif //INFIX_TO_POSTFIX_INFIX2POSTFIX_H
