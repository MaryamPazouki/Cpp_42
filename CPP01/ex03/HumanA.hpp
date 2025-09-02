/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpazouki <mpazouki@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-09-02 10:37:40 by mpazouki          #+#    #+#             */
/*   Updated: 2025-09-02 10:37:40 by mpazouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HH
#define HUMANA_HH
#include <string>

//#include"header.hpp"

class Weapon; // Forward declaration

class HumanA{
    public:
        HumanA(const std::string& name, Weapon& weapon);
        void attack() const;

    private:
        Weapon& weapon;
        std::string name;
};

#endif