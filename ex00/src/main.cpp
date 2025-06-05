#include "BitcoinExchange.hpp"

static void	drawTitle(const std::string &title, bool orange)
{
	if (orange)
		std::cout << ORANGE << std::string(LINE, '=') << "\n\t" << title << "\n" << std::string(LINE, '=') << RESET << std::endl;
	else
		std::cout << std::string(LINE, '=') << "\n\t" << title << "\n" << std::string(LINE, '=') << std::endl;
}

static int	howToUse(void)
{
	std::cout << BRIGHT_RED "How to use: ./bitcoin <test number>\n" RESET;
	return (0);
}

static void	canonical(void)
{
	std::cout << ORANGE << std::string(LINE, '-') << "\n" << "\tCanonical Ortodox tests\n" << std::string(LINE, '-') << RESET << std::endl;
	std::cout << "\tConstructors\n" << std::string(LINE, '-') << std::endl;
	BitcoinExchange	a;
	BitcoinExchange	b = BitcoinExchange(10);

	std::cout << "\n\tOperator <<\n" << std::string(LINE, '-') << std::endl;
	std::cout << a << "\n" << b << "\n";

	std::cout << "\n\tAssignment test =\n" << std::string(LINE, '-') << std::endl;
	a = b;
	std::cout << a << "\n" << b << "\n";

	std::cout << "\n\tCopy constructors test =\n" << std::string(LINE, '-') << std::endl;
	BitcoinExchange	*c = new BitcoinExchange(b);
	std::cout << b << "\n" << *c << std::endl;
	delete c;

	std::cout << "\n\tDestructors\n" << std::string(LINE, '-') << std::endl;
}

int	main(int argc, char **argv)
{
	if (argc != 2)
		return (howToUse());

	std::map<std::string, void (*)(void)>	map;
	map["1"] = &canonical;

	if (map.find(argv[1]) == map.end())
		return (howToUse());

	drawTitle("BitcoinExchange", 1);
	map[argv[1]]();
	return (0);
}

