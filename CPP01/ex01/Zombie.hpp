/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpazouki <mpazouki@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-09-02 10:36:59 by mpazouki          #+#    #+#             */
/*   Updated: 2025-09-02 10:36:59 by mpazouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef ZOMBIE_HH
#define ZOMBIE_HH

#include<string>
#include <iostream>

class Zombie
{
private:
    std::string name;
public:
    Zombie();
    ~Zombie();

    void announce() const;
    void setName(std::string name);
};

#endif