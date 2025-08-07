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