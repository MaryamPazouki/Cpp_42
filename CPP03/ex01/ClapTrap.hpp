#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <string>

class ClapTrap {
protected:
    std::string     _Name;
    unsigned int    hitPoints;
    int             energyPoints;
    int             attackDamage;

public:
    // Constructor
    ClapTrap(const std::string &name);

    // Copy constructor
    ClapTrap(const ClapTrap &other);

    // Destructor
    ~ClapTrap();

    // Copy assignment operator
    ClapTrap& operator=(const ClapTrap &other);

    // Member functions
    void attack(const std::string &target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);

   /*  // Getters
    int getHitpoints(void) const;
    int getEnergypoints(void) const;
    int getAttackpoints(void) const;
    const std::string& getName(void) const; */

   /*  //setter
    void setHitpoints(int amount);
    void setEnergypoints(int amount);
    void setAttackdamage(int amount); */
};

#endif
