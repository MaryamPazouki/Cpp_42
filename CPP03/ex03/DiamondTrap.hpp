/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpazouki <mpazouki@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-09-03 07:41:17 by mpazouki          #+#    #+#             */
/*   Updated: 2025-09-03 07:41:17 by mpazouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMOND_TRAP
#define DIAMOND_TRAP

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"


#include <string>

class DiamondTrap : public ScavTrap, public FragTrap {
    private:
        std::string _Name;
    public:
        DiamondTrap(const std::string &name);
        DiamondTrap(const DiamondTrap &other);
        DiamondTrap &operator = (const DiamondTrap &other);
        ~DiamondTrap();

        void whoAmI();
        using ScavTrap::attack; // Avoid ambiguity, use ScavTrap’s attack
};


#endif