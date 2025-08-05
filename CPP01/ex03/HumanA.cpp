#include "header.hpp"

HumanA::HumanA(const std::string& name, Weapon& weapon) : weapon(weapon), name(name) {}

void HumanA::attack() const{
    std::cout << name << "attack with their " << weapon.getType() << std::cout << std::endl;

}