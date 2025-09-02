/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpazouki <mpazouki@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-09-02 10:37:45 by mpazouki          #+#    #+#             */
/*   Updated: 2025-09-02 10:37:45 by mpazouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.hpp"

HumanB::HumanB(const std::string& name) : weapon(NULL), name(name){}

void HumanB::setWeapon(Weapon& newWeapon){
    weapon = &newWeapon;
}

void HumanB::attack() const{
    if (weapon)
        std::cout << GREEN << name << RESET " attacks with their " << weapon->getType() << std::endl;
    else 
        std::cout << GREEN << name << RESET << RED << " has no weapon to attack with." << RESET << std::endl;
}