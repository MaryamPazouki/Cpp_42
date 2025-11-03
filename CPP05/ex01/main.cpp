#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(){
    try{
        Bureaucrat john("John", 46);
        Form contract("Work contract", 45, 20);

        
        john.signForm(contract);// too low

        john.incrementGrade();
        john.incrementGrade();
        john.signForm(contract);// too low
        john.decrementGrade(); // throws exception
    }
    catch (std::exception & e){
        std::cerr << e.what() << std::endl;
    }
}