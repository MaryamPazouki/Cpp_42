
#ifndef CONTACT_HPP
#define CONTACT_HPP

#include "header.hpp"

class Contact{
    private:
        std::string firstName;
        std::string lastName;
        std::string nickName;
        std::string phoneNumber;
        std::string secret;
    public:
        Contact();
        ~Contact();

        //Getters and setters
        void setContact(const std::string &firstName,
                        const std::string &lastName,
                        const std::string &nickName,
                        const std::string &phoneNumber,
                        const std::string &secret);
        std::string getFirstName() const;
        std::string getLastName() const;
        std::string getNickName() const;
        std::string getPhoneNumber() const;
        std::string getSecret() const;
        void displayContact() const;
        bool isEmpty() const;
};
#endif