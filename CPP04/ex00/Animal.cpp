#include "Animal.hpp"


Animal::Animal(std::string &n) : type(n){
    std::cout<< "Default Constructor for Animal called!" << std::endl;
}

Animal :: Animal(const Animal &other): type(other.type){
    std::cout<< "copy Constructor for Anmila called!" << std::endl;
}

Animal& Animal::operator= (const Animal &other){
     std::cout << "copy assignment operator  Animal called!" << std::endl;
    if (this != &other)
        this->type = other.type;
    return *this;
}

Animal::~Animal(){
    std::cout<< "Destructor for Animal called!" << std::endl;
}