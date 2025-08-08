#ifndef HUMANA_HH
#define HUMANA_HH
#include <string>

//#include"header.hpp"

class Weapon; // Forward declaration

class HumanA{
    public:
        HumanA(const std::string& name, Weapon& weapon);
        void attack() const;

    private:
        Weapon& weapon;
        std::string name;
};

#endif