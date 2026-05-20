/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpazouki <mpazouki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 07:45:40 by mpazouki          #+#    #+#             */
/*   Updated: 2026/05/19 07:45:47 by mpazouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Bureaucrat.hpp"

/*int main(){
    try{
        Bureaucrat a("B1", 2);
        std::cout<< a << std::endl;
        a.incrementGrade();
        std::cout<< a << std::endl;
        a.incrementGrade(); // throws exception
    }
    catch (std::exception & e){
        std::cerr << e.what() << std::endl;
    }
     try {
        Bureaucrat b("Bob", 151); // throws immediately
    }
    catch (std::exception & e) {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}*/

#include <iostream>
#include "Bureaucrat.hpp"

int main()
{
    std::cout << "===== VALID CONSTRUCTION =====" << std::endl;
    try {
        Bureaucrat a("Alice", 42);
        std::cout << a << std::endl;
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\n===== INVALID: GRADE TOO HIGH (0) =====" << std::endl;
    try {
        Bureaucrat b("Bob", 0);
        std::cout << b << std::endl;
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\n===== INVALID: GRADE TOO LOW (151) =====" << std::endl;
    try {
        Bureaucrat c("Charlie", 151);
        std::cout << c << std::endl;
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\n===== INCREMENT TEST =====" << std::endl;
    try {
        Bureaucrat d("David", 2);
        std::cout << d << std::endl;

        d.incrementGrade(); // should go to 1
        std::cout << "After increment: " << d << std::endl;

        d.incrementGrade(); // should throw
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\n===== DECREMENT TEST =====" << std::endl;
    try {
        Bureaucrat e("Eve", 149);
        std::cout << e << std::endl;

        e.decrementGrade(); // should go to 150
        std::cout << "After decrement: " << e << std::endl;

        e.decrementGrade(); // should throw
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\n===== MULTIPLE OPERATIONS =====" << std::endl;
    try {
        Bureaucrat f("Frank", 75);
        std::cout << f << std::endl;

        f.incrementGrade();
        f.incrementGrade();
        f.decrementGrade();

        std::cout << "After operations: " << f << std::endl;
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}