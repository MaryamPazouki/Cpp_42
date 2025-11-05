/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpazouki <mpazouki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 12:01:13 by mpazouki          #+#    #+#             */
/*   Updated: 2025/11/05 12:01:14 by mpazouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include<string>
#include<iostream>
#include<stdexcept>

class Bureaucrat; // forward declaration

class Form
{
    private:
        const std::string _name;
        bool _isSigned;
        const int _gradeToSign;
        const int _gradeToExecute;


    public:
        Form(std::string const &name, int gradeToSign, int gradeToExecute);
        Form(const Form &other);
        Form& operator=(const Form &other);
        ~Form();


        void beSigned(const Bureaucrat &b);

        //Exceptions
        class GradeTooHighException : public std::exception {
            public:
                const char* what() const throw();
        };

        class GradeTooLowException : public std::exception {
            public:
                const char* what() const throw();
        };
           
        //getter functions

        const std::string getName() const;
        bool getIsSigned() const;
        int getGradeToSign() const;
        int getGradeToExecute() const;
};
std::ostream & operator<<(std::ostream &out, const Form &f);

#endif