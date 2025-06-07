#include "BitcoinExchange.hpp"

static void	drawTitle(const std::string &title, bool orange = false)
{
	if (orange)
		std::cout << ORANGE;
	std::cout << std::string(LINE, '=') << "\n\t" << title << "\n" << std::string(LINE, '=') << RESET << std::endl;
}

int	main(int argc, char **argv)
{
	//	Error management
	if (argc != 2)
		return (drawError("Error: could not open the file.", 0));
	
	//	Setup
	std::ifstream	db("./src/data.csv");
	if (!db.is_open())
		return (drawError("Error: could not open the data base.", 1));
	std::ifstream	input(argv[1]);
	if (!input.is_open())
	{
		db.close();
		return (drawError("Error: could not open the file.", 1));
	}
	
	//	Run program
	drawTitle("BitcoinExchange");
	exchange(input, db);

	//	Close files
	db.close();
	input.close();
	return (0);
}
