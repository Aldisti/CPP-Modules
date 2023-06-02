/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-stef <adi-stef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 18:11:36 by adi-stef          #+#    #+#             */
/*   Updated: 2023/06/02 12:30:22 by adi-stef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# ifndef COLORS
#  define COLORS
#  define PURPLE "\033[1;35m"
#  define GREEN "\033[1;32m"
#  define CYAN "\033[1;36m"
#  define RED "\033[1;31m"
#  define RESET "\033[0m"
# endif

# include <iostream>
# include <stdlib.h>
# include <sstream>
# include <iomanip>
# include <string>
# include <cctype>

class ScalarConverter
{
	public:
		ScalarConverter(void);
		ScalarConverter(ScalarConverter const &sc);
		~ScalarConverter(void);
		ScalarConverter	&operator = (ScalarConverter const &sc);
		// functions
		static void	convert(std::string str);
		static bool	ft_in(std::string str);
		static bool	ft_check_input(std::string str);
		static int	stoi(std::string &s);
	private:
		static int	type;
};

#endif