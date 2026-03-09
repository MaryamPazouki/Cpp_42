#include "RPN.hpp"
#include<iostream>

int main(int ac, char **av){
    if (ac != 2){
         std::cerr << "Error1" << std::endl;
        return 1;
    }
    try {
        RPN rpn;
        int result = rpn.evaluate(av[1]);
        std::cout<< result<< std::endl;

    } 
    catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}