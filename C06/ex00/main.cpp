/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-stef <adi-stef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 18:05:21 by adi-stef          #+#    #+#             */
/*   Updated: 2023/06/02 12:08:44 by adi-stef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <string>
#include <limits>
#include "ScalarConverter.hpp"

int	main(int ac, char **av)
{
	ScalarConverter	boh;

	if (ac != 2)
	{
		std::cerr << RED
		<< "Error\nWrong arguments"
		<< RESET << std::endl;
		return (1);
	}
	for (int i = 1; i < ac; i++)
	{
		boh.convert(av[i]);
		std::cout << std::endl;
	}
	return (0);
}
