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
#include <fstream>
#include <sstream>
#include <string>

void	exchange(std::ifstream &input, std::ifstream &db);
template<typename T>
T		drawError(const std::string &message, T exitCode)
{
	std::cout << BRIGHT_RED << message << RESET << std::endl;
	return (exitCode);
}

#endif
