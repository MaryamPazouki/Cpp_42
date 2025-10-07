#ifndef FORM_HPP
#define FORM_HPP

#include<string>
#include "Bureaucrat.hpp";

class Form : public Bureaucrat{
    private:
        std::string _name;
        bool _isSigned;
        const int _gradeToSign;
        const int _gradeToExecute;


    public:
        Form(std::string const & name, int gradeToSign, int gradeToExecute);
        Form(const Form& other);
        Form& operator=(const Form& other);
        ~Form();



        void beSigned(const Bureaucrat & b);


}





#endif