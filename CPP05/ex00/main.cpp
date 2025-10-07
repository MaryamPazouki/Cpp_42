#include "Bureaucrat.hpp"

int main(){
    try{
        Bureaucrat a("B1", 2);
        std::cout<< a << std::endl;
        a.incrementGrade();
        std::cout<< a << std::endl;
        a.incrementGrade(); // throws exception
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