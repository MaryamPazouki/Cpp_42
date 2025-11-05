/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpazouki <mpazouki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 12:05:49 by mpazouki          #+#    #+#             */
/*   Updated: 2025/11/05 12:05:50 by mpazouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern(){
   // std::cout << "Default constructor called" << std::endl;
};
Intern::Intern(const Intern &other){
    (void) other;
};
Intern &Intern::operator = (const Intern &other){
    (void) other;
    return(*this);
};
Intern::~Intern() {};


AForm* Intern::makeForm(std::string const &formName, std::string const &target) const {
    std::string formNames[3] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"
    };

    AForm* forms[3] = {
        new ShrubberyCreationForm(target),
        new RobotomyRequestForm(target),
        new PresidentialPardonForm(target)
    };

    for (int i = 0; i < 3; i++) {
        if (formName == formNames[i]) {
            std::cout << "Intern creates " << formName << std::endl;
            // delete unused forms
            for (int j = 0; j < 3; j++) {
                if (i != j)
                    delete forms[j];
            }
            return forms[i];
        }
    }

    std::cout << "Intern: form name \"" << formName << "\" not found" << std::endl;
    for (int i = 0; i < 3; i++)
        delete forms[i];
    return NULL;
};



/*
//makeForm function in elegant way with c++11, use lambda functions

AForm * Intern::makeForm(std::string const &formName, std::string const &target){
    
    struct FormEntry{
        std::string name;
        AForm* (*create)(const std::string & _target);
    };

    static const FormEntry formTable[] = {
        {"shrubbery creation", [](const std::string &t) -> AForm* {return new ShrubberyCreationForm(t);}},
        { "robotomy request",    [](const std::string &t) -> AForm* { return new RobotomyRequestForm(t); } },
        { "presidential pardon", [](const std::string &t) -> AForm* { return new PresidentialPardonForm(t); } }
    };

    for (size_t i = 0; i< sizeof(formTable)/sizeof(formTable[0]); ++i)
    {
        if (formName == formTable[i].name)
        {
            std::cout << "Intern creates " << formName << std::endl;
            return formTable[i].create(target);
        }
    }
    std::cerr << "Intern: form name \"" << formName << "\" not found" << std::endl;
    return NULL;
} */
