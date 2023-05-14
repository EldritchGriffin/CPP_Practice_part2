#pragma once
#ifndef  SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <exception>
# include <string>
# include <limits>
# include <iomanip>
 
class ScalarConverter
{
	private:
		std::string type;
		bool		isChar(void) const ;
		bool		isInt(void) const ;
		bool		isDouble(void) const ;
		bool		isDouble(std::string type) const ;
		bool		isFloat(void) const ;
		bool		isDenormalized(void) const ;
		bool		checkError(void) const ;
		void		printChar(void) const ;
		void		printInt(void) const ;
		void		printFloat(void) const ;
		void		printDouble(void) const ;

	public:
		ScalarConverter();
		ScalarConverter(ScalarConverter const &);
		ScalarConverter(std::string const & str);
		~ScalarConverter();

		void 		convert(void);
		std::string getType(void) const;
		void		setType(std::string const & str);

		class InvalidInputException : public std::runtime_error
		{
			public:
				InvalidInputException();
		};
		ScalarConverter&	operator=(ScalarConverter const &);
};

#endif 
