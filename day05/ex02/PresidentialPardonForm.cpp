#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5)
{
    this->target = "default";
}


PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5)
{
    this->target = target;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& obj) : AForm(obj)
{
    this->target = obj.target;
}

PresidentialPardonForm& PresidentialPardonForm::operator= (const PresidentialPardonForm& obj)
{
    this->target = obj.target;
    return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

void        PresidentialPardonForm::set_target(std::string target)
{
    this->target = target;
}

std::string PresidentialPardonForm::get_target() const
{
    return (this->target);
}

void PresidentialPardonForm::execute(const Bureaucrat& executor) const
{
    if(this->get_toExec() < executor.get_grade())
        throw AForm::GradeTooLowException();
    else if (this->get_signature() == false)
        throw AForm::FormNotSignedException();
    else
        std::cout << this->get_target() << " has been pardoned by Zafod Beeblebrox" << std::endl;
}