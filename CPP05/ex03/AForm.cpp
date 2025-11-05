/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpazouki <mpazouki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 12:05:27 by mpazouki          #+#    #+#             */
/*   Updated: 2025/11/05 12:05:28 by mpazouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm :: AForm (std::string const &name, int gradeToSign, int gradeToExecute)
    : _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute){
   // std::cout << "Default constructor called" << std::endl;
    if (gradeToExecute < 1 || gradeToSign < 1)
        throw AForm::GradeTooHighException();
    if (gradeToExecute > 150 || gradeToSign > 150)
        throw AForm::GradeTooLowException();
    }

AForm :: AForm (const AForm& other) : _name(other._name), 
    _isSigned(other._isSigned), _gradeToSign(other._gradeToSign), 
    _gradeToExecute(other._gradeToExecute)
{
    std::cout << "Copy Constructor AForm called for "<< this->_name << std::endl;
}

AForm& AForm::operator=(const AForm& other)
{
    std::cout << "Copy assignment AForm called for "<< this->_name << std::endl;
    if (this != &other)
        this->_isSigned = other._isSigned;
    return(*this);
}

AForm :: ~AForm(void){
    //std::cout << "AForm " << this->_name << " destroyed!" << std::endl;
}

void AForm :: beSigned(const Bureaucrat &b){
    if (b.getGrade() > _gradeToSign)
        throw AForm :: GradeTooLowException();
    this->_isSigned = true;
}

void AForm::execute(Bureaucrat const &executor) const {
    if (!_isSigned)
        throw FormNotSignedException();
    if (executor.getGrade() > _gradeToExecute)
        throw GradeTooLowException();
    this->executeAction();// call the concrete action
}


// Exception messages
const char* AForm::GradeTooHighException::what() const throw() {
    return "AForm grade too high!";
}

const char* AForm::GradeTooLowException::what() const throw() {
    return "AForm grade too low!";
}

const char* AForm::FormNotSignedException::what() const throw() {
    return "Form not signed!";
}

//getter

const std::string AForm :: getName() const{
    return(this->_name);
}
bool AForm :: getIsSigned() const{
    return(this-> _isSigned);
}
int AForm :: getGradeToSign() const {
    return(this -> _gradeToSign);
}
int AForm :: getGradeToExecute() const{
    return(this-> _gradeToExecute);
}

// Operator <<
std::ostream & operator<<(std::ostream & out, const AForm & f) {
    out << f.getName() << ", AForm signed: "
        << std::boolalpha << f.getIsSigned()
        << ", grade to sign: " << f.getGradeToSign()
        << ", grade to execute: " << f.getGradeToExecute() << ".";
    return out;
}