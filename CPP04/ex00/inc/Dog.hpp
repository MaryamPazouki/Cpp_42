/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpazouki <mpazouki@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-09-12 08:43:45 by mpazouki          #+#    #+#             */
/*   Updated: 2025-09-12 08:43:45 by mpazouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal{
    
    public:
        Dog();
        Dog(const Dog &other);
        Dog& operator = (const Dog &other);
        ~Dog();
        
        void makeSound()const; //override
};

#endif