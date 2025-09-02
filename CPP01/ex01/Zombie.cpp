/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpazouki <mpazouki@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-09-02 10:36:54 by mpazouki          #+#    #+#             */
/*   Updated: 2025-09-02 10:36:54 by mpazouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "header.hpp"

Zombie::Zombie() {
    std::cout << GREEN << "Zombie constructed" << RESET << std::endl; 
}

Zombie:: ~Zombie(){
    std::cout<< RED << this ->name << " is destroyed" << RESET <<std::endl;
}
  
void Zombie::announce() const {
    std::cout<< BLUE << ": BraiiiiiiinnnzzzZ..." << RESET << std::endl; 
}

void Zombie::setName (std::string name){
    this -> name = name;
}
