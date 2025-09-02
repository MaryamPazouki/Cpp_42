/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpazouki <mpazouki@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-09-02 10:36:13 by mpazouki          #+#    #+#             */
/*   Updated: 2025-09-02 10:36:13 by mpazouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.hpp"

void randomChump(const std::string name)
{
    Zombie zombie(name);
    zombie.announce();
}