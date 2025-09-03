/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpazouki <mpazouki@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-09-03 07:39:37 by mpazouki          #+#    #+#             */
/*   Updated: 2025-09-03 07:39:37 by mpazouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ClapTrap.hpp"


int main() {
    // Create a ClapTrap
    ClapTrap ct1("Jack");

    // Attack someone
    ct1.attack("TargetDummy");

    // Take some damage
    ct1.takeDamage(3);

    // Repair itself
    ct1.beRepaired(5);

    // Take more damage (enough to destroy)
    ct1.takeDamage(12);

    // Try repairing when destroyed
    ct1.beRepaired(3);

    // Try attacking when destroyed
    ct1.attack("TargetDummy");

    // Copy constructor test
    ClapTrap ct2 = ct1;

    // Assignment operator test
    ClapTrap ct3("AnotherOne");
    ct3 = ct1;

    return 0;
}


/* attack() → consumes energy, prints damage dealt.

takeDamage() → decreases HP, never touch attackDamage.

beRepaired() → increases HP, consumes energy. */