/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpazouki <mpazouki@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-09-03 07:40:36 by mpazouki          #+#    #+#             */
/*   Updated: 2025-09-03 07:40:36 by mpazouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"


class FragTrap : public ClapTrap  {

    public:
        FragTrap(const std::string &name);
        FragTrap(const FragTrap &other);
        FragTrap &operator = (const FragTrap &other);
        ~FragTrap();

        void highFivesGuys(void);
};



#endif