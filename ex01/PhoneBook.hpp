#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook {
private:
    Contact contacts[8];
    int totalContacts;
    int nextIndex;

    void displayTableHeader() const;
    void displayContactPreview(int index) const;
    std::string formatField(const std::string &str) const;

public:
    PhoneBook();

    void addContact();
    void searchContacts() const;
};

#endif



