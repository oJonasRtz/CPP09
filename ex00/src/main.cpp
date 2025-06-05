#include "BitcoinExchange.hpp"

static void	drawTitle(const std::string &title, bool orange)
{
	if (orange)
		std::cout << ORANGE << std::string(LINE, '=') << "\n\t" << title << "\n" << std::string(LINE, '=') << RESET << std::endl;
	else
		std::cout << std::string(LINE, '=') << "\n\t" << title << "\n" << std::string(LINE, '=') << std::endl;
}

static int	errorMessage(const std::string &message, unsigned int exitCode = 0)
{
	std::cout << BRIGHT_RED << message << "\n" RESET;
	return (exitCode);
}

int	main(int argc, char **argv)
{
	//	Error management
	if (argc != 2)
		return (errorMessage("Error: could not open the file."));
	
	//	Setup
	std::ifstream	db("./src/data.csv");
	if (!db.is_open())
		return (errorMessage("Error: could not open the data base.", 1));
	std::ifstream	input(argv[1]);
	if (!input.is_open())
	{
		db.close();
		return (errorMessage("Error: could not open the file.", 1));
	}
	//	Run program
	drawTitle("BitcoinExchange", 1);
	// exchange(input, db);

	//	Close files
	db.close();
	input.close();
	return (0);
}

