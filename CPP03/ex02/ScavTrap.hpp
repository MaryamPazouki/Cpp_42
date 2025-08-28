#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include <iostream>
#include <string>

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
    public:
        ScavTrap(const std::string &name);
        ScavTrap(const ScavTrap &other);
        ScavTrap& operator=(const ScavTrap& other);
        ~ScavTrap();

        //Overeriden attack
        void attack(const std::string& target);

        // unique attack
        void guardGate();
};


#endif