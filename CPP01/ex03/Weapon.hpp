#ifndef WEAPON_HH
#define WEAPON_HH

#include "header.hpp"
#include <string>

class Weapon
{
    public:
        const std::string& getType() const; //return const ref to type
        void setType(const std::string& newType); // sets the type
        Weapon(std::string& type);

    private:
        std::string type;
};

#endif