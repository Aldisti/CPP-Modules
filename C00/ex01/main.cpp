/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-stef <adi-stef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 15:41:18 by adi-stef          #+#    #+#             */
/*   Updated: 2023/04/30 16:17:32 by adi-stef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	main(int ac, const char **av)
{
	PhoneBook	phonebook;
	std::string	cmd;

	(void)av;
	if (ac != 1)
	{
		std::cout << "Too many arguments!" << std::endl;
		return (1);
	}
	std::cout << "Please, insert one of this commands: ADD, SEARCH and EXIT"
	<< std::endl;
	while (42)
	{
		std::cout << "$> ";
		std::getline(std::cin, cmd);
		clearerr(stdin);
		std::cin.clear();
		if (cmd == "ADD")
			phonebook.add();
		else if (cmd == "SEARCH")
			phonebook.search();
		else if (cmd == "EXIT")
			break ;
	}
	std::cout << "Deleting all your contacts" << std::endl;
	std::cout << "Exiting..." << std::endl;
	return (0);
}