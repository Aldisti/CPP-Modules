/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-stef <adi-stef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 14:51:31 by adi-stef          #+#    #+#             */
/*   Updated: 2023/04/30 16:31:26 by adi-stef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

std::string	Contact::_types[DATA] = {"first name", "last name", "nickname",
									"number", "darkest secret"};

void	Contact::getData(size_t	index)
{
	this->_index = index + 1;
	for (int i = 0; i < DATA; i++)
	{
		while (42)
		{
			std::cout << "Insert your " << Contact::_types[i] << ": ";
			std::getline(std::cin, this->_values[i]);
			clearerr(stdin);
			if (this->_values[i] != "")
				break ;
			std::cin.clear();
			std::cout << "Invalid " << Contact::_types[i] << ", try again..." << std::endl;
		}
	}
	std::cout << "New contact created" << std::endl;
	return ;
}

void	Contact::display(void) const
{
	for (int i = 0; i < DATA; i++)
		std::cout << Contact::_types[i] << ": " << this->getValue(i) << std::endl;
	return ;
}

size_t	Contact::getIndex(void) const
{
	return (this->_index);
}

std::string	Contact::getValue(size_t index) const
{
	return (this->_values[index]);
}

Contact::Contact(void)
{
	// std::cout << "\033[32m" << "Constructor called" << "\033[0m" << std::endl;
	for (int i = 0; i < DATA; i++)
		this->_values[i] = "";
	return ;
}

Contact::~Contact(void)
{
	// std::cout << "\033[31m" << "Destructor called" << "\033[0m" << std::endl;
	return ;
}
