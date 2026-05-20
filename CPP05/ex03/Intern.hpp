/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpazouki <mpazouki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 12:05:55 by mpazouki          #+#    #+#             */
/*   Updated: 2026/05/20 10:01:40 by mpazouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

# include <string>
# include <iostream>
# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class Intern{
    public:
        Intern();
        Intern(const Intern &other);
        Intern &operator= (const Intern &other);
        ~Intern();
        
        // makeForm Function
        AForm* makeForm(std::string const  &formname, std::string const &target) const;
};


#endif