/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpazouki <mpazouki@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-09-12 08:44:06 by mpazouki          #+#    #+#             */
/*   Updated: 2025-09-12 08:44:06 by mpazouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"


Cat :: Cat() {
    this->type = "Cat";
    std::cout<< "Cat Constructed!" << std::endl;
}

Cat :: Cat(const Cat &other): Animal (other){
    std::cout<< "Cat copy Constructed!" << std::endl;
}

Cat& Cat::operator = (const Cat& other){
    Animal :: operator=(other);
    std::cout<< "Cat assigned!" << std::endl;
    return(*this);
}

Cat :: ~Cat(){
    std::cout<< "Cat destroyed!" << std::endl;
}

void Cat :: makeSound() const {
    std::cout << "Meow!" << std::endl;
}