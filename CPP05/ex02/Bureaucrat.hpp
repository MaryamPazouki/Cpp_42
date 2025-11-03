# ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include<iostream>
#include<string>

class AForm;

class Bureaucrat{
    private:
        std::string _name;
        int _grade;
    public:
        Bureaucrat();
        Bureaucrat(std::string const &name, int grade);
        Bureaucrat(const Bureaucrat &other);
        Bureaucrat& operator=(const Bureaucrat &other);
        ~Bureaucrat();
        
        std::string getName(void) const;
        int getGrade(void) const;
        
        // Grade operations
        void incrementGrade();
        void decrementGrade();

        //void signAForm();
        void signAForm(AForm &f);

        void executeForm(AForm const & form) const;
        
        // Exceptions
        class GradeTooHighException : public std::exception {
            public:
                const char* what() const throw();
        };

        class GradeTooLowException : public std::exception {
            public:
                const char* what() const throw();
        };
};

// Operator overload
std::ostream & operator<<(std::ostream & out, const Bureaucrat & b);


#endif