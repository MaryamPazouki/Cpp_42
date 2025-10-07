#include "Bureaucrat.hpp"

int main(){
    try{
        Bureaucrat a("B1", 0);
        std::cout<< a << std::endl;
        a.decrementGrade();
        std::cout<< a << std::endl;
        a.decrementGrade(); // throws exception
    }
    catch (std::exception & e){
        std::cerr << e.what() << std::endl;
    }
     try {
        Bureaucrat b("Bob", 151); // throws immediately
    }
    catch (std::exception & e) {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}