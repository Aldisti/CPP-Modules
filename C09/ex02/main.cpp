/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-stef <adi-stef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 14:14:51 by adi-stef          #+#    #+#             */
/*   Updated: 2023/06/16 12:39:15 by adi-stef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pmerge.hpp"

/*
$(shuf -i 0-1000 -n 1000 | tr '\n' ' ')
$(shuf -i 0-3000 -n 3000 | tr '\n' ' ')
$(shuf -i 0-10000 -n 10000 | tr '\n' ' ')
*/
int	main(int ac, char **av)
{
	std::string	avs = "";

	if (ac < 2)
	{
		std::cout << "Error\nType: Invalid arguments" << std::endl;
		return (1);
	}

	for (int i = 1; i < ac; i++)
		avs += std::string(av[i]) + " ";
	try
	{
		Pmerge::sort(avs);
	}
	catch(std::exception &e)
	{
		std::cout << "Error\nType: " << e.what() << std::endl;
		return (1);
	}
	return (0);
}
