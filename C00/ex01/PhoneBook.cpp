/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-stef <adi-stef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 15:51:25 by adi-stef          #+#    #+#             */
/*   Updated: 2023/04/30 16:32:18 by adi-stef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void	PhoneBook::add(void)
{
	this->_contacts[this->_next].getData(this->_next);
	this->_nbContacts += (this->_nbContacts < SIZE);
	this->_next++;
	if (this->_next == SIZE)
		this->_next = 0;
	return ;
}

void	ft_print_pad(std::string str, size_t nPad)
{
	if (str.size() <= nPad)
		std::cout << std::setfill(' ') << std::setw(PAD) << str;
	else if (str.size() > nPad)
		std::cout << str.substr(0, nPad - 1) << ".";
	return ;
}

void	PhoneBook::search(void)
{
	size_t	id = 20022004;

	if (this->_nbContacts == 0)
	{
		std::cout << "There are no contacts yet..." << std::endl;
		return ;
	}
	std::cout << " -------------------------------------------" << std::endl;
	std::cout << "|     Index|First name| Last name|  Nickname|" << std::endl;
	for (int i = 0; i < (int)this->_nbContacts; i++)
	{
		std::cout << "|" << std::setfill(' ') << std::setw(PAD) << this->_contacts[i].getIndex();
		std::cout << "|"; ft_print_pad(this->_contacts[i].getValue(0), PAD);
		std::cout << "|"; ft_print_pad(this->_contacts[i].getValue(1), PAD);
		std::cout << "|"; ft_print_pad(this->_contacts[i].getValue(2), PAD);
		std::cout << "|" << std::endl;
	}
	std::cout << " -------------------------------------------" << std::endl;
	std::cout << "Please insert an index or 0 to exit" << std::endl;
	while (id > this->_nbContacts)
	{
		if (id != 20022004)
			std::cout << "Invalid index, try again..." << std::endl;
		std::cout << "index: ";
		std::cin >> id;
		clearerr(stdin);
		std::cin.clear();
	}
	if (!id)
		return ;
	this->_contacts[id - 1].display();
	return ;
}

PhoneBook::PhoneBook(void)
{
	std::cout << "\033[32m" << "PhoneBook Constructor called" << "\033[0m"
	<< std::endl;
	this->_nbContacts = 0;
	this->_next = 0;
	return ;
}

PhoneBook::~PhoneBook(void)
{
	std::cout << "\033[31m" << "PhoneBook Destructor called" << "\033[0m"
	<< std::endl;
	return ;
}
