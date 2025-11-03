#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"
#include <string>

class PresidentialPardonForm : public AForm {
private:
    std::string _target;
public:
    PresidentialPardonForm(std::string const & target);
    virtual ~PresidentialPardonForm();
    virtual void executeAction() const;
};

#endif
