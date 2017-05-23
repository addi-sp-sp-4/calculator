#include "calculator.h"
#include <iostream>

int main(int argc, char *argv[])
{
    Calculator *calculator = new Calculator;
    std::string input;

    // If command line arg(s) supplied
    if(argc > 1)
    {
        // For every arg, calculate it and cout it
        for(unsigned i = 1; i < argc; i++)
        {
            std::string outcome = calculator->evaluate(argv[i]);
            std::cout << outcome << std::endl;
        }
    }

    // Else
    else
    {
        std::cout << "David's calculator:" << std::endl << std::endl;
        // Unless either quit, q, or exit is typed, ask for input and calculate the input, then cout it.
        while (true)
        {


            std::getline(std::cin, input);

            if(input == "quit" || input == "q" || input == "exit")
            {
                return 0;
            }
            std::string outcome = calculator->evaluate(input);
            std::cout << outcome << std::endl;
        }
    }
    return 0;

}