#ifndef HUMANB_HH
#define HUMANB_HH

#include <string>

class Weapon; // Forward declaration

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