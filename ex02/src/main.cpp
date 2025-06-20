#include "PmergeMe.hpp"

static void	drawTitle(const std::string &title, bool orange = false)
{
	if (orange)
		std::cout << ORANGE;
	std::cout << std::string(LINE, '=') << "\n\t" << title << "\n" << std::string(LINE, '=') << RESET << std::endl;
}

static bool	convert(const std::string &str, unsigned int &out)
{
	char			*end;
	unsigned long	temp;

	if (str.empty())
		return (true);
	
	errno = 0;
	temp = std::strtoul(str.c_str(), &end, 10);
	if (*end || temp > UINT_MAX || errno)
		return (true);
	out = static_cast<unsigned int>(temp);
	return (false);
}

static bool	isDuplicate(int argc, char **argv)
{
	for (int i = 1; i < argc; i++)
	{
		for (int j = i - 1; j > 0; j--)
			if (std::string(argv[i]) == std::string(argv[j]))
				return (true);
	}
	return (false);
}

static bool	parser(int argc, char **argv, std::vector<unsigned int> &vBase, std::list<unsigned int> &lBase)
{
	if (argc == 1)
		return (drawMessage("Error: too few arguments", 1, 1));

	if (isDuplicate(argc, argv))
		return (drawMessage("Error: duplicates detected.", 1, 1));

	unsigned int	value;

	for (int i = 1; i < argc; i++)
	{
		if (convert(argv[i], value))
			return (drawMessage("Error: invalid input", 1, 1));
		vBase.push_back(value);
		lBase.push_back(value);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_vector	vBase;
	t_list		lBase;

	if (parser(argc, argv, vBase, lBase))
		return (1);
	
	//show values before
	drawTitle("PmergeMe", 1);
	drawMessage<void>("\tBefore\n" + std::string(LINE, '-'));
	drawConteiner("vector", vBase.begin(), vBase.end());
	drawConteiner("list", lBase.begin(), lBase.end());

	//Execute PmergeMe
	double	vTime = getTime(vBase,  &PmergeMeVector);
	double	lTime = getTime(lBase, &PmergeMeList);

	//Show after
	drawMessage<void>("\tAfter\n" + std::string(LINE, '-'));
	
	//Vector time
	drawConteiner("vector", vBase.begin(), vBase.end());
	std::cout << "Time to process a range of " << vBase.size() <<
			std::fixed << std::setprecision(7) <<
			 " elements with std::vector: " << vTime << "s" << std::endl;

	//List time
	drawConteiner("list", lBase.begin(), lBase.end());
	std::cout << "Time to process a range of " << vBase.size() <<
			std::fixed << std::setprecision(7) <<
			 " elements with std::list: " << lTime << "s" << std::endl;
	return (0);
}
