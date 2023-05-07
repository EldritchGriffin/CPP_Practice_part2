#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <iostream>

class  RobotomyRequestForm : public AForm
{
    private:
        std::string target;
    public:
    RobotomyRequestForm();
    RobotomyRequestForm(std::string target);
    RobotomyRequestForm(const RobotomyRequestForm& obj);
    RobotomyRequestForm& operator= (const RobotomyRequestForm& obj);
    virtual ~RobotomyRequestForm();

    void        set_target(std::string target);
    std::string get_target() const;

    void execute(const Bureaucrat& executor) const;
};

#endif