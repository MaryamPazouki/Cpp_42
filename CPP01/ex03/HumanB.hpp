/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpazouki <mpazouki@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-09-02 10:37:54 by mpazouki          #+#    #+#             */
/*   Updated: 2025-09-02 10:37:54 by mpazouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef HUMANB_HH
#define HUMANB_HH

#include <string>

class Weapon; // Forward declaration

class HumanB{
    public:
        HumanB(const std::string& name);
        void setWeapon(Weapon& weapon);
        void attack() const;
        
    private:
        Weapon* weapon;
        std::string name;
};

#endif