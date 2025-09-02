/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpazouki <mpazouki@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-09-02 10:37:05 by mpazouki          #+#    #+#             */
/*   Updated: 2025-09-02 10:37:05 by mpazouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.hpp"

Zombie* zombieHorde(int N, std::string name){

    if (N <= 0)
        return NULL;
    
    Zombie* horde = new Zombie[N]; //alocate an array of zombies

    for (int i = 0; i < N; ++i){
        horde[i].setName(name);
    }
    return horde;
}