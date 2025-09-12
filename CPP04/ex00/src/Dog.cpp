/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpazouki <mpazouki@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-09-12 08:44:12 by mpazouki          #+#    #+#             */
/*   Updated: 2025-09-12 08:44:12 by mpazouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() {
    this->type ="Dog";
    std::cout<< "Dog Constructed!" << std::endl;
};

Dog:: Dog(const Dog &other): Animal(other){
    std::cout<< "Dog copy Constructed!" << std::endl;
}

Dog& Dog::operator = (const Dog&other){
   Animal :: operator=(other);
    std::cout<< "Dog assigned!" << std::endl;
    return (*this);
}

Dog:: ~Dog(){
    std::cout<< "Dog Destructed!" << std::endl;
}

void Dog::makeSound (void) const {
    std::cout << "Woof!" << std::endl;
}