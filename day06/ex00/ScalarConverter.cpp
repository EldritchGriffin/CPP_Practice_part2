#include "ScalarConverter.hpp"

// canonical form

ScalarConverter::ScalarConverter(){}

ScalarConverter::ScalarConverter(std::string const & str) : type(str) {}

ScalarConverter::ScalarConverter(const ScalarConverter &other){	*this = other;}

ScalarConverter::~ScalarConverter(){}

ScalarConverter&   ScalarConverter::operator=(ScalarConverter const & other )
{
	this->type = other.type;
	return (*this);
}

std::string ScalarConverter::getType() const { return (this->type); }

void ScalarConverter::setType(std::string const & str) { this->type = str; }

// member functions

bool ScalarConverter::isChar(void) const
{
	if (this->type.length() == 1 && !isdigit(this->type[0]))
		return (true);
	return (false);
}

bool ScalarConverter::isInt(void) const
{
	int i = -1;

	while(this->type[++i])
	{
		if (i == 0 && (this->type[i] == '-' || this->type[i] == '+'))
			continue;
		if (!isdigit(this->type[i]))
			return (false);
	}
	return (true);
}

bool ScalarConverter::isDouble(void) const
{
	int i = -1;
	int dot = 0;

	while(this->type[++i])
	{
		if (i == 0 && (this->type[i] == '-' || this->type[i] == '+'))
			continue;
		if (this->type[i] == '.')
			dot++;
		else if (!isdigit(this->type[i]))
			return (false);
	}
	if (dot == 1)
		return (true);
	return (false);
}
bool ScalarConverter::isDouble(std::string type) const
{
	int i = -1;
	int dot = 0;

	while(type[++i])
	{
		if (i == 0 && (type[i] == '-' || type[i] == '+'))
			continue;
		if (type[i] == '.')
			dot++;
		else if (!isdigit(type[i]))
			return (false);
	}
	if (dot == 1)
		return (true);
	return (false);
}

bool ScalarConverter::isFloat(void) const
{
	std::string str = this->type.substr(0, this->type.length() - 1);

	if(this->isDouble(str) && this->type[this->type.length() - 1] == 'f')
		return (true);
	else
		return (false);
}

bool ScalarConverter::isDenormalized(void) const
{
	if (this->type == "nan" || this->type == "nanf" || this->type == "+inf" || this->type == "+inff" || this->type == "-inf" || this->type == "-inff")
		return (true);
	return (false);
}

void ScalarConverter::printChar(void) const
{
	char	c;
	try
	{
		if (this->isInt())
			c = static_cast<char>(std::stoi(this->type));
		else if (this->isFloat())
			c = static_cast<char>(std::stof(this->type));
		else if (this->isDouble())
			c = static_cast<char>(std::stod(this->type));
		else
			c = this->type[0];
		if (isprint(c))
			std::cout << "char: '" << c << "'" << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;
	}
	catch(const std::invalid_argument& e)
	{
		std::cout << "char: impossible" << std::endl;
	}
	catch(const std::out_of_range& e)
	{
		std::cout << "char: impossible" << std::endl;
	}
}

void	ScalarConverter::printInt(void) const
{
	int n;

	try
	{
		if (this->isChar())
			n = static_cast<int>(this->type[0]);
		else if (this->isInt())
			n = std::stoi(this->type);
		else if (this->isFloat())
			n = static_cast<int>(std::stof(this->type));
		else if (this->isDouble())
			n = static_cast<int>(std::stod(this->type));
		else
			n = std::stoi(this->type);
		std::cout << "int: " << n << std::endl;
	}
	catch(const std::invalid_argument& e)
	{
		std::cout << "int: impossible" << std::endl;
	}
	catch(const std::out_of_range& e)
	{
		std::cout << "int: impossible" << std::endl;
	}
}

void	ScalarConverter::printFloat(void) const
{
	float f;

	try
	{
		if (this->isChar())
			f = static_cast<float>(this->type[0]);
		else if (this->isInt())
			f = static_cast<float>(std::stoi(this->type));
		else if (this->isFloat())
			f = std::stof(this->type);
		else if (this->isDouble())
			f = static_cast<float>(std::stod(this->type));
		else
			f = std::stof(this->type);
		std::cout << std::fixed << std::setprecision(1) << "float: " << f << "f" << std::endl;
	}
	catch(const std::invalid_argument& e)
	{
		std::cout << "float: impossible" << std::endl;
	}
	catch(const std::out_of_range& e)
	{
		std::cout << "float: impossible" << std::endl;
	}
}

void ScalarConverter::printDouble(void) const
{
	double d;

	try
	{
		if (this->isChar())
			d = static_cast<double>(this->type[0]);
		else if (this->isInt())
			d = static_cast<double>(std::stoi(this->type));
		else if (this->isFloat())
			d = static_cast<double>(std::stof(this->type));
		else if (this->isDouble())
			d = std::stod(this->type);
		else
			d = std::stod(this->type);
		std::cout << std::fixed << std::setprecision(1) << "double: " << d << std::endl;
	}
	catch(const std::invalid_argument& e)
	{
		std::cout << "double: impossible" << std::endl;
	}
	catch(const std::out_of_range& e)
	{
		std::cout << "double: impossible" << std::endl;
	}
}

bool ScalarConverter::checkError(void) const
{
	if (this->isDenormalized() || this->isChar() || this->isInt() || this->isFloat() || this->isDouble())
		return (true);
	return (false);
}

void ScalarConverter::convert(void)
{
	if(!this->checkError())
		throw ScalarConverter::InvalidInputException();
	this->printChar();
	this->printInt();
	this->printFloat();
	this->printDouble();
}

ScalarConverter::InvalidInputException::InvalidInputException() : std::runtime_error("ERROR: Invalid Input."){}
