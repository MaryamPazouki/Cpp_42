
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpazouki <mpazouki@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-09-03 07:40:46 by mpazouki          #+#    #+#             */
/*   Updated: 2025-09-03 07:40:46 by mpazouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(const std::string &name) 
    : ClapTrap(name)   // call base constructor
{
    this->hitPoints = 100;
    this->energyPoints= 50;
    this->attackDamage = 20;

    std::cout << "ScavTrap " << this->_Name << " constructed! "
              << "It has " << this->energyPoints << " energy points and " 
              << this->hitPoints << " hit points." << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other){
    std::cout << "ScavTrap copy constructor called for " 
              << other._Name << std::endl;
}

ScavTrap& ScavTrap::operator = (const ScavTrap &other){
    ClapTrap::operator=(other);
    std::cout << "ScavTrap assignment operator called!" << std::endl;
    return *this;
}
ScavTrap :: ~ScavTrap(){
    std::cout << "ScavTrap " << this->_Name << " destroyed!" << std::endl;
}

void ScavTrap::attack(const std::string &target){
    if (this->hitPoints <= 0 || this -> energyPoints <= 0) {
        std::cout << "ClapTrap " << this->_Name << " cannot attack (no HP or energy left)!\n";
        return;
    }
    this-> energyPoints --;
    std::cout << "ClapTrap " << this->_Name << " attacks " << target 
                <<  ", causing " << this -> attackDamage
                << " points of damage!" << std::endl;
}

void ScavTrap::guardGate(){
    std::cout << "ScavTrap " << this->_Name << " is now in Gatekeeper mode!" << std::endl;
}
