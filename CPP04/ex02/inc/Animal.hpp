/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpazouki <mpazouki@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-09-12 08:45:29 by mpazouki          #+#    #+#             */
/*   Updated: 2025-09-12 08:45:29 by mpazouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include<string>
#include<iostream>

class Animal{
    protected:
        std::string type;

    public:
        Animal();
        Animal(const Animal &other);
        Animal &operator = (const Animal &other);
        virtual ~Animal();
        
        const std::string& getType(void) const;
        
        // pure virtual function = Abstract class
        virtual void makeSound() const = 0; 
        
};

#endif