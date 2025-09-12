/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpazouki <mpazouki@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-09-12 08:44:29 by mpazouki          #+#    #+#             */
/*   Updated: 2025-09-12 08:44:29 by mpazouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat :: WrongCat() {
    this-> type = "WrongCat";
    std::cout<< "WrongCat Constructed!" << std::endl;
}

WrongCat :: WrongCat(WrongCat &other): WrongAnimal(other){
    std::cout<< "Cat copy Constructed!" << std::endl;
}

WrongCat&  WrongCat ::operator=(WrongCat &other){
    WrongAnimal :: operator=(other);
    std::cout<< "Cat assigned!" << std::endl;
    return(*this);
}

WrongCat :: ~WrongCat(){
    std::cout<< "Cat destroyed!" << std::endl;
}

void WrongCat::makesound() const{
            std::cout << "Wrong Meow!" << std::endl;
        }