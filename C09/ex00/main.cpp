/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-stef <adi-stef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 16:34:43 by adi-stef          #+#    #+#             */
/*   Updated: 2023/06/16 12:50:27 by adi-stef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "Error\nType: Invalid input" << std::endl;
		return (1);
	}
	try
	{
		BitcoinExchange::exchange(av[1]);
	}
	catch (std::exception &e)
	{
		std::cout << "Error\nType: " << e.what() << std::endl;
		return (1);
	}
	return (0);
}
