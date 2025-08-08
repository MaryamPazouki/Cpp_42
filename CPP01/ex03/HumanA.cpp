#include "header.hpp"

HumanA::HumanA(const std::string& name, Weapon& weapon) : weapon(weapon), name(name) {}

void HumanA::attack() const{

    std::cout << BLUE << name << RESET << " attacks with their " << weapon.getType() << std::endl;
}