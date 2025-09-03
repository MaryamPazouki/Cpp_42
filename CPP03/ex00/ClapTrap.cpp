/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpazouki <mpazouki@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-09-03 07:39:31 by mpazouki          #+#    #+#             */
/*   Updated: 2025-09-03 07:39:31 by mpazouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap :: ClapTrap(const std::string &n) : _Name (n), hitPoints(10),  energyPoints(10),  attackDamage(0){
    std::cout << "ClapTrap " <<this-> _Name << " constructed!" 
                << "it has " << this-> energyPoints << " energypoints and " 
                << this->hitPoints << " Hitpoints "<< std::endl;
}

ClapTrap :: ClapTrap (const ClapTrap &other ): _Name(other._Name), hitPoints(other.getHitpoints()), 
                 energyPoints(other.getEnergypoints()),  attackDamage(other.getAttackpoints()){
                    std::cout << "Copy Constructor called for "<< this-> _Name << std::endl;
                 }

ClapTrap&  ClapTrap :: operator = (const ClapTrap &other){
    std::cout << "copy assignment operator called!" << std::endl;
    if (this != &other )
    {
        this -> _Name = other._Name;
        this -> hitPoints = other.hitPoints;
        this -> energyPoints = other.energyPoints;
        this -> attackDamage = other.attackDamage;
    }
    return (*this);
} 

int  ClapTrap::getHitpoints(void) const{
    return this -> hitPoints;
};
int ClapTrap:: getEnergypoints(void) const {
    return this-> energyPoints;
};
int ClapTrap:: getAttackpoints(void) const{
    return this-> attackDamage;
};
const std::string& ClapTrap:: getName(void) const{
    return this -> _Name;
};    
                 
ClapTrap :: ~ClapTrap(){
   std::cout << "ClapTrap " << this->_Name << " destroyed!" << std::endl;

} 

void ClapTrap :: attack(const std::string &target){
    if (this->hitPoints <= 0 || energyPoints <= 0) {
        std::cout << "ClapTrap " << this->_Name << " cannot attack (no HP or energy left)!\n";
        return;
    }
    this-> energyPoints--;
    std::cout << "ClapTrap " << this->_Name << " attacks " << target 
                <<  ", causing " << this -> attackDamage 
                << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
    if (this->hitPoints <= 0) {
        std::cout << "ClapTrap " << this->_Name << " is already destroyed!" << std::endl;
        return;
    }
    if (amount >= this->hitPoints)
        this -> hitPoints = 0;
    else
        this->hitPoints -= amount;

    std::cout << "ClapTrap " << this->_Name 
              << " takes " << amount << " points of damage! "
              << "Remaining HP: " << this->hitPoints << std::endl;
}


void ClapTrap::beRepaired(unsigned int amount) {
    if (this->hitPoints <= 0 || this->energyPoints <= 0) {
        std::cout << "ClapTrap " << this->_Name 
                  << " cannot repair (no HP or energy left)!\n";
        return;
    }

    this->hitPoints += amount;
    this->energyPoints--;

    std::cout << "ClapTrap " << this->_Name 
              << " repairs itself, gaining " << amount 
              << " hit points! Now has " << this->hitPoints 
              << " HP and " << this->energyPoints 
              << " energy points!" << std::endl;
}

