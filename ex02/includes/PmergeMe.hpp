#ifndef PMERGEME_HPP
#define PMERGEME_HPP

# define BRIGHT_RED "\033[1;31m"
# define BRIGHT_BLUE "\033[1;34m"
# define ORANGE "\033[38;5;208m"
# define BRIGHT_GREEN "\033[1;32m"
# define RESET "\033[0m"
# define LINE 30

#include <iostream>

class PmergeMe
{
	private:
		/* data */
	public:
		PmergeMe();
		PmergeMe(const PmergeMe &other);
		PmergeMe	&operator=(const PmergeMe &other);
		~PmergeMe();
};

std::ostream	&operator<<(std::ostream &out, const PmergeMe &other);

#endif
