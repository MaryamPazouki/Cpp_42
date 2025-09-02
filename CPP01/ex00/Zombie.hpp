/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpazouki <mpazouki@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-09-02 10:36:28 by mpazouki          #+#    #+#             */
/*   Updated: 2025-09-02 10:36:28 by mpazouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include<string>

class Zombie{
    private:
       const std::string name;

    public:
        Zombie(const std::string& name);
        ~Zombie();

        void announce() const;

        std::string getName();
};

#endif