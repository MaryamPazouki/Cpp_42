/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpazouki <mpazouki@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-09-02 10:34:14 by mpazouki          #+#    #+#             */
/*   Updated: 2025-09-02 10:34:14 by mpazouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "header.hpp"

Zombie* newZombie(const std::string& name)
{
    return new Zombie(name);
}