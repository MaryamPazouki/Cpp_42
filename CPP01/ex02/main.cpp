/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpazouki <mpazouki@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-09-02 10:37:17 by mpazouki          #+#    #+#             */
/*   Updated: 2025-09-02 10:37:17 by mpazouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <string>
#include <iostream>

int main (){
std :: string name( "HI THIS IS BRAIN"); // Astring variable initialized
std::string* stringPTR = &name;  // pointer to string
std::string& stringREF = name; // reference to the same string

std::cout << &name << std::endl; //The memory address of the string variable.
std::cout << stringPTR << std::endl; //The memory address held by stringPTR.
std::cout << &stringREF << std::endl; //The memory address held by stringREF.

std::cout << name << std::endl; //The value of the string variable.
std::cout << *stringPTR << std::endl; //The value pointed to by stringPTR.
std::cout << stringREF << std::endl; //The value pointed to by stringREF.
}

