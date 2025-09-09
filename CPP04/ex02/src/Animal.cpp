#include "Animal.hpp"


Animal::Animal() : type("Animal"){
    std::cout<< "Animal Constructed!" << std::endl;
}

Animal :: Animal(const Animal &other): type(other.type){
    std::cout<< "Animal copy Constructed!"  << std::endl;
}

Animal& Animal::operator= (const Animal &other){
     std::cout << "Animal assigned!" << std::endl;
    if (this != &other)
        this->type = other.type;
    return *this;
}

Animal::~Animal(){
    std::cout<< "Animal destroyed!"  << std::endl;
}


void Animal :: makeSound(void) const{
    std::cout << "Some generic animal sound..." << std::endl;
}

const std::string& Animal::getType(void) const{
    return this->type;
}