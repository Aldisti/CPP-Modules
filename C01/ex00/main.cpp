/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-stef <adi-stef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 12:44:25 by adi-stef          #+#    #+#             */
/*   Updated: 2023/05/02 16:35:33 by adi-stef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"



int	main(int ac, const char **av)
{
	std::string	names[10] = { "budz", "pain", "konan", "nagato", "itachi", "tobi", "madara", "naruto", "danzou", "kakashi" };
	Zombie	*z1;
	Zombie	*z2;
	Zombie	*z3;

	if (ac != 1)
	{
		std::cerr << "Error\nType: too many arguments!" << std::endl;
		return (1);
	}
	(void)av;
	std::cout << "\033[36m" << "Testing newZombie..." << "\033[0m" << std::endl;
	z1 = newZombie("pippo");
	z2 = newZombie("pluto");
	z3 = newZombie("paperino");
	delete z1;
	delete z2;
	delete z3;
	std::cout << "\033[36m" << "Testing randomChump..." << "\033[0m" << std::endl;
	randomChump(names[rand() % 10]);
	randomChump(names[rand() % 10]);
	randomChump(names[rand() % 10]);
	std::cout << "\033[36m" << "Exiting..." << "\033[0m" << std::endl;
	return (0);
}