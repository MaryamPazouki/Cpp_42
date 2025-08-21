#include "Fixed.hpp"

Fixed :: Fixed() : _value(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed :: Fixed(const Fixed& other) : _value(other.getRawBits()) {
    std::cout << "copying Value:"<< other.getRawBits() << std::endl;
}

// Copy assignment operator
Fixed& Fixed :: operator = (const Fixed & other){
     std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
        this -> _value = other.getRawBits();
     else 
        std::cout << "overwritting!" << std::endl;
    return *this;
}

int Fixed::getRawBits(void) const{
    std::cout << "getRawBits member function called" << std::endl;
    return this -> _value;
}

void Fixed::setRawBits(int const raw){
    std::cout << "setRawBits member function called" << std::endl;
    this -> _value  = raw;
}

Fixed :: ~Fixed(){
    std::cout << "Destructor called!"<< std::endl;
}
