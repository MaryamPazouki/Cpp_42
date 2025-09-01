/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpazouki <mpazouki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 20:44:34 by mpazouki          #+#    #+#             */
/*   Updated: 2025/09/01 20:44:35 by mpazouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "header.hpp"
#include "Contact.hpp"

class PhoneBook {
    private:
        Contact contacts[8];
        int contactCount;
        int _index;
        void storeContact(const std::string &firstName,
                        const std::string &lastName,
                        const std::string &nickName,
                        const std::string &phoneNumber,
                        const std::string &secret);
        void promptandShowDetails() const;

    public:
        PhoneBook();
        ~PhoneBook();
        void addContact();
        void searchContacts() const;
        void displayContacts() const;
        
};

#endif



