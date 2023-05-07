#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern
{
public:
	Intern();
	Intern(Intern const &);
	~Intern();

	Intern&	operator=(Intern const &);

AForm* makeForm(std::string formName, std::string target);
};

#endif
