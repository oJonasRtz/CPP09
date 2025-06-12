#ifndef PMERGEME_HPP
#define PMERGEME_HPP

# define BRIGHT_RED "\033[1;31m"
# define BRIGHT_BLUE "\033[1;34m"
# define ORANGE "\033[38;5;208m"
# define BRIGHT_GREEN "\033[1;32m"
# define RESET "\033[0m"
# define LINE 30

#include <iostream>
#include <vector>
#include <list>
#include <cstdlib>
#include <climits>
#include <cerrno>

typedef std::vector<unsigned int>	t_vector;
typedef std::list<unsigned int>		t_list;

void	PmergeMeVector(t_vector &base);

template<typename T>
T	drawMessage(const std::string &message, T exitStatus, bool colour = false)
{
	if (colour)
		std::cerr << BRIGHT_RED;
	std::cerr << message << RESET << std::endl;
	return (exitStatus);
}

template<typename T>
T	drawMessage(const std::string &message)
{
	std::cout << message << std::endl;
	return T();
}

template<typename It>
void	drawConteiner(const std::string &message, It begin, It end)
{
	std::cout << message << ": " ORANGE;
	for (It i = begin; i != end; i++)
		std::cout << *i << " ";
	std::cout << "\n" RESET;
}

#endif
