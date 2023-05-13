/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-stef <adi-stef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 14:20:55 by adi-stef          #+#    #+#             */
/*   Updated: 2023/05/02 15:49:07 by adi-stef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(int ac, char **av)
{
	Harl		harl;
	std::string	level;

	if (ac != 2)
	{
		std::cerr << "Wrong number of arguments" << std::endl;
		return (1);
	}
	level = av[1];
	if (level != "DEBUG" && level != "INFO" && level != "WARNING"
		&& level != "ERROR")
	{
		std::cerr << "Invalid level" << std::endl;
		return (0);
	}
	harl.complain(level);
	return (0);
}
