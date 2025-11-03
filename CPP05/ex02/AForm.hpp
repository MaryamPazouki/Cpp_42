#ifndef FORM_HPP
# define FORM_HPP

#include<string>
#include<iostream>
#include<stdexcept>

class Bureaucrat; // forward declaration

class AForm
{
    private:
        const std::string _name;
        bool _isSigned;
        const int _gradeToSign;
        const int _gradeToExecute;


    public:
        AForm(std::string const &name, int gradeToSign, int gradeToExecute);
        AForm(const AForm &other);
        AForm& operator=(const AForm &other);
        virtual ~AForm();


        void beSigned(const Bureaucrat &b);
        void execute(Bureaucrat const & executor) const; // checks, then call executeAction()

        // the action each concrete form implements
        virtual void executeAction() const = 0;

        //Exceptions
        class GradeTooHighException : public std::exception {
            public:
                const char* what() const throw();
        };

        class GradeTooLowException : public std::exception {
            public:
                const char* what() const throw();
        };
        class FormNotSignedException : public std::exception {
            public:
                const char* what() const throw();
        };
           
        //getter functions

        const std::string getName() const;
        bool getIsSigned() const;
        int getGradeToSign() const;
        int getGradeToExecute() const;
};
std::ostream & operator<<(std::ostream &out, const AForm &f);

#endif