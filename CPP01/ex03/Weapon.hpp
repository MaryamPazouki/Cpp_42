#ifndef WEAPON_HH
#define WEAPON_HH

#include <string>

class Weapon
{
    public:
        Weapon(const std::string& type); // constructor

        const std::string& getType() const; //return const ref to type
        void setType(const std::string& newType); // sets the type
            
    private:
        std::string type;
};

#endif