#include "RPN.hpp"

RPN::RPN()
{
	std::cout << BRIGHT_GREEN "RPN: constructor called\n" RESET;
}
RPN::RPN(const RPN &other)
{
	std::cout << BRIGHT_GREEN "RPN: copy constructor called\n" RESET;
	*this = other;
}
RPN&	RPN::operator=(const RPN &other)
{
	std::cout << BRIGHT_GREEN "RPN: assignment operator\n" RESET;
	// if (this != &other)
		/*	copy	*/
	(void)other;
	return (*this);
}
RPN::~RPN()
{
	std::cout << BRIGHT_RED "RPN: destructor called\n" RESET;
}

std::ostream	&operator<<(std::ostream &out, const RPN &other)
{
	(void)other;
	out << "temp";
	return (out);
}
