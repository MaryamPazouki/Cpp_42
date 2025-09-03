/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpazouki <mpazouki@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-09-03 07:40:31 by mpazouki          #+#    #+#             */
/*   Updated: 2025-09-03 07:40:31 by mpazouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(const std::string &name) : ClapTrap (name){

    this -> hitPoints = 100;
    this -> energyPoints = 100;
    this -> attackDamage = 30;

    std::cout << "FragTrap " << this->_Name << " constructed! "
              << "It has " << this->energyPoints << " energy points and " 
              << this->hitPoints << " hit points." << std::endl;
}

FragTrap :: FragTrap(const FragTrap &other) : ClapTrap(other){
    std::cout << "FragTrap copy constructor called for " 
              << other._Name << std::endl;
}

FragTrap& FragTrap::operator = (const FragTrap &other){
    ClapTrap::operator=(other);
    std::cout << "FragTrap assignment operator called!" << std::endl;
    return *this;
}

FragTrap :: ~FragTrap(){
    std::cout << "FragTrap " << this->_Name << " destroyed!" << std::endl;
}

void FragTrap::highFivesGuys(void) {
    std::cout << "FragTrap " << this->_Name 
              << " is asking for a high five! ✋😄" 
              << std::endl;
}
