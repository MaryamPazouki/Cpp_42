
#include "Contact.hpp"
#include <iostream>

Contact::Contact() {
    // Default constructor initializes an empty contact
    firstName = "";
    lastName = "";
    nickName = "";
    phoneNumber = "";
    darkestSecret = "";
    std::cout<< "Contact created." << std::endl;
}

void Contact::setContact(const std::string &firstName,
                         const std::string &lastName,
                         const std::string &nickName,
                         const std::string &phoneNumber,
                         const std::string &darkestSecret) {
    this->firstName = firstName;
    this->lastName = lastName;
    this->nickName = nickName;
    this->phoneNumber = phoneNumber;
    this->darkestSecret = darkestSecret;
}


std::string Contact::getFirstName() const {
    return firstName;
}

std::string Contact::getLastName() const {
    return lastName;
}

std::string Contact::getNickname() const {
    return nickName;
}

void Contact::displayContact() const {
    std::cout << "First Name: " << firstName << std::endl;
    std::cout << "Last Name: " << lastName << std::endl;
    std::cout << "Nickname: " << nickName << std::endl;
    std::cout << "Phone Number: " << phoneNumber << std::endl;
    std::cout << "Darkest Secret: " << darkestSecret << std::endl;
}

bool Contact::isEmpty() const {
    return firstName.empty(); // simple check for empty contact
}
