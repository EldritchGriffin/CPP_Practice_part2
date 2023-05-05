#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45)
{
    this->target = "default";
}


RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45)
{
    this->target = target;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& obj) : AForm(obj)
{
    this->target = obj.target;
}

RobotomyRequestForm& RobotomyRequestForm::operator= (const RobotomyRequestForm& obj)
{
    this->target = obj.target;
    return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

void        RobotomyRequestForm::set_target(std::string target)
{
    this->target = target;
}

std::string RobotomyRequestForm::get_target() const
{
    return (this->target);
}

void RobotomyRequestForm::execute(const Bureaucrat& executor) const
{
    if (this->get_toExec() < executor.get_grade())
        throw AForm::GradeTooLowException();
    else if (this->get_signature() == false)
        throw AForm::FormNotSignedException();
    else
    {
        std::cout << "Brrr zzzzzt" << std::endl;
        srand(time(NULL));
        if (rand() % 2 == 0)
            std::cout << this->get_target() << " has been robotomized successfully." << std::endl;
        else
            std::cout << this->get_target() << " robotomization failed." << std::endl;
    }
}