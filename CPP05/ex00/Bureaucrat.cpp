#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Unnamed"), _grade(151) {
   std::cout << "Default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string &name , const int grade)
             : _name(name), _grade(grade){
   if (grade < 1)
      throw GradeTooHighException();
   if (grade > 150)
      throw GradeTooLowException();

 }

Bureaucrat::Bureaucrat(const Bureaucrat &other): _name(other._name), 
      _grade(other._grade){
         std::cout << "Copy Constructor called for "<< this->_name << std::endl;
}
 
 
Bureaucrat& Bureaucrat::operator=(const Bureaucrat &other){
   std::cout << "copy assignment operator called!" << std::endl;
   if (this != &other)
   {
      this->_grade = other._grade;
   }
   return(*this);
 }
 

Bureaucrat::~Bureaucrat(){
   std::cout << "Bureaucrat " << this->_name << " destroyed!" << std::endl;
 }

 
void Bureaucrat::incrementGrade(void){
   if (_grade <=1)
      throw GradeTooHighException();
   _grade--;
 }
void Bureaucrat::decrementGrade(void){
   if (_grade >= 150)
      throw GradeTooLowException();
   _grade++;
}

// Exception messages
const char* Bureaucrat::GradeTooHighException::what() const throw() {
   return "Grade too high!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
   return "Grade too low!";
}

// Operator overload
std::ostream & operator<<(std::ostream &out, const Bureaucrat &b) {
   out << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
   return out;
}

 std::string  Bureaucrat::getName(void) const{
    return this->_name;
 }
 
 int  Bureaucrat::getGrade(void) const{
   return this->_grade;
 }