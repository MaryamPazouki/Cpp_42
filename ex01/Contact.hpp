
#ifndef CONTACT_HPP
#define CONTACT_HPP

#include "header.hpp"

class Contact{
private:
    std::string firstName;
    std::string lastName;
    std::string nickName;
    std::string phoneNumber;
    std::string darkestSecret;
public:
    Contact();

    void setContact(const std::string &firstName,
                    const std::string &lastName,
                    const std::string &nickname,
                    const std::string &phoneNumber,
                    const std::string &darkestSecret);
    std::string getFirstName() const;
    std::string getLastName() const;
    std::string getNickname() const;
    void displayContact() const;
    bool isEmpty() const;

};
#endif