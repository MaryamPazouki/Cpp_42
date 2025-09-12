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

/* int main() {
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
} */


#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

int main() {
    std::cout << "=== Deep Copy Demonstration ===" << std::endl;

    Dog dog1;
    dog1.getBrain()->setIdea(0, "Chase the cat");
    dog1.getBrain()->setIdea(1, "Eat food");

    std::cout << "dog1 ideas before copy:" << std::endl;
    std::cout << "  Idea[0]: " << dog1.getBrain()->getIdea(0) << std::endl;
    std::cout << "  Idea[1]: " << dog1.getBrain()->getIdea(1) << std::endl;

    // Copy constructor (deep copy)
    Dog dog2(dog1);

    std::cout << "\nAfter copying dog1 -> dog2:" << std::endl;
    std::cout << "dog2 ideas:" << std::endl;
    std::cout << "  Idea[0]: " << dog2.getBrain()->getIdea(0) << std::endl;
    std::cout << "  Idea[1]: " << dog2.getBrain()->getIdea(1) << std::endl;

    // Modify dog2’s brain
    dog2.getBrain()->setIdea(0, "Sleep all day");

    std::cout << "\nAfter modifying dog2’s brain:" << std::endl;
    std::cout << "dog1 idea[0]: " << dog1.getBrain()->getIdea(0) << std::endl;
    std::cout << "dog2 idea[0]: " << dog2.getBrain()->getIdea(0) << std::endl;

    // Assignment operator (deep copy)
    Dog dog3;
    dog3 = dog1;

    std::cout << "\nAfter assigning dog1 -> dog3:" << std::endl;
    std::cout << "dog3 idea[1]: " << dog3.getBrain()->getIdea(1) << std::endl;

    dog3.getBrain()->setIdea(1, "Play fetch");
    std::cout << "\nAfter modifying dog3’s brain:" << std::endl;
    std::cout << "dog1 idea[1]: " << dog1.getBrain()->getIdea(1) << std::endl;
    std::cout << "dog3 idea[1]: " << dog3.getBrain()->getIdea(1) << std::endl;

    std::cout << "\n=== Test Finished ===" << std::endl;
    return 0;
}
