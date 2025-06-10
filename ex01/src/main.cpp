#include "RPN.hpp"

static void	drawTitle(const std::string &title, bool orange)
{
	if (orange)
		std::cout << ORANGE << std::string(LINE, '=') << "\n\t" << title << "\n" << std::string(LINE, '=') << RESET << std::endl;
	else
		std::cout << std::string(LINE, '=') << "\n\t" << title << "\n" << std::string(LINE, '=') << std::endl;
}

int	main(int argc, char **argv)
{
	if (argc != 2)
		return (errorMessage("How to use: ./RPN <your calculation in RPN notation>", 0));

	drawTitle("RPN", 1);
	try{
		RPN(argv[1]);
	} catch(const std::exception& e){
		std::cerr << e.what() << '\n';
	}
	
	return (0);
}
