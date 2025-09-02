/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpazouki <mpazouki@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-09-02 12:16:46 by mpazouki          #+#    #+#             */
/*   Updated: 2025-09-02 12:16:46 by mpazouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Fixed.hpp"

int main(void){
    Fixed a ;
    Fixed b(a); // copy constructor called
    Fixed c;
    
    c = b; //copy assignment called
    // c = c; // overwriting
    std::cout << a.getRawBits() << std::endl;
    std::cout << b.getRawBits() << std::endl;
    std::cout << c.getRawBits() << std::endl;
    
    return 0;
}