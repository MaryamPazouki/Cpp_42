#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"


/*  int main()
 {
     const Animal* _animal = new Animal();
     const Animal* _cat = new Cat();
     const Animal* _dog = new Dog();

     std::cout << _cat->getType() << " " << std::endl;
     std::cout << _dog->getType() << " " << std::endl;
     
     _cat->makeSound(); //will output the cat sound!
     _dog->makeSound(); //will output the cat sound!
     _animal->makeSound();
    return 0;
} */



int main() {
    std::cout << "--- Constructors on Stack ---" << std::endl;
    Animal a;
    Dog d;
    Cat c;

    std::cout << "\n--- Sounds ---" << std::endl;
    a.makeSound();
    d.makeSound();
    c.makeSound();

    std::cout << "\n--- Polymorphism test (on Heap) ---" << std::endl;
    Animal *ptr1 = new Dog();
    Animal *ptr2 = new Cat();

    ptr1->makeSound(); // should call Dog’s version
    ptr2->makeSound(); // should call Cat’s version

    delete ptr1;
    delete ptr2;

    std::cout << "\n--- Copy and assignment ---" << std::endl;
    Dog d2 = d;     // copy constructor
    Cat c2;
    c2 = c;         // assignment operator

    std::cout << "\n--- Destructors ---" << std::endl;
    return 0;
}


/* int main() {
    std::cout << "\n=== Correct Polymorphism (with Virtual) ===\n";
    const Animal* a = new Cat();
    const Animal* b = new Dog();
    std::cout << "a is type: " << a->getType() << std::endl;
    std::cout << "b is type: " << b->getType() << std::endl;
    a->makeSound(); // Meow
    b->makeSound(); // Woof
    delete a;
    delete b;

    std::cout << "\n=== Wrong Polymorphism (without Virtual) ===\n";
    const WrongAnimal* wa = new WrongCat();
    std::cout << "wa is type: " << wa->getType() << std::endl;
    wa->makeSound(); //  Outputs WrongAnimal sound, not WrongCat
    delete wa;

    std::cout << "\n=== Direct WrongCat Call ===\n";
    WrongCat wc;
    wc.makeSound(); //  This works fine
} */

//In this simple version, you don’t see leaks because WrongCat doesn’t allocate extra heap memory.


