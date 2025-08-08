#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include<string>

class Zombie{
    private:
       const std::string name;

    public:
        Zombie(const std::string& name);
        ~Zombie();

        void announce() const;

        std::string getName() {};
};

#endif