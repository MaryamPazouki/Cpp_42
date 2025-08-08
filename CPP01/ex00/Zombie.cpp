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
