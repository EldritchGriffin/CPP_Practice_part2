#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
    readData();
}

BitcoinExchange::BitcoinExchange(std::string input)
{
    readData();
    run(input);
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy)
{
    *this = copy;
}

BitcoinExchange::~BitcoinExchange(){}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &copy)
{
    if (this != &copy)
        _data = copy._data;
    return (*this);
}

void BitcoinExchange::printData()
{
    std::map<std::string, double>::iterator it = _data.begin();
    std::map<std::string, double>::iterator ite = _data.end();

    while (it != ite)
    {
        std::cout << "|" << it->first << "|" << it->second << "|" << std::endl;
        it++;
    }
}

void    BitcoinExchange::readData()
{
    std::ifstream   file("data.csv");
    std::string     line;
    std::string     date;
    std::string     price;
    std::string     delimiter = ",";
    size_t          pos = 0;
    int             i = 0;

    if (file.is_open())
    {
        while (getline(file, line))
        {
            if (i == 0)
            {
                if(line != "date,exchange_rate")
                    throw std::invalid_argument("Invalid data.csv format.");
                i++;
                continue ;
            }
            pos = line.find(delimiter);
            if(pos == std::string::npos)
                throw std::invalid_argument("Invalid line in data.csv");
            date = line.substr(0, pos);
            if(isDateValid(date) == false)
                throw std::invalid_argument("Invalid date in data.csv");
            line.erase(0, pos + delimiter.length());
            pos = line.find(delimiter);
            price = line.substr(0, pos);
            if(price.empty() == true)
                throw std::invalid_argument("Invalid price in data.csv");
            _data.insert(std::pair<std::string, double>(date, std::atof(price.c_str())));
        }
        if(i == 0)
            throw std::invalid_argument("Empty data.csv.");
        file.close();
    }
    else
        std::cout << "Unable to open file" << std::endl;
}

bool    BitcoinExchange::isDateValid(std::string date)
{
    int i = 0;

    if(date.length() != 10)
        return (false);
    if (date[4] != '-' || date[7] != '-')
        return (false);
    while(date[i])
    {
        if (i != 4 && i != 7)
        {
            if (std::isdigit(date[i]) == 0)
                return (false);
        }
        i++;
    }
    return (true);
}

bool    BitcoinExchange::isPriceValid(std::string price)
{
    int i = 0;
    int dot = 0;
    double p = std::atof(price.c_str());

    if (p < 0)
    {
        std::cout << "Error: not a positive number." << std::endl;
        return (false);
    }
    if (p > 1000)
    {
        std::cout << "Error: too large a number." << std::endl;
        return (false);
    }
    while (price[i])
    {
        if (price[i] == '.')
            dot++;
        else
            if (std::isdigit(price[i]) == 0)
            {
                std::cout << "Error: Invalid value." << std::endl;
                return (false);
            }
        i++;
    }
    if (dot > 1)
    {
        std::cout << "Error: Invalid value." << std::endl;
        return (false);
    }
    return (true);
}

void    BitcoinExchange::run(std::string inputfile)
{
    std::ifstream   file(inputfile.c_str());
    std::string     line;
    std::string     date;
    std::string     price;
    std::string     delimiter = "|";
    size_t          pos = 0;
    int             i = 0;

    if (file.is_open())
    {
        while (getline(file, line))
        {
            if (i == 0)
            {
                if(line != "date | value")
                    throw std::invalid_argument("Invalid inputfile format.");
                i++;
                continue ;
            }
            pos = line.find(delimiter);
            if(pos == std::string::npos)
            {
                std::cout << "Error: bad input => " << line << std::endl;
                continue ;
            }
            date = line.substr(0, pos - 1);
            if(isDateValid(date) == false)
            {
                std::cout << "Invalid date in inputfile" << std::endl;
                continue ;
            }
            line.erase(0, pos + delimiter.length());
            price = line.substr(1);
            if(isPriceValid(price) == false)
                continue ;
            this->result(date, std::atof(price.c_str()));
        }
        if(i == 0)
            throw std::invalid_argument("Empty inputfile.");
        file.close();
    }
    else
        std::cout << "Unable to open file" << std::endl;
}

void    BitcoinExchange::result(std::string date, double value)
{
    std::map<std::string, double>::iterator it = _data.find(date);

    if(it != this->_data.end())
    {
        std::cout <<it->first << " => " << value << " = " << value * it->second << std::endl;
        return;
    }
    it = this->_data.lower_bound(date);
    if(it != this->_data.begin())
    {
        --it;
        std::cout << date << " => " << value << " = " << value * it->second << std::endl;
        return;
    }
    else
        std::cout << date << ": unavailable in database" << std::endl;
}