#include "Fixed.hpp"

int main(void){
    Fixed a ;
    Fixed b(a); // copy constructor called
    Fixed c;
    
    c = b; //copy assignment called
    // c = c; // overwriting
    std::cout << a.getRawBits() << std::endl;
    std::cout << b.getRawBits() << std::endl;
    std::cout << c.getRawBits() << std::endl;
    
    return 0;
}