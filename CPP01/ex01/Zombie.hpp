#ifndef ZOMBIE_HH
#define ZOMBIE_HH

#include<string>
#include <iostream>

class Zombie
{
private:
    std::string name;
public:
    Zombie();
    ~Zombie();

    void announce() const;
    void setName(std::string name);
};

#endif