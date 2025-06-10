#ifndef RPN_HPP
#define RPN_HPP

# define BRIGHT_RED "\033[1;31m"
# define BRIGHT_BLUE "\033[1;34m"
# define ORANGE "\033[38;5;208m"
# define BRIGHT_GREEN "\033[1;32m"
# define RESET "\033[0m"
# define LINE 30

#include <iostream>
#include <stack>
#include <cstdlib>

int	RPN(const std::string &input);

template<typename T>
T	errorMessage(const std::string &message, T exitCode)
{
	std::cout << BRIGHT_RED << message << RESET << std::endl;
	return (exitCode);
}

#endif
