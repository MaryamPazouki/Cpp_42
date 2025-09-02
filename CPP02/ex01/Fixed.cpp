/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpazouki <mpazouki@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-09-02 12:17:54 by mpazouki          #+#    #+#             */
/*   Updated: 2025-09-02 12:17:54 by mpazouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed :: Fixed() : _value(0){
    std::cout << "Default constructor called" << std::endl;
}

Fixed :: Fixed(const int iNum) {
    std::cout << "Int constructor called" << std::endl;
    this -> _value = iNum << _fractionalBites;
}

Fixed :: Fixed (const float fNum) {
    std::cout << "Float constructor called" << std::endl;
    this ->_value = roundf (fNum* (1 << _fractionalBites));
}

float Fixed :: toFloat(void) const{
    return (float) this -> _value / (1 << _fractionalBites);
}

int Fixed :: toInt(void ) const{
    return this -> _value >> _fractionalBites;
}

Fixed :: Fixed (const Fixed& other) : _value(other.getRawBits()){
    std::cout << "Copy Constructor called" << std::endl;
}

Fixed& Fixed:: operator = (const Fixed& other){
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
        this -> _value = other.getRawBits();
    else 
        std::cout << "overwritting!" << std::endl;
    return *this;
}

std::ostream& operator <<(std::ostream &out, const Fixed &fixed){
    out << fixed.toFloat();
    return out;
}

int Fixed :: getRawBits(void)const{
    std::cout << "getRawBits member function called" << std::endl;
    return this->_value;
}

void Fixed :: setRawBits(int const raw){
    std::cout << "setRawBits member function called" << std::endl;
    this -> _value = raw;
}

Fixed :: ~Fixed(){
    std::cout << "Destructor called!" << std::endl;
}