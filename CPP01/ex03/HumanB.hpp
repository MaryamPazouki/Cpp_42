#ifndef HUMANB_HH
#define HUMANB_HH

#include "header.hpp"

class HumanB{
    public:
        HumanB(const std::string& name);
        void setWeapon(Weapon& weapon);
        void attack() const;
    private:
        Weapon* weapon;
        std::string name;
};

#endif