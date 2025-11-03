#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <string>

class RobotomyRequestForm : AForm{
    private:
        std::string _target;
    public: 
        RobotomyRequestForm(std::string const & target);
        virtual ~RobotomyRequestForm(){};
        virtual void executeAction() const;
};

#endif
