/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpazouki <mpazouki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 12:18:35 by mpazouki          #+#    #+#             */
/*   Updated: 2025/10/06 08:32:32 by mpazouki         ###   ########.fr       */
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
    if (this != &other) // avoid self assignment
        this -> _value = other.getRawBits();
    else 
        std::cout << "overwritting!" << std::endl;
    return *this;
}

bool Fixed::operator > (const Fixed &other) const{
    return this-> _value > other.getRawBits();
}

bool Fixed::operator < (const Fixed &other) const{
    return this->_value < other.getRawBits();
}

bool Fixed::operator >= (const Fixed &other) const{
    return this->_value >= other.getRawBits();
}

bool Fixed::operator<= (const Fixed &other) const{
    return this -> _value <= other.getRawBits();
}

bool Fixed::operator== (const Fixed &other) const{
    return this -> _value == other.getRawBits();
}

bool Fixed::operator != (const Fixed &other) const{
    return this -> _value != other.getRawBits();
}

Fixed Fixed::operator+(const Fixed &other) const {
    return Fixed(this->toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed &other) const{
    return Fixed(this->toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed &other) const {
    return Fixed(this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed &other) const{
    if (other.toFloat() == 0)
        throw std::runtime_error("Division by zero");
    return Fixed(this->toFloat() / other.toFloat());
}
//preincrement ++a
Fixed& Fixed::operator++(){
    this->_value ++;
    return *this; // is obj itself
}
//post increment a++
Fixed Fixed::operator++(int ){
    Fixed temp(*this);
    this->_value++;
    return temp;
}

Fixed &Fixed::operator--(){
    this->_value --;
    return *this;
}

Fixed Fixed::operator--(int){
    Fixed temp = (*this);
    this->_value--;
    return temp;
}

/*Modifying the reference modifies the original object
Const version ensures safety with read-only objects*/

Fixed& Fixed::min(Fixed &n, Fixed &m){
    return (m > n) ? n : m;
}

const Fixed& Fixed::min(const Fixed &n, const Fixed &m){
    return (m > n) ? n : m;
}

Fixed& Fixed::max(Fixed &n, Fixed &m){
    return (m < n) ? n : m;
}

const Fixed& Fixed::max(const Fixed &n, const Fixed &m){
    return (m < n) ? n : m;
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