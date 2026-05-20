/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpazouki <mpazouki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 12:01:19 by mpazouki          #+#    #+#             */
/*   Updated: 2026/05/20 09:26:29 by mpazouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

/*int main(){
    try{
        Bureaucrat john("John", 46);
        Form contract("Work contract", 45, 20);

        
        john.signForm(contract);// too low

        john.incrementGrade();
        john.incrementGrade();
        john.signForm(contract);// too low
        john.decrementGrade(); // throws exception
    }
    catch (std::exception & e){
        std::cerr << e.what() << std::endl;
    }
}*/



int main()
{
    std::cout << "=== CPP05 ex01 tests ===" << std::endl;

    try
    {
        std::cout << "\n-- signing checks --" << std::endl;
        Bureaucrat john("John", 46);
        Form contract("Work contract", 45, 20);

        std::cout << john << std::endl;
        std::cout << contract << std::endl;

        john.signForm(contract);

        john.incrementGrade();
        john.signForm(contract);

        std::cout << contract << std::endl;

        Bureaucrat copyJohn(john);
        Form copyContract(contract);

        std::cout << copyJohn << std::endl;
        std::cout << copyContract << std::endl;

        std::cout << "\n-- boundary checks --" << std::endl;
        try
        {
            Bureaucrat tooStrong("TooStrong", 0);
            std::cout << tooStrong << std::endl;
        }
        catch (const std::exception &e)
        {
            std::cout << "Failed to create bureaucrat: " << e.what() << std::endl;
        }

        try
        {
            Bureaucrat tooWeak("TooWeak", 151);
            std::cout << tooWeak << std::endl;
        }
        catch (const std::exception &e)
        {
            std::cout << "Failed to create bureaucrat: " << e.what() << std::endl;
        }

        try
        {
            Form badFormHigh("BadHigh", 0, 10);
            std::cout << badFormHigh << std::endl;
        }
        catch (const std::exception &e)
        {
            std::cout << "Failed to create form: " << e.what() << std::endl;
        }

        try
        {
            Form badFormLow("BadLow", 10, 151);
            std::cout << badFormLow << std::endl;
        }
        catch (const std::exception &e)
        {
            std::cout << "Failed to create form: " << e.what() << std::endl;
        }

        std::cout << "\n-- grade change check --" << std::endl;
        while (true)
            john.decrementGrade(); 
    }
    catch (const std::exception &e)
    {
        std::cout << "Grade change failed: " << e.what() << std::endl;
    }
    return 0;
}