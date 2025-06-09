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

static bool	isValidDate(const std::string &date, const std::string &firstYear)
{
	//Check format YYYY-MM-DD
	bool	format = date.size() == 10 && date[4] == '-' && date[7] == '-';
	if (!format)
		return (format);

	//Check date
	int	year = std::atoi(date.substr(0, 4).c_str());
	int	yearDb = std::atoi(firstYear.substr(0, 4).c_str());
	int	month = std::atoi(date.substr(5, 2).c_str());
	int	day = std::atoi(date.substr(8, 2).c_str());
	int	daysInMonth[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	bool	myDate = (month <= 12 && month > 0)
					&& (day > 0 && day <= daysInMonth[month - 1])
					&& (year >= yearDb);

	return (myDate);
}

static bool	checkValue(const std::string &value, const std::string &date, const std::string &firstYear)
{
	std::stringstream	ss;

	if (value.empty() || date.empty() || !isAllDigit(value) || !isValidDate(date, firstYear))
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
	if (it != map.end())
		return it->second;

	std::map<std::string, double>::iterator	lb = map.lower_bound(date);
	if (lb == map.end() || lb->first > date)
		lb--;

	return lb->second;
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
	
	//Read <input> file
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
		if (checkValue(valueStr, date, data.begin()->first))
			continue;
		drawMessage(date, valueStr, data);
	}
}
