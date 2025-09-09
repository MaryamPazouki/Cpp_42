#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>
#include <string>

class WrongAnimal{
    protected:
        std::string type;
    public:
        WrongAnimal();
        WrongAnimal(WrongAnimal &other);
        WrongAnimal &operator=(WrongAnimal &otehr);
        ~WrongAnimal();

        void makeSound() const;
        const std::string &getType(void) const;
};

#endif