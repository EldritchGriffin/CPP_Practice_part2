#ifndef AForm_HPP
#define AForm_HPP

#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;
class AForm
{
	private:

		const std::string	name;
		bool				signature;
		const   int			toSign;
		const   int			toExec;

	public:

		AForm();
		AForm(std::string name, const int to_sign, const int to_exec);
		virtual	~AForm();
		AForm(const AForm& obj);

		void beSigned(Bureaucrat& bureaucrat);
		virtual void execute(const Bureaucrat& executor) const = 0;

		const std::string	get_name() const;
		bool				get_signature() const;
		int					get_toSign() const;
		int					get_toExec() const;
		void				set_signature(bool signature);

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
		class FormNotSignedException : public std::runtime_error
		{
			public:
				FormNotSignedException();
		};
};

std::ostream&	operator<< ( std::ostream& ostrm, AForm& form);

#endif