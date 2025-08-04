#include "header.hpp"

Zombie::Zombie(std::string name) : name(name){}

Zombie::~Zombie(){
    std::cout << this->name << RED <<" is destroyed." << RESET << std::endl;
}

void Zombie::announce() const {
    std::cout << this->name << GREEN << ": BraiiiiiiinnnzzzZ..." << RESET << std::endl;
}
