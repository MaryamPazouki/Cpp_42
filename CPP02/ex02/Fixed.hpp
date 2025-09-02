/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpazouki <mpazouki@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-09-02 12:18:41 by mpazouki          #+#    #+#             */
/*   Updated: 2025-09-02 12:18:41 by mpazouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <string>
#include <cmath>

class Fixed{
    private:
        int _value;
        static const int _fractionalBites = 8; 
    public:
        Fixed();                                // Default Constructor
        Fixed(const Fixed& other);              //copy construcor
        Fixed &operator=(const Fixed &other);   // Copy assign operator
        ~Fixed();                               // Destructor

        Fixed(const int _integer); //int Constructor 
        Fixed(float const _floating); //float constructor

        float toFloat(void) const;
        int toInt(void) const;

        int getRawBits(void) const;
        void setRawBits(int const raw);

        bool operator>(const Fixed &other) const;
        bool operator<(const Fixed &other) const;
        bool operator>=(const Fixed &other)  const;
        bool operator<=(const Fixed &other) const;
        bool operator==(const Fixed &other) const;
        bool operator!=(const Fixed &other) const;

        Fixed operator+(const Fixed &other) const;
        Fixed operator-(const Fixed &other) const;
        Fixed operator*(const Fixed &other) const;
        Fixed operator/(const Fixed &other) const;

        Fixed &operator++(void); //preincrement ++a
        Fixed operator++(int); //post increment a++
        Fixed &operator--(void);
        Fixed operator--(int);

        static Fixed& min(Fixed &n, Fixed &m);
        static const Fixed& min(const Fixed &n, const Fixed &m);
        static Fixed& max(Fixed &n, Fixed &m);
        static const Fixed& max(const Fixed &n, const Fixed &m);
};

std::ostream& operator<<(std::ostream &out, const Fixed &fixed);

#endif