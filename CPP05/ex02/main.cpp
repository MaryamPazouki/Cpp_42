/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpazouki <mpazouki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 12:03:35 by mpazouki          #+#    #+#             */
/*   Updated: 2025/11/05 12:03:36 by mpazouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <cstdlib>
#include <ctime>

/* int main() {
    try {
        Bureaucrat alice("Alice", 1); // super high rank
        ShrubberyCreationForm form("home");

        alice.signForm(form);      // Alice signs the form
        alice.executeForm(form);   // Alice executes the form (creates a file)
    }
    catch (std::exception & e) {
        std::cerr << e.what() << std::endl;
    }
} */

int main() {
    std::srand(std::time(NULL)); // seed rand once

    Bureaucrat high("HighRank", 1);
    Bureaucrat mid("MidRank", 50);
    Bureaucrat low("LowRank", 150);

    ShrubberyCreationForm shrub("home");
    RobotomyRequestForm robo("Bender");
    PresidentialPardonForm pres("Ford Prefect");

    // try to execute unsigned form
    mid.executeForm(shrub); // should say couldn't execute: Form not signed!

    // sign forms with appropriate bureaucrats
    high.signForm(shrub);
    high.signForm(robo);
    high.signForm(pres);

    // execute
    high.executeForm(shrub); // creates file home_shrubbery
    high.executeForm(robo);  // 50% success message
    high.executeForm(pres);  // pardoned

    // demonstration of insufficient grade
    low.signForm(shrub);
    low.executeForm(shrub); // couldn't execute because grade too low (or form not signed)
    return 0;
}
