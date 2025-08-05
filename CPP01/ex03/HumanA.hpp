#ifndef HUMANA_HH
#define HUMANA_HH

#include "header.hpp"

class HumanA{
    public:
        HumanA(const std::string& name, Weapon& weapon);
        void attack() const;
    private:
        Weapon& weapon;
        std::string name;



};

#endif