/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpazouki <mpazouki@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-09-03 07:40:40 by mpazouki          #+#    #+#             */
/*   Updated: 2025-09-03 07:40:40 by mpazouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
//#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main() {
    std::cout << "=== ClapTrap Test ===" << std::endl;
    ClapTrap ct("Jack");
    ct.attack("Dummy");
    ct.takeDamage(5);
    ct.beRepaired(3);

    /* std::cout << "\n=== ScavTrap Test ===" << std::endl;
    ScavTrap st("Scavy");
    st.attack("Dummy");
    st.guardGate(); */

    std::cout << "\n=== FragTrap Test ===" << std::endl;
    FragTrap ft("Fraggy");
    ft.attack("Dummy");
    ft.highFivesGuys();

    // Copy constructor test
    std::cout << "\n=== Copy Constructor Test (FragTrap) ===" << std::endl;
    FragTrap ft2 = ft;

    // Assignment operator test
    std::cout << "\n=== Assignment Operator Test (FragTrap) ===" << std::endl;
    FragTrap ft3("AnotherFrag");
    ft3 = ft;

    return 0;
}



/* attack() → consumes energy, prints damage dealt.

takeDamage() → decreases HP, never touch attackDamage.

beRepaired() → increases HP, consumes energy. */