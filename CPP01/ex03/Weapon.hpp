/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpazouki <mpazouki@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-09-02 10:38:18 by mpazouki          #+#    #+#             */
/*   Updated: 2025-09-02 10:38:18 by mpazouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HH
#define WEAPON_HH

#include <string>

class Weapon
{
    public:
        Weapon(const std::string& type); // constructor
        
        const std::string& getType() const; //return const ref to type
        void setType(const std::string& newType); // sets the type
            
    private:
        std::string type;
};

#endif