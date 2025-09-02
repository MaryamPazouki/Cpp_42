/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpazouki <mpazouki@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-09-02 12:16:40 by mpazouki          #+#    #+#             */
/*   Updated: 2025-09-02 12:16:40 by mpazouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include<string>
#include<iostream>

class Fixed {
private:
    int _value; // The fixed-point value
    static const int _fractionalBits = 8; // Number of fractional bits

public:
    // Default constructor
    Fixed();

    // Copy constructor
    Fixed(const Fixed &other);

    // Destructor
    ~Fixed();

    // Assignment operator
    Fixed &operator=(const Fixed &other);

    // Getter for the raw fixed-point value
    int getRawBits(void) const;

    // Setter for the raw fixed-point value
    void setRawBits(int const raw);
};




#endif