#include "Intern.hpp"

Intern::Intern()
{
}

Intern::Intern(const Intern &other)
{
	*this = other;
}

Intern::~Intern()
{
}


Intern&   Intern::operator=(Intern const & other )
{
	(void)other;
	return (*this);
}


AForm* Intern::makeForm(std::string formName, std::string target)
{
	AForm* form = nullptr;
	int i = 0;
	std::string formNames[3] = {"robotomy request", "presidential pardon", "shrubbery creation"};

	while (i < 3)
	{
		if (formName == formNames[i])
			break;
		i++;
	}
	switch (i)
	{
		case 0:
			form = new RobotomyRequestForm(target);
			break;
		case 1:
			form = new PresidentialPardonForm(target);
			break;
		case 2:
			form = new ShrubberyCreationForm(target);
			break;
		default:
			std::cout << "Error: Form name not found" << std::endl;
			break;
	}

	return (form);
}

