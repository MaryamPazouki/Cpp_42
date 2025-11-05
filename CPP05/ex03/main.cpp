/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpazouki <mpazouki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 11:59:20 by mpazouki          #+#    #+#             */
/*   Updated: 2025/11/05 11:59:21 by mpazouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"
#include "Intern.hpp"
#include <cstdlib>
#include <ctime>


int main() {
    Intern rIntern;
    Bureaucrat boss("HighRank", 1);

    AForm *form;

    form = rIntern.makeForm("shrubbery creation", "garden");
    if (form)
    {
        boss.signForm(*form);
        boss.executeForm(*form);
        delete form;
    }
    std::cout << std::endl ;
    form = rIntern.makeForm("robotomy request", "Bender");
    if(form)
    {
        boss.signForm(*form);
        boss.executeForm(*form);
        delete form;
    }
    std::cout << std::endl ;
    form = rIntern.makeForm("invalid form", "nobody");
    if (!form) {
        std::cout << "Intern failed to create the form." << std::endl;
    }
   
    return 0;
}
