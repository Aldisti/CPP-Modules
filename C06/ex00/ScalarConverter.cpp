/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-stef <adi-stef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 18:40:23 by adi-stef          #+#    #+#             */
/*   Updated: 2023/06/02 12:27:46 by adi-stef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int	ScalarConverter::type = -1;

ScalarConverter::ScalarConverter(void)
{
	return ;
}

ScalarConverter::ScalarConverter(ScalarConverter const &sc)
{
	*this = sc;
	return ;
}

ScalarConverter::~ScalarConverter(void)
{
	return ;
}

ScalarConverter	&ScalarConverter::operator = (ScalarConverter const &sc)
{
	(void)sc;
	return (*this);
}

int ScalarConverter::stoi(std::string &s)
{
	std::istringstream iss (s.c_str());
    int	i;

    iss >> i;
    return (i);
}

bool	ScalarConverter::ft_check_input(std::string str)
{
	int	j = 0;
	int	k = 0;

	if (!str[0])
		return (false);
	if (str.size() == 1)
	{
		if (std::isdigit(str[0]))
			ScalarConverter::type = 1;
		return (!std::isdigit(str[0]) || !std::isalpha(str[0]));
	}
	if (ScalarConverter::ft_in(str))
	{
		ScalarConverter::type = 0;
		return (true);
	}
	for (int i = 0; i < (int)str.length(); i++)
	{
		if (!std::isdigit(str[i]) && str[i] != '.' && str[i] != 'f')
			return (false);
		j += (str[i] == 'f');
		k += (str[i] == '.');
	}
	if (j > 1 || k > 1 || (j && !k))
		return (false);
	ScalarConverter::type = j + k + 1;
	return (true);
}

bool	ScalarConverter::ft_in(std::string str)
{
	for (int i = 0; i < (int)str.size(); i++)
		str[i] = std::tolower(str[i]);
	if (str == "inf" || str == "inff" || str == "+inf" || str == "-inf"
		|| str == "+inff" || str == "-inff" || str == "nan" || str == "nanf")
		return (true);
	return (false);
}

void	ScalarConverter::convert(std::string str)
{
	int		n;
	char	c;
	double	d;
	float	f;

	if (!ScalarConverter::ft_check_input(str))
	{
		std::cerr << RED
		<< "Error\nThe input is not a valid char, int, float or double"
		<< RESET << std::endl;
		return ;
	}
	switch (ScalarConverter::type)
	{
		case -1:
			c = str[0];
			n = static_cast<int>(c);
			f = static_cast<float>(n);
			d = static_cast<double>(n);
			std::cout << CYAN << "Type: char" << RESET << std::endl;
			break ;
		case 0:
			d = atof(str.c_str());
			f = d;
			if (str == "inf" || str == "+inf" || str == "-inf" || str == "nan")
				std::cout << CYAN << "Type: double" << RESET << std::endl;
			else
				std::cout << CYAN << "Type: float" << RESET << std::endl;
			break ;
		case 1:
			n = ScalarConverter::stoi(str);
			c = static_cast<char>(n);
			f = static_cast<float>(n);
			d = static_cast<double>(n);
			std::cout << CYAN << "Type: int" << RESET << std::endl;
			break ;
		default:
			d = atof(str.c_str());
			f = d;
			n = static_cast<int>(d);
			c = static_cast<char>(n);
			if (str[str.size() - 1] == 'f')
				std::cout << CYAN << "Type: float" << RESET << std::endl;
			else
				std::cout << CYAN << "Type: double" << RESET << std::endl;
	}
	if (!ScalarConverter::type)
		std::cout << "Char: impossible\nInt: impossible" << std::endl;
	else
	{
		if (n < 32 || n >= 128)
			std::cout << "Char: Non displayable" << std::endl;
		else
			std::cout << "Char: '" << c << "'" << std::endl;
		std::cout << "Int: " << n << " " << std::endl;
	}
	std::cout << "Float: " << f;
	if (f - (int)f == 0)
		std::cout << ".0";
	std::cout << "f" << std::endl;
	std::cout << "Double: " << d;
	if (d - (int)d == 0)
		std::cout << ".0";
	std::cout << std::endl;
	return ;
}
