#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
	std::cout << BRIGHT_GREEN "BitcoinExchange: constructor called\n" RESET;
}
BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
	std::cout << BRIGHT_GREEN "BitcoinExchange: copy constructor called\n" RESET;
	*this = other;
}
BitcoinExchange&	BitcoinExchange::operator=(const BitcoinExchange &other)
{
	std::cout << BRIGHT_GREEN "BitcoinExchange: assignment operator\n" RESET;
	// if (this != &other)
		/*	copy	*/
	(void)other;
	return (*this);
}
BitcoinExchange::~BitcoinExchange()
{
	std::cout << BRIGHT_RED "BitcoinExchange: destructor called\n" RESET;
}

std::ostream	&operator<<(std::ostream &out, const BitcoinExchange &other)
{
	(void)other;
	out << "temp";
	return (out);
}
