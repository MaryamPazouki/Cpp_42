/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpazouki <mpazouki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 12:04:01 by mpazouki          #+#    #+#             */
/*   Updated: 2025/11/05 12:04:02 by mpazouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


// ShrubberyCreationForm.cpp
#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(std::string const & target)
  : AForm("ShrubberyCreationForm", 145, 137), _target(target) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::executeAction() const {
    std::string filename = _target + "_shrubbery";
    std::ofstream ofs(filename.c_str());
    if (!ofs) {
        // optionally throw an exception or print an error
        return;
    }
    ofs << "   ccee88oo\n  C8O8O8Q8PoOb o8oo\n ...\n"; // ASCII trees, repeat as you like
    ofs.close();
}
