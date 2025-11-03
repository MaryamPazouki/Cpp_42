#include "RobotomyRequestForm.hpp"
#include <iostream>
#include <cstdlib> // std::rand
#include <ctime>   // if you seed in main

RobotomyRequestForm::RobotomyRequestForm(std::string const &target)
    : AForm("RobotomyRequestForm", 72, 45), _target(target){}

RobotomyRequestForm::~RobotomyRequestForm(){}

void RobotomyRequestForm::executeAction() const {
    std::cout << "Brrrr... zzzrrr... drilling noises..." << std::endl;
    if (std::rand() % 2) {
        std::cout << _target << " has been robotomized successfully." << std::endl;
    } else {
        std::cout << "Robotomy failed on " << _target << "." << std::endl;
    }
}