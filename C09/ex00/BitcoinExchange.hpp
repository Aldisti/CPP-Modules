/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-stef <adi-stef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 11:10:58 by adi-stef          #+#    #+#             */
/*   Updated: 2023/06/15 11:39:01 by adi-stef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <map>

class BitcoinExchange
{
	public:
		// METHODS
		static double const	&getPrice(std::string const &date);
		static void			exchange(std::string const &path);
		// ERRORS
		class InvalidDB: public std::exception
        {
            public:
                virtual const char* what() const throw()
                { return ("Invalid database file"); }
        };
		class InvalidInputFile: public std::exception
        {
            public:
                virtual const char* what() const throw()
                { return ("Invalid input file"); }
        };
	private:
		BitcoinExchange(void);
		BitcoinExchange(BitcoinExchange const &be);
		~BitcoinExchange(void);
		BitcoinExchange	&operator = (BitcoinExchange const &be);
		static std::map<std::string, double>	_db;
		// STATIC FUNCTIONS
		static bool	isValidDate(int d, int m, int y);
		static std::map<std::string, double>	uploadDB(std::string const &path);
};
