#include "RPN.hpp"

static bool	isOperator(const char c)
{
	return (c == '+' || c == '-' || c == '/' || c == '*');
}

static int	getTop(std::stack<int> &s)
{
	int	n = s.top();

	s.pop();
	return (n);
}

static int	handleOperator(const std::string &input, std::stack<int> &s)
{
	int	value, n1, n2;

	switch (input[0])
	{
		case '+':
			n1 = getTop(s);
			n2 = getTop(s);
			value = n2 + n1;
			break;
		case '-':
			n1 = getTop(s);
			n2 = getTop(s);
			value = n2 - n1;
			break;
		case '/':
			n1 = getTop(s);
			if (n1 == 0)
				throw (std::runtime_error(BRIGHT_RED "Error: Division by zero is forbiden." RESET));
			n2 = getTop(s);
			value = n2 / n1;
			break;
		case '*':
			n1 = getTop(s);
			n2 = getTop(s);
			value = n2 * n1;
			break;
	}
	s.push(value);
	return (1);
}

static int	getNumber(const std::string &input, std::stack<int> &s)
{
	if (isOperator(input[0]))
		return (handleOperator(input, s));

	int	i = 0;
	int	value;

	while (input[i] && std::isdigit(input[i]))
		i++;
	value = std::atoi(input.substr(0, i).c_str());
	s.push(value);
	return (i);
}

static bool	isValidInput(const char c)
{
	return (std::isdigit(c) || isOperator(c));
}

int	RPN(const std::string &input)
{
	std::stack<int>	myStack;

	//Get values
	for (size_t i = 0; i < input.size(); i++)
	{
		if (std::isspace(input[i]))
			continue;
		
		if (!isValidInput(input[i]))
			return (errorMessage("Error: invalid input.", 0));
		i += getNumber(input.substr(i), myStack) - 1;
	}
	
	//Display result
	std::cout << input <<
				 " = " ORANGE <<
				 myStack.top() << RESET << std::endl;

	return (0);
}
