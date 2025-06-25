
#include "header.hpp"


Contact::Contact() {
    // Default constructor initializes an empty contact
    firstName = "";
    lastName = "";
    nickName = "";
    phoneNumber = "";
    secret = "";
    //std::cout<< "Contact created." << std::endl;
}

Contact::~Contact()
{
}

void Contact::setContact(const std::string &firstName,
                         const std::string &lastName,
                         const std::string &nickName,
                         const std::string &phoneNumber,
                         const std::string &secret) {
    this->firstName = firstName;
    this->lastName = lastName;
    this->nickName = nickName;
    this->phoneNumber = phoneNumber;
    this->secret = secret;
}


std::string Contact::getFirstName() const {
    return firstName;
}

std::string Contact::getLastName() const {
    return lastName;
}

std::string Contact::getNickName() const {
    return nickName;
}

std::string Contact::getPhoneNumber()  const {
    return phoneNumber;
}

std::string Contact::getSecret() const 
{
    return secret;
}


void Contact::displayContact() const {
    std::cout << GREEN <<"First Name: " << RESET << firstName  << std::endl;
    std::cout << GREEN << "Last Name: " << RESET << lastName <<std::endl;
    std::cout << GREEN <<"Nickname: " << RESET << nickName <<std::endl;
    std::cout << GREEN <<"Phone Number: " << RESET << phoneNumber <<std::endl;
    std::cout << GREEN <<"Secret: " << RESET << secret <<std::endl;
}

bool Contact::isEmpty() const {
    return firstName.empty(); // simple check for empty contact
}
