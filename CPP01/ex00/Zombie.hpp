#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP


#include "header.hpp"

class Zombie{
    public:
        Zombie(std::string name);
        ~Zombie;

        void annonce() const;
    private:
        std::string name;
};

#endif