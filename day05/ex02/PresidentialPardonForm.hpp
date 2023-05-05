#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"
#include <iostream>

class  PresidentialPardonForm : public AForm
{
    private:
        std::string target;
    public:
    PresidentialPardonForm();
    PresidentialPardonForm(std::string target);
    PresidentialPardonForm(const PresidentialPardonForm& obj);
    PresidentialPardonForm& operator= (const PresidentialPardonForm& obj);
    virtual ~PresidentialPardonForm();

    void        set_target(std::string target);
    std::string get_target() const;

    void execute(const Bureaucrat& executor) const;
};

#endif