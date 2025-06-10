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

static void	getNum(int &n1, int &n2, std::stack<int> &s)
{
	if (s.size() < 2)
		throw (std::runtime_error(BRIGHT_RED "Error: there is no enough values to operate." RESET));
	n1 = getTop(s);
	n2 = getTop(s);
}

static int	handleOperator(const std::string &input, std::stack<int> &s)
{
	int	value, n1, n2;

	switch (input[0])
	{
		case '+':
			getNum(n1, n2, s);
			value = n2 + n1;
			break;
		case '-':
			getNum(n1, n2, s);
			value = n2 - n1;
			break;
		case '/':
			getNum(n1, n2, s);
			if (n1 == 0)
				throw (std::runtime_error(BRIGHT_RED "Error: Division by zero is forbiden." RESET));
			value = n2 / n1;
			break;
		case '*':
			getNum(n1, n2, s);
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

	int			i = 0;
	bool		isAllZero = true;
	int			value;
	std::string	result;

	while (input[i] && std::isdigit(input[i]))
		if (input[i++] != '0')
			isAllZero = false;

	if (!isAllZero && i > 1)
		throw (std::runtime_error(BRIGHT_RED "Error: number is too large." RESET));
	result = input.substr(0, i);
	value = std::atoi(result.c_str());
	s.push(value);
	return (i);
}

static bool	isValidInput(const char c)
{
	return (std::isdigit(c) || isOperator(c));
}

static bool	checkInput(const std::string &input)
{
	if (input.empty())
		return (errorMessage("Error: Empty input.", true));
	if (!isOperator(input[input.size() - 1]) || isOperator(input[0]))
		return (errorMessage("Error: invalid format. how to use: \"2 3 +\"", true));
	return (false);
}

int	RPN(const std::string &input)
{
	std::stack<int>	myStack;

	if (checkInput(input))
		return (1);

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
