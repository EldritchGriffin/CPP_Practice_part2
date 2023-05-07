#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137)
{
	this->target = "default";
}


ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137)
{
	this->target = target;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& obj) : AForm(obj)
{
	this->target = obj.target;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator= (const ShrubberyCreationForm& obj)
{
	this->target = obj.target;
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

void        ShrubberyCreationForm::set_target(std::string target)
{
	this->target = target;
}

std::string ShrubberyCreationForm::get_target() const
{
	return (this->target);
}

void ShrubberyCreationForm::execute(const Bureaucrat& executor) const
{
	std::ofstream file;

	if(this->get_toExec() < executor.get_grade())
		throw AForm::GradeTooLowException();
	else if (this->get_signature() == false)
		throw AForm::FormNotSignedException();
	else
	{
		file.open(this->get_target() + "_shrubbery");
		if(file.is_open())
		{
			file << "      /\\\n";
			file << "     /\\*\\\n";
			file << "    /\\O\\*\\\n";
			file << "   /*/\\/\\/\\\n";
			file << "  /\\O\\/\\*\\/\\\n";
			file << " /\\*\\/\\*\\/\\/\\\n";
			file << "/\\O\\/\\/*/\\/O/\\\n";
			file << "      ||\n";
			file << "      ||\n";
			file << "      ||\n";
			file << "    \\====/\n";
			file << "     \\__/\n";
		}
		else
			std::cerr << "Error: could not open file." << std::endl;
	}
}