#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "header.hpp"
#include "Contact.hpp"

class PhoneBook {
    private:
        Contact contacts[8];
        int contactCount;
        int _index;

        /* void displayTableHeader() const;
        void displayContactPreview(int index) const;
        std::string formatField(const std::string &str) const; */

    public:
        PhoneBook();
        ~PhoneBook();

        void addContact();
        void searchContacts() const;
};

#endif



