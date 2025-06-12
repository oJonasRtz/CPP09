#include "PmergeMe.hpp"

static void	drawTitle(const std::string &title, bool orange = false)
{
	if (orange)
		std::cout << ORANGE;
	std::cout << std::string(LINE, '=') << "\n\t" << title << "\n" << std::string(LINE, '=') << RESET << std::endl;
}

int	main(void)
{
	drawTitle("PmergeMe", 1);
	return (0);
}

