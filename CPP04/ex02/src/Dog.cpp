/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpazouki <mpazouki@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-09-12 08:46:06 by mpazouki          #+#    #+#             */
/*   Updated: 2025-09-12 08:46:06 by mpazouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() {
    this -> type = "Dog";
    this -> brain = new Brain();
    std::cout<< "Dog Constructed!" << std::endl;
};

Dog:: Dog(const Dog &other): Animal(other){
    brain = new Brain(*other.brain); // deep copy
    std::cout<< "Dog copy Constructed!" << std::endl;
}

Dog& Dog::operator = (const Dog&other){
    if (this != &other)
        {
            Animal :: operator=(other);
            delete brain;
            brain = new Brain(*other.brain); // deep copy

        }
   
    std::cout<< "Dog assigned!" << std::endl;
    return (*this);
}

Dog:: ~Dog(){
    delete brain;
    std::cout<< "Dog Destructed!" << std::endl;
}

void Dog::makeSound (void) const {
    std::cout << "Woof!" << std::endl;
}