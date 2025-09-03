/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpazouki <mpazouki@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-09-03 07:41:04 by mpazouki          #+#    #+#             */
/*   Updated: 2025-09-03 07:41:04 by mpazouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <string>

class ClapTrap {
protected:
    std::string     _Name;
    unsigned int    hitPoints;
    int             energyPoints;
    int             attackDamage;

public:
    // Constructor
    ClapTrap(const std::string &name);

    // Copy constructor
    ClapTrap(const ClapTrap &other);

    // Destructor
    ~ClapTrap();

    // Copy assignment operator
    ClapTrap& operator=(const ClapTrap &other);

    // Member functions
    void attack(const std::string &target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);

   /*  // Getters
    int getHitpoints(void) const;
    int getEnergypoints(void) const;
    int getAttackpoints(void) const;
    const std::string& getName(void) const; */

   /*  //setter
    void setHitpoints(int amount);
    void setEnergypoints(int amount);
    void setAttackdamage(int amount); */
};

#endif
