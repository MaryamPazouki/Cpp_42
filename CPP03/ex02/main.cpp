#include "ClapTrap.hpp"
#include "ScavTrap.hpp"


int main() {
    // Create a ClapTrap
    ClapTrap ct1("Jack");
    ScavTrap st1("scavlet");

     // Try attacking when destroyed
    //ct1.attack("TargetDummy");
    st1.attack("TargetDummy");
    st1.guardGate();

    // Copy constructor test
    ScavTrap st2 = st1;

    // Assignment operator test
    ScavTrap st3("AnotherOne");
    st3 = st1;

    return 0;
}


/* attack() → consumes energy, prints damage dealt.

takeDamage() → decreases HP, never touch attackDamage.

beRepaired() → increases HP, consumes energy. */