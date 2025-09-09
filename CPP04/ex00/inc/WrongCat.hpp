#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP


#include <string>
#include <iostream>

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
    public:
        WrongCat();
        WrongCat(WrongCat &other);
        WrongCat &operator=(WrongCat &other);
        ~WrongCat();

        void makesound() const;
};

#endif

