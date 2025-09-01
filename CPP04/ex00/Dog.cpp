#include "Dog.hpp"

Dog::Dog() : type(0) {
    std::cout<< "Default Constructor for Dog called!" << std::endl;
};

Dog:: Dog(const Dog &other): type(other.type){
    std::cout<< "copy Constructor for Dog called!" << std::endl;
}

Dog& Dog::operator = (const Dog&other){
    std::cout<< "copy Constructor for Dog called!" << std::endl;
    if (this != &other)
        this->type = other.type;
    return (*this);
}

Dog:: ~Dog(){
    std::cout<< "Destructor for Dog called!" << std::endl;
}