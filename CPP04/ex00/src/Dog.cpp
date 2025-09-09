#include "Dog.hpp"

Dog::Dog() {
    this->type ="Dog";
    std::cout<< "Dog Constructed!" << std::endl;
};

Dog:: Dog(const Dog &other): Animal(other){
    std::cout<< "Dog copy Constructed!" << std::endl;
}

Dog& Dog::operator = (const Dog&other){
   Animal :: operator=(other);
    std::cout<< "Dog assigned!" << std::endl;
    return (*this);
}

Dog:: ~Dog(){
    std::cout<< "Dog Destructed!" << std::endl;
}

void Dog::makeSound (void) const {
    std::cout << "Woof!" << std::endl;
}