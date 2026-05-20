/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpazouki <mpazouki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 12:05:49 by mpazouki          #+#    #+#             */
/*   Updated: 2026/05/20 10:31:11 by mpazouki         ###   ########.fr       */
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

// helper creator functions
static AForm* createShrubbery(const std::string &target) {
    return new ShrubberyCreationForm(target);
}
static AForm* createRobotomy(const std::string &target) {
    return new RobotomyRequestForm(target);
}
static AForm* createPresidential(const std::string &target) {
    return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(std::string const &formName, std::string const &target) const {
    std::string forms[3] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"
    };
    //array of function pointers to the creator functions
    // the function pointer type is AForm* (*)(const std::string &)
    // this means a pointer to a function that takes a const std::string & and returns an AForm*
    // the array is initialized with the addresses of the creator functions
    // the constructors array allows us to call the appropriate creator function based on the form name
    
    AForm* (*constructors[3])(const std::string &) = {
        &createShrubbery,
        &createRobotomy,
        &createPresidential
    };

    for (int i = 0; i < 3; i++) {
        if (formName == forms[i]) {
            std::cout << "Intern creates " << formName << std::endl;
            return constructors[i](target);
        }
    }

    std::cout << "Intern: form name \"" << formName << "\" not found" << std::endl;
    return NULL;
}





/* AForm* Intern::makeForm(std::string const &formName, std::string const &target) const {
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

 */




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
