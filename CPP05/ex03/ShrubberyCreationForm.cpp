/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpazouki <mpazouki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 12:06:26 by mpazouki          #+#    #+#             */
/*   Updated: 2026/05/20 10:33:04 by mpazouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(std::string const & target)
  : AForm("ShrubberyCreationForm", 145, 137), _target(target) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::executeAction() const {
    std::string filename = _target + "_shrubbery";
    std::ofstream ofs(filename.c_str());
    if (!ofs) {
        throw std::runtime_error("Failed to open output file: " + filename);
    }
      ofs
          << "               ,@@@@@@@,\n"
          << "       ,,,.   ,@@@@@@/@@,  .oo8888o.\n"
          << "    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o\n"
          << "   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'\n"
          << "   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'\n"
          << "   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `\\\n"
          << "   `&%\\ ` /%&'    |.|        \\_.-\\\n"
          << "       |o|        | |         | |\n"
          << "       |.|        | |         | |\n"
          << "    \\./   \\./   \\./   \\./   \\./   \\./\n"
          << "     ^     ^     ^     ^     ^     ^\n";
    ofs.close();
}
