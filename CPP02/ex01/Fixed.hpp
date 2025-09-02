/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpazouki <mpazouki@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-09-02 12:17:59 by mpazouki          #+#    #+#             */
/*   Updated: 2025-09-02 12:17:59 by mpazouki         ###   ########.fr       */
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
        Fixed(const Fixed& other);              // copy construcor
        Fixed &operator=(const Fixed &other);   // Copy assign operator
        ~Fixed();                               // Destructor

        Fixed(const int _integer); //int Constructor 
        Fixed(float const _floating); //float constructor

        float toFloat(void) const;
        int toInt(void) const;

        int getRawBits(void) const;
        void setRawBits(int const raw);
};

std::ostream& operator<<(std::ostream &out, const Fixed &fixed);

#endif