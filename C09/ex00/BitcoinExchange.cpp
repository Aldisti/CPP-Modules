/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-stef <adi-stef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 11:26:29 by adi-stef          #+#    #+#             */
/*   Updated: 2023/06/15 11:56:54 by adi-stef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

std::map<std::string, double> BitcoinExchange::_db = BitcoinExchange::uploadDB("data.csv");

bool BitcoinExchange::isValidDate(int d, int m, int y)
{
	if (y < 2009 || y > 2023)
		return (false);
    if (m < 1 || m > 12)
		return (false);
    if (d < 1 || d > 31)
		return (false);
    if (m == 2)
		return ((((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0)) && d <= 29) || d <= 28);
    if (m == 4 || m == 6 || m == 9 || m == 11)
		return (d <= 30);
	return (true);
}

std::map<std::string, double>	BitcoinExchange::uploadDB(std::string const &path)
{
	std::ifstream					data;
	std::map<std::string, double>	db;
	std::string						line;
	int								year;
	int								month;
	int								day;
	double							price;

	data.open(path.c_str());
	if (!data)
		throw (BitcoinExchange::InvalidDB());
	std::getline(data, line);
	if (line != "date,exchange_rate")
		throw (BitcoinExchange::InvalidDB());
	while (42)
	{
		std::getline(data, line);
		if (!data || !line[0])
			break ;
		try
		{
			year = atof((line.substr(0, 4)).c_str());
			month = atof((line.substr(5, 2)).c_str());
			day = atof((line.substr(8, 2)).c_str());
			price = atof((line.substr(11, line.size() - 10)).c_str());
		}
		catch(std::exception &e)
		{ throw (BitcoinExchange::InvalidDB()); }
		if (price < 0 || !BitcoinExchange::isValidDate(day, month, year))
			throw (BitcoinExchange::InvalidDB());
		db[line.substr(0, 10)] = price;
	}
	data.close();
	return (db);
}

BitcoinExchange::BitcoinExchange(void) {}
BitcoinExchange::BitcoinExchange(BitcoinExchange const &be) { (void)be; }
BitcoinExchange::~BitcoinExchange(void) {}
BitcoinExchange	&BitcoinExchange::operator = (BitcoinExchange const &be)
{
	(void)be;
	return (*this);
}

double const	&BitcoinExchange::getPrice(std::string const &date)
{
	try
	{
		return (BitcoinExchange::_db.at(date));
	}
	catch(std::exception &e)
	{
		return (BitcoinExchange::_db.lower_bound(date)->second);
	}
}

void		BitcoinExchange::exchange(std::string const &path)
{
	std::ifstream					data;
	std::string						line;
	std::string						date;
	int								year;
	int								month;
	int								day;
	double							value;

	data.open(path.c_str());
	if (!data)
		throw (BitcoinExchange::InvalidInputFile());
	std::getline(data, line);
	if (line != "date | value")
		throw (BitcoinExchange::InvalidInputFile());
	while (42)
	{
		std::getline(data, line);
		if (!data || !line[0])
			break ;
		if (line.find(" | ") == std::string::npos)
			date = line.substr(0, line.size());
		else
			date = line.substr(0, line.find(" | "));
		if (line.size() <= 10)
		{
			std::cout << "Error: bad input => " << date << std::endl;
			continue ;
		}
		if (line[4] != 45 || line[7] != 45)
		{
			std::cout << "Error: bad input => " << date << std::endl;
			continue ;
		}
		if (line[10] != 32 || line[11] != '|' || line[12] != 32)
		{
			std::cout << "Error: bad input => " << line << std::endl;
			continue ;
		}
		year = atof((line.substr(0, 4)).c_str());
		month = atof((line.substr(5, 2)).c_str());
		day = atof((line.substr(8, 2)).c_str());
		if (!BitcoinExchange::isValidDate(day, month, year))
		{
			std::cout << "Error: bad input => " << date << std::endl;
			continue ;
		}
		value = atof((line.substr(line.find(" | ") + 3, line.size())).c_str());
		if (value < 0 || value > 1000)
		{
			if (value < 0)
				std::cout << "Error: not a positive number." << std::endl;
			else
				std::cout << "Error: too large number." << std::endl;
			continue ;
		}
		std::cout << date << " => " << value << " = " << value * BitcoinExchange::getPrice(date) << std::endl;
	}
	data.close();
}
