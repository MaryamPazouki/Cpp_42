/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpazouki <mpazouki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 13:53:48 by mpazouki          #+#    #+#             */
/*   Updated: 2025/11/19 10:15:25 by mpazouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <ctime>
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base *generate()
{
    /*std::time(NULL) returns the current time in seconds since the Unix epoch
    
    srand() sets the seed for the C-style random number generator rand().
    A seed determines the starting point of the random sequence.
    -> produces a different random sequence each program run */
    
    std::srand(std::time(NULL));
    int r = std::rand() % 3;

    switch(r){
        case 0:
            return new A();
        case 1:
            return new B();
        default:
            return new C(); 
    }
}