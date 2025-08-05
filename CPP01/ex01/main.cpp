#include "header.hpp"

int main(){
    int count = 5;
    Zombie* horde = zombieHorde(count, "HordeZ");

    if (!horde)
        return 1;
    
    for(int i= 0; i< count; ++i){
        std::cout << BLUE << "Zombie #" << i<< ": " << RESET;
        horde[i].announce();
    }

    delete[] horde;
    return 0;
}