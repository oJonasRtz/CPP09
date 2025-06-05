#include "BitcoinExchange.hpp"

static void	fillMap(std::map<std::string, double> &map, std::ifstream &db)
{
	std::string	line;

	//Ignore header
	if (!std::getline(db, line))
		return;
	//Fill the map
	while (std::getline(db, line))
	{
		if (line.empty())
			continue;
		std::istringstream	ss(line);
		std::string	date, valueStr;
		if (std::getline(ss, date, ',') && std::getline(ss, valueStr))
		{
			double	value;
			std::istringstream	iss(valueStr);
			if (!(iss >> value))
				std::cerr << BRIGHT_RED "Error: invalid value on line: " << line << RESET;
			else
				map[date] = value;
		}
	}
}

static bool	isAllDigit(const std::string &str)
{
	for (std::string::size_type i = 0; i < str.size(); i++)
		if (!std::isdigit(str[i]) && str[i] != '.' && str[i] != '-')
			return (false);
	return (true);
}

static bool	checkValue(const std::string &value, const std::string &date)
{
	std::stringstream	ss;

	if (value.empty() || !isAllDigit(value))
	{
		ss << "Error: bad input => " << date;
		return (drawError(ss.str(), true));
	}
	if (value[0] == '-')
		return (drawError("Error: not a positive number.", true));
	return (false);
}
//Trim spaces from the string
static std::string	trim(const std::string &str)
{
	if (str.empty())
		return (str);

	std::string::size_type	start = 0;
	while (start < str.size() && std::isspace(str[start]))
		start++;
	
	std::string::size_type	end = str.size();
	while (end > start && std::isspace(str[end - 1]))
		end--;
	
	return (str.substr(start, end - start));
}

static double	getClosestValue(std::map<std::string, double> &map, const std::string &date)
{
	std::map<std::string, double>::iterator	it = map.find(date);
	
	if (it == map.end())
	{
		std::map<std::string, double>::iterator	lb = map.lower_bound(date);
		return (lb->second);
	}
	return (it->second);
}

static double	convert(std::map<std::string, double> &data, const std::string &date, const std::string &valueStr)
{
	double				value;
	std::istringstream	ss(valueStr);
	double				closest = getClosestValue(data, date);

	ss >> value;
	if (value > 1000)
		return (drawError("Error: too large number.", -1));
	return (value * closest);
}

static void	drawMessage(const std::string &date, const std::string &value, std::map<std::string, double> &data)
{
	double	val = convert(data, date, value);

	if (val < 0)
		return;
	
	std::cout <<
		ORANGE <<
		date <<	" => " << value << RESET " = " ORANGE << val <<
		RESET << std::endl;
}

void	exchange(std::ifstream &input, std::ifstream &db)
{
	std::string	line;

	//Setup
	std::map<std::string, double>	data;
	fillMap(data, db);
	
	//Ignore header
	if (!std::getline(input, line))
		return;
	while (std::getline(input, line))
	{
		std::string	date, valueStr;
		std::istringstream	ss(line);
		if (!std::getline(ss, date, '|') || !std::getline(ss, valueStr))
		{
			std::cout << BRIGHT_RED "Error: bad input => " << date << RESET << std::endl;
			continue;
		}
		date = trim(date);
		valueStr = trim(valueStr);
		if (checkValue(valueStr, date))
			continue;
		drawMessage(date, valueStr, data);
	}
}
