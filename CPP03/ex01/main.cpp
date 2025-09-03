/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpazouki <mpazouki@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-09-03 07:40:00 by mpazouki          #+#    #+#             */
/*   Updated: 2025-09-03 07:40:00 by mpazouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"


int main() {
   std::cout << "=== ClapTrap Test ===" << std::endl;
    ClapTrap ct("Jack");
    ct.attack("Dummy");
    ct.takeDamage(5);
    ct.beRepaired(3);

   std::cout << "=== ScavTrap Test ===" << std::endl;

    // Create a ScavTrap
    ScavTrap st1("Scavy");

    // Attack a target
    st1.attack("Training Dummy");

    // Take damage and repair
    st1.takeDamage(30);
    st1.beRepaired(15);

    // Activate special ability
    st1.guardGate();

    std::cout << "\n=== Copy Constructor Test (ScavTrap) ===" << std::endl;
    ScavTrap st2 = st1;  // invokes copy constructor

    std::cout << "\n=== Assignment Operator Test (ScavTrap) ===" << std::endl;
    ScavTrap st3("AnotherScav");
    st3 = st1;           // invokes assignment operator

    return 0;
}


/* attack() → consumes energy, prints damage dealt.

takeDamage() → decreases HP, never touch attackDamage.

beRepaired() → increases HP, consumes energy. */