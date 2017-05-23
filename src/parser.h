//
// Created by david on 15-5-17.
//

#ifndef CALCULATOR_PARSER_H
#define CALCULATOR_PARSER_H

#include <vector>
#include <string>

class Parser
{
    public:
        Parser();
        std::vector<std::string> parse(std::string unparsed, bool &failed);
    private:
        std::string stripspaces(std::string input);
        bool isvalidated(std::string input, std::string &message);
        bool isoperator(char input);


};


#endif //CALCULATOR_PARSER_H
