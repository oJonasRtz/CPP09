#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

# define BRIGHT_RED "\033[1;31m"
# define BRIGHT_BLUE "\033[1;34m"
# define ORANGE "\033[38;5;208m"
# define BRIGHT_GREEN "\033[1;32m"
# define RESET "\033[0m"
# define LINE 30

#include <map>
#include <iostream>

class BitcoinExchange
{
	private:
		/* data */
	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &other);
		BitcoinExchange	&operator=(const BitcoinExchange &other);
		~BitcoinExchange();
};

std::ostream	&operator<<(std::ostream &out, const BitcoinExchange &other);

#endif
