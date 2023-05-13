/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-stef <adi-stef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 12:44:25 by adi-stef          #+#    #+#             */
/*   Updated: 2023/05/01 15:58:38 by adi-stef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"



int	main(int ac, const char **av)
{
	Zombie	*horde;

	(void)av;
	if (ac != 1)
	{
		std::cerr << "Too many arguments!" << std::endl;
		return (1);
	}
	horde = zombieHorde(16, "Socrate");
	for (int i = 0; i < 16; i++)
		horde[i].announce();
	delete [] horde;
	return (0);
}