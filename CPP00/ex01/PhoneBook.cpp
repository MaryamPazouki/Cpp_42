/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpazouki <mpazouki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 20:44:28 by mpazouki          #+#    #+#             */
/*   Updated: 2025/09/01 21:06:52 by mpazouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "header.hpp"

PhoneBook::PhoneBook()
{
    this -> contactCount = 0;
    this -> _index = 0;
}

PhoneBook :: ~PhoneBook()
{
}

static std::string truncate(const std::string &str)
{
    if (str.length()> 10)
        return str.substr(0 , 9) + ".";
    return str;
}

void PhoneBook::storeContact(const std::string& firstName, const std::string& lastName,
                             const std::string& nickName, const std::string& phoneNumber,
                             const std::string& secret) {
{
    contacts[_index].setContact(firstName,lastName,nickName, phoneNumber,secret);
    _index = (_index +1) % 8;
    if (contactCount < 8)
        contactCount ++;
}
}

void PhoneBook::addContact()
{
    std::string firstName, lastName,nickName,phoneNumber, secret;
    
    std::cout << BLUE <<"Enter First Name: "<< RESET ;
    std::getline(std::cin, firstName);
    std::cout << BLUE <<"Enter Last Name: "<< RESET;
    std::getline(std::cin, lastName);
    std::cout << BLUE <<"Enter Nickname: "<< RESET;
    std::getline(std::cin, nickName);
    std::cout << BLUE <<"Enter Phone Number: "<< RESET;
    std::getline(std::cin, phoneNumber);
    std::cout << BLUE <<"Enter Darkest Secret: "<< RESET;
    std::getline(std::cin, secret);

    if (firstName.empty() || lastName.empty() || nickName.empty() 
        || phoneNumber.empty() || secret.empty()){
            std::cout << RED << "All fields must be non-empty"<< RESET << std::endl;
        return;
        }
    
    storeContact(firstName, lastName, nickName, phoneNumber, secret);
    std::cout << YELLOW << "Contact added" << RESET << std::endl;
}

void PhoneBook :: displayContacts() const {

    std::cout << std::setw(10) << "Index"<<  "|"
            << std::setw(10) << "First Name"<< "|"
            << std::setw(10) << "Last Name"<< "|"
            << std::setw(10) << "Nickname" << std::endl;

    for (int i = 0; i < this->contactCount; ++i) {
        std::cout << std::setw(10) << i << "|"
                  << std::setw(10) << truncate(this->contacts[i].getFirstName()) << "|"
                  << std::setw(10) << truncate(this->contacts[i].getLastName()) << "|"
                  << std::setw(10) << truncate(this->contacts[i].getNickName()) << std::endl;
    }
}

void PhoneBook :: promptandShowDetails() const {

    std::cout << BLUE << "Enter index to view details: " << RESET;
    std::string input;
    std::getline(std::cin, input);
    std::istringstream iss(input);
    int index;
    if (!(iss >> index) || index < 0 || index >= this->contactCount) {
        std::cout << RED << "Invalid index." << RESET << std::endl;
        return;
    }

    this->contacts[index].displayContact();

}

void PhoneBook::searchContacts() const {
    if (this-> contactCount == 0)
    {
        std::cout << RED << "No Contacts to display!"<< RESET << std::endl;
        return;
    }
    
    displayContacts();
    promptandShowDetails();
}



