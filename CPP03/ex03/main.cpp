/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpazouki <mpazouki@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-09-03 07:41:32 by mpazouki          #+#    #+#             */
/*   Updated: 2025-09-03 07:41:32 by mpazouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main() {
    std::cout << "=== Creating DiamondTrap d1 ===" << std::endl;
    DiamondTrap d1("Diamondy");

    std::cout << "\n=== Testing abilities ===" << std::endl;
    d1.attack("enemy target");        // inherited from ScavTrap
    d1.takeDamage(20);                // from ClapTrap
    d1.beRepaired(15);                // from ClapTrap
    d1.highFivesGuys();               // from FragTrap
    d1.guardGate();                   // from ScavTrap
    d1.whoAmI();                      // DiamondTrap-specific

    std::cout << "\n=== Copy constructor test ===" << std::endl;
    DiamondTrap d2(d1);
    d2.whoAmI();

    std::cout << "\n=== Assignment operator test ===" << std::endl;
    DiamondTrap d3("Temp");
    d3 = d1;
    d3.whoAmI();

    std::cout << "\n=== Scope ending, destructors will be called ===" << std::endl;
    return 0;
}



/* attack() → consumes energy, prints damage dealt.

takeDamage() → decreases HP, never touch attackDamage.

beRepaired() → increases HP, consumes energy. */