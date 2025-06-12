#include "PmergeMe.hpp"

static void	drawTitle(const std::string &title, bool orange = false)
{
	if (orange)
		std::cout << ORANGE;
	std::cout << std::string(LINE, '=') << "\n\t" << title << "\n" << std::string(LINE, '=') << RESET << std::endl;
}

static bool	isAllDigit(const std::string &str)
{
	for (size_t i = 0; i < str.size(); i++)
		if (!std::isdigit(str[i]))
			return (false);
	return (true);
}

static bool	convert(const std::string &str, unsigned int &out)
{
	char			*end;
	unsigned long	temp;

	if (str.empty() || !isAllDigit(str))
		return (true);
	
	temp = std::strtoul(str.c_str(), &end, 10);
	if (*end || temp > UINT_MAX)
		return (true);
	out = static_cast<unsigned int>(temp);
	return (false);
}

static bool	parser(int argc, char **argv, std::vector<unsigned int> &vBase, std::list<unsigned int> &lBase)
{
	unsigned int	value;

	for (int i = 1; i < argc; i++)
	{
		if (convert(argv[i], value))
			return (1);
		vBase.push_back(value);
		lBase.push_back(value);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	std::vector<unsigned int>	vBase;
	std::list<unsigned int>		lBase;

	if (argc == 1)
		return (drawMessage("Error: too few arguments", 0, 1));

	if (parser(argc, argv, vBase, lBase))
		return (drawMessage("Error: invalid elements.", 0, 1));
	
	drawTitle("PmergeMe", 1);
	drawMessage("\tBefore\n" + std::string(LINE, '-'), 0, 0);
	drawConteiner("vector", vBase.begin(), vBase.end());
	drawConteiner("list", lBase.begin(), lBase.end());
	return (0);
}

