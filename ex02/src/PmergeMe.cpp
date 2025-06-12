#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
	std::cout << BRIGHT_GREEN "PmergeMe: constructor called\n" RESET;
}
PmergeMe::PmergeMe(const PmergeMe &other)
{
	std::cout << BRIGHT_GREEN "PmergeMe: copy constructor called\n" RESET;
	*this = other;
}
PmergeMe&	PmergeMe::operator=(const PmergeMe &other)
{
	std::cout << BRIGHT_GREEN "PmergeMe: assignment operator\n" RESET;
	// if (this != &other)
		/*	copy	*/
	(void)other;
	return (*this);
}
PmergeMe::~PmergeMe()
{
	std::cout << BRIGHT_RED "PmergeMe: destructor called\n" RESET;
}

std::ostream	&operator<<(std::ostream &out, const PmergeMe &other)
{
	(void)other;
	out << "temp";
	return (out);
}
