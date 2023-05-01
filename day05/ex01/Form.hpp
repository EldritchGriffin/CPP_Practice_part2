#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;
class Form
{
	private:

		const std::string	name;
		bool				signature;
		const   int			toSign;
		const   int			toExec;

	public:

		Form();
		Form(std::string name, const int to_sign, const int to_exec);
		virtual	~Form();
		Form(const Form& obj);
		Form& operator= (const Form& obj);

		void beSigned(Bureaucrat& bureaucrat);

		const std::string	get_name() const;
		bool				get_signature();
		int					get_toSign() const;
		int					get_toExec() const;
		void				set_signature(bool signature);
		void				set_toSign(const int toSign);

		class GradeTooHighException : public std::runtime_error
		{
			public:
				GradeTooHighException();
		};
		class GradeTooLowException : public std::runtime_error
		{
			public:
				GradeTooLowException();
		};
		class FormAlreadySignedException : public std::runtime_error
		{
			public:
				FormAlreadySignedException();
		};
};

std::ostream&	operator<< ( std::ostream& ostrm, Form& form);

#endif