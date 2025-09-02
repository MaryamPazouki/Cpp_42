/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpazouki <mpazouki@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-09-02 10:37:34 by mpazouki          #+#    #+#             */
/*   Updated: 2025-09-02 10:37:34 by mpazouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.hpp"

HumanA::HumanA(const std::string& name, Weapon& weapon) : weapon(weapon), name(name) {}

void HumanA::attack() const{

    std::cout << BLUE << name << RESET << " attacks with their " << weapon.getType() << std::endl;
}