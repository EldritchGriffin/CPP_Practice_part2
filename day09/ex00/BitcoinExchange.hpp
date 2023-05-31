#pragma once
#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <string>
# include <map>
# include <algorithm>
# include <iomanip>
# include <fstream>
# include <ctime>


class BitcoinExchange
{
    private:
        std::map<std::string, double> _data;
        void    readData();
        void    run(std::string inputfile);
        bool    isDateValid(std::string date);
        bool    isPriceValid(std::string price);
        bool    isLeapYear(int year);
        void    result(std::string date, double value);
    public:
        BitcoinExchange();
        BitcoinExchange(std::string input);
        BitcoinExchange(const BitcoinExchange &copy);
        ~BitcoinExchange();
        BitcoinExchange &operator=(const BitcoinExchange &copy);

        void    printData();
};

#endif