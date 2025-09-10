#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
    // Animal a is not allowed anymore
    Animal *a = new Dog();
    Animal *b = new Cat();

    a->makeSound(); // Woof
    b->makeSound(); // Meow

    delete a;
    delete b;

    return 0;
}