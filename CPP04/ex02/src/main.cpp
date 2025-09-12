/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpazouki <mpazouki@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-09-12 08:46:11 by mpazouki          #+#    #+#             */
/*   Updated: 2025-09-12 08:46:11 by mpazouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
    // Animal a  : is not allowed anymore, Animal is an abstract class
    Animal *a = new Dog();
    Animal *b = new Cat();

    a->makeSound(); // Woof
    b->makeSound(); // Meow

    delete a;
    delete b;

    return 0;
}