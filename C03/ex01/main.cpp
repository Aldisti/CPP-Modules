/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-stef <adi-stef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 14:24:34 by adi-stef          #+#    #+#             */
/*   Updated: 2023/05/08 14:52:54 by adi-stef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main(int ac, char **av)
{
	(void)av;
	if (ac != 1)
	{
		std::cout << GREEN << "Ehh senti" << RESET "," << RED
		<< " hai aspettative troppo alte" << RESET << "," << CYAN
		<< " prova a non passare" << PURPLE << " nessun argomento"
		<< RESET << std::endl;
		return (0);
	}

	ClapTrap	a;
	ClapTrap	b("Eugenio");
	ScavTrap	c("Ernesto");

	a.attack(b.getName());
	b.takeDamage(a.getAtk());
	a.beRepaired(15);

	c.attack(b.getName());
	b.takeDamage(c.getAtk());
	c.guardGate();

	return (0);
}