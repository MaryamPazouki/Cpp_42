/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpazouki <mpazouki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 20:44:03 by mpazouki          #+#    #+#             */
/*   Updated: 2025/09/01 20:44:07 by mpazouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.hpp"

int main() {
    PhoneBook phoneBook;
    std::string command;

    std::cout << MAGENTA <<"Welcome to the PhoneBook!" << RESET << std::endl;

    while (true) {
        std::cout << BLUE << "Enter command (ADD, SEARCH, EXIT): " << RESET;
        std::getline(std::cin, command);

        if (std::cin.eof())
            break;
        if (command == "ADD")
            phoneBook.addContact();
        else if (command == "SEARCH")
            phoneBook.searchContacts();
        else if (command == "EXIT")
            break;
        else
            std::cout << RED << "Unknown command." << RESET << std::endl;
    }

    std::cout << MAGENTA << "Goodbye!" << RESET << std::endl;
    return 0;
}
