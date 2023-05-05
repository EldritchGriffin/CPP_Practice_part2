#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <fstream>
#include <iostream>

class  ShrubberyCreationForm : public AForm
{
    private:
        std::string target;
    public:
    ShrubberyCreationForm();
    ShrubberyCreationForm(std::string target);
    ShrubberyCreationForm(const ShrubberyCreationForm& obj);
    ShrubberyCreationForm& operator= (const ShrubberyCreationForm& obj);
    virtual ~ShrubberyCreationForm();

    void        set_target(std::string target);
    std::string get_target() const;

    void execute(const Bureaucrat& executor) const;
};

#endif