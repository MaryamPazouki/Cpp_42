/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpazouki <mpazouki@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-09-03 07:41:12 by mpazouki          #+#    #+#             */
/*   Updated: 2025-09-03 07:41:12 by mpazouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include <iostream>

DiamondTrap::DiamondTrap(const std::string &name)
    : ClapTrap(name + "_clap_name"), ScavTrap(name),
      FragTrap(name), _Name(name)
{
    // set stats explicitly from FragTrap & ScavTrap rules
    this->hitPoints = FragTrap::hitPoints;      // 100
    this->energyPoints = ScavTrap::energyPoints; // 50
    this->attackDamage = FragTrap::attackDamage; // 30

    std::cout << "DiamondTrap " << this->_Name << " constructed! "
              << "It has " << this->hitPoints << " HP, "
              << this->energyPoints << " EP, "
              << "and " << this->attackDamage << " AD." << std::endl;
}

DiamondTrap ::DiamondTrap(const DiamondTrap &other)
    : ClapTrap(other), ScavTrap(other), FragTrap(other), _Name(other._Name)
{
    std::cout << "DiamondTrap copy constructor called for "
              << other._Name << std::endl;
}

DiamondTrap &DiamondTrap ::operator=(const DiamondTrap &other)
{
    if (this != &other)
    {
        ClapTrap::operator=(other);
        this->_Name = other._Name;
    }
    std::cout << "DiamondTrap assignment operator called!" << std::endl;
    return *this;
}

DiamondTrap ::~DiamondTrap()
{
    std::cout << "DiamondTrap " << this->_Name << " destroyed!" << std::endl;
}

void DiamondTrap::whoAmI()
{
    std::cout << "I am DiamondTrap " << this->_Name
              << " and my ClapTrap name is " << ClapTrap::_Name << std::endl;
}
