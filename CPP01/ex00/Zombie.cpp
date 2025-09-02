/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpazouki <mpazouki@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-09-02 10:36:23 by mpazouki          #+#    #+#             */
/*   Updated: 2025-09-02 10:36:23 by mpazouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.hpp"

Zombie::Zombie(const std::string& name) : name(name){}

Zombie::~Zombie(){
    std::cout << this->name << RED <<" is destroyed." << RESET << std::endl;
}

void Zombie::announce() const {
    std::cout << this->name << GREEN << ": BraiiiiiiinnnzzzZ..." << RESET << std::endl;
}

std::string Zombie::getName()
{
    return this->name;
}
