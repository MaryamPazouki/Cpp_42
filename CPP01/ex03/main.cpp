
//#include "Weapon.hpp"
//#include "HumanA.hpp"
#include "header.hpp"

int main()
 {
    
    {    Weapon club = Weapon("crude spiked club");
        //Weapon club = Weapon(" ");
        HumanB jim("Jim");
        jim.setWeapon(club);
        //jim.attack();
        //jim.setWeapon(club);
        club.setType("some other type of jim");
        jim.attack();

        HumanA bob("Bob", club);
        
        bob.attack();
       // club.setType("some other type of bob");
        bob.attack();

    
        club.getType();
        std::cout << club.getType()<< std::endl;

    }


  
        return 0;
}