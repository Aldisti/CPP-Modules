/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-stef <adi-stef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 12:10:39 by adi-stef          #+#    #+#             */
/*   Updated: 2023/05/02 14:14:35 by adi-stef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cctype>

std::string	ft_replace(std::string str, std::string s_old, std::string s_new)
{
	std::string	newString;

	for (int i = 0; i < (int)str.length(); i++)
	{
		if (i == ((int)str.find(s_old, i)))
		{
			newString += s_new;
			i += s_old.length() - 1;
		}
		else
			newString += str[i];
	}
	return (newString);
}

int	main(int ac, char **av)
{
	std::ifstream	myfile;
	std::ofstream	newfile;
	std::string		line;

	if (ac != 4)
	{
		std::cerr << "Wrong number of parameters" << std::endl;
		return (1);
	}
	myfile.open(av[1]);
	if (!myfile.is_open())
	{
		std::cerr << "Invalid input file" << std::endl;
		return (1);
	}
	newfile.open((std::string)av[1] + ".replace");
	if (!newfile.is_open())
	{
		std::cerr << "Error during creation of the new file" << std::endl;
		return (1);
	}
	while (std::getline(myfile, line))
	{
		newfile << ft_replace(line, av[2], av[3]);
		newfile << "\n";
	}
	return (0);
}
