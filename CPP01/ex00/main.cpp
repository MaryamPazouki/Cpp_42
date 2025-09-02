/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpazouki <mpazouki@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-09-02 10:33:59 by mpazouki          #+#    #+#             */
/*   Updated: 2025-09-02 10:33:59 by mpazouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "header.hpp"
//#include "Zombie.hpp"

int main(){
    Zombie* heapZombie = newZombie("HeapZombie");
    heapZombie->announce();
    delete heapZombie;

    randomChump("StackZombie");

    return 0;
}