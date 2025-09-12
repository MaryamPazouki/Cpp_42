/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpazouki <mpazouki@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-09-12 08:45:21 by mpazouki          #+#    #+#             */
/*   Updated: 2025-09-12 08:45:21 by mpazouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main() {
    const int N = 4;
    Animal* animals[N];

    // Half Dogs, half Cats
    for (int i = 0; i < N; i++) {
        if (i < N / 2)
            animals[i] = new Dog();
        else
            animals[i] = new Cat();
    }

    std::cout << "\n=== Making sounds ===" << std::endl;
    for (int i = 0; i < N; i++)
        animals[i]->makeSound();

    std::cout << "\n=== Cleaning up ===" << std::endl;
    for (int i = 0; i < N; i++)
        delete animals[i];   // virtual destructors ensure proper deletion

    std::cout << "\n=== Deep Copy Test ===" << std::endl;
    Dog basicDog;
    basicDog = Dog();   // Assignment operator with deep copy
    // Dog() creates a temporary Dog object (on the right-hand side of the =).
    Dog copyDog(basicDog); // Copy constructor with deep copy

    return 0;
}