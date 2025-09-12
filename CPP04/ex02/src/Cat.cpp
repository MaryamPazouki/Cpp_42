/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpazouki <mpazouki@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-09-12 08:46:02 by mpazouki          #+#    #+#             */
/*   Updated: 2025-09-12 08:46:02 by mpazouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"



Cat :: Cat() {
    this->type = "Cat"; 
    brain = new Brain(); //allocate a new brain obj on the heap
    std::cout<< "Cat Constructed with new Brain!" << std::endl;
}

Cat :: Cat(const Cat &other): Animal (other){
    brain = new Brain(*other.brain); // deep copy
    std::cout<< "Cat copy Constructed!" << std::endl;
}

Cat& Cat::operator = (const Cat& other){
    if (this != &other){
        Animal :: operator=(other);
        delete brain;
        brain = new Brain(*other.brain); // deep copy
    }
    
    std::cout<< "Cat assigned!" << std::endl;
    return(*this);
}

Cat :: ~Cat(){
    delete this-> brain;
    std::cout<< "Cat destroyed!" << std::endl;
}

void Cat :: makeSound() const {
    std::cout << "Meow!" << std::endl;
}