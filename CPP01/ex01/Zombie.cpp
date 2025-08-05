#include "header.hpp"

Zombie::Zombie() {
    std::cout << GREEN << "Zombie constructed" << RESET << std::endl; 
}

Zombie:: ~Zombie(){
    std::cout<< RED << this ->name << " is destroyed" << RESET <<std::endl;
}
  
void Zombie::announce() const {
    std::cout<< BLUE << ": BraiiiiiiinnnzzzZ..." << RESET << std::endl; 
}

void Zombie::setName (std::string name){
    this -> name = name;
}
