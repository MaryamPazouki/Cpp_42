/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpazouki <mpazouki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 12:01:07 by mpazouki          #+#    #+#             */
/*   Updated: 2025/11/05 12:01:08 by mpazouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form :: Form (std::string const &name, int gradeToSign, int gradeToExecute)
    : _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute){
    std::cout << "Default constructor called" << std::endl;
    if (gradeToExecute < 1 || gradeToSign < 1)
        throw Form::GradeTooHighException();
    if (gradeToExecute > 150 || gradeToSign > 150)
        throw Form::GradeTooLowException();
    }

Form :: Form (const Form& other) : _name(other._name), 
    _isSigned(other._isSigned), _gradeToSign(other._gradeToSign), 
    _gradeToExecute(other._gradeToExecute)
{
    std::cout << "Copy Constructor Form called for "<< this->_name << std::endl;
}

Form& Form::operator=(const Form& other)
{
    std::cout << "Copy assignment Form called for "<< this->_name << std::endl;
    if (this != &other)
        this->_isSigned = other._isSigned;
    return(*this);
}

Form :: ~Form(void){
    std::cout << "Form " << this->_name << " destroyed!" << std::endl;
}

void Form :: beSigned(const Bureaucrat &b){
    if (b.getGrade() > _gradeToSign)
        throw Form :: GradeTooLowException();
    this->_isSigned = true;
}

// Exception messages
const char* Form::GradeTooHighException::what() const throw() {
    return "Form grade too high!";
}

const char* Form::GradeTooLowException::what() const throw() {
    return "Form grade too low!";
}

//getter

const std::string Form :: getName() const{
    return(this->_name);
}
bool Form :: getIsSigned() const{
    return(this-> _isSigned);
}
int Form :: getGradeToSign() const {
    return(this -> _gradeToSign);
}
int Form :: getGradeToExecute() const{
    return(this-> _gradeToExecute);
}

// Operator <<
std::ostream & operator<<(std::ostream & out, const Form & f) {
    out << f.getName() << ", form signed: "
        << std::boolalpha << f.getIsSigned()
        << ", grade to sign: " << f.getGradeToSign()
        << ", grade to execute: " << f.getGradeToExecute() << ".";
    return out;
}