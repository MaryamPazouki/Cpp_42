#include "Cat.hpp"

Cat :: Cat(){
    std::cout<< "Default Constructor for Cat called!" << std::endl;
}

Cat :: Cat(const Cat &other): type(other.type){
    std::cout<< "copy Constructor for Cat called!" << std::endl;
}

Cat& Cat::operator = (const Cat& other){
    std::cout<< "copy Constructor for Cat called!" << std::endl;
    if (this != &other)
        this->type = other.type;
    return(*this);
}

Cat :: ~Cat(){
    std::cout<< "Destructor for Cat called!" << std::endl;
}