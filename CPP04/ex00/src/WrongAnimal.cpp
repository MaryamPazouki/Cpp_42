#include "WrongAnimal.hpp"

WrongAnimal :: WrongAnimal() : type("WrongAnimal"){
    std::cout << "WrongAnimal constructed!"<< std::endl;
}

WrongAnimal :: WrongAnimal (WrongAnimal &other){
    this ->type = other.type;
    std::cout<< "WrongAnimal copy constructed!"<<std::endl;
}

WrongAnimal& WrongAnimal :: operator=(WrongAnimal &other){
    std::cout << "WrongAnimal assigned!" << std::endl;
    if (this != &other)
        this->type = other.type;
    return (*this);
}

WrongAnimal :: ~WrongAnimal ()
{
    std::cout << "WrongAnimal destructed!" << std::endl;
}

void WrongAnimal :: makeSound()const {
    std::cout << "some generic WrongAnimal sound ...!" << std::endl;
}

const std::string& WrongAnimal:: getType(void) const{ 
    return this->type;
}


