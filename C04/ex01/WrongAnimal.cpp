/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-stef <adi-stef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 17:48:40 by adi-stef          #+#    #+#             */
/*   Updated: 2023/05/08 17:49:37 by adi-stef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void): _type("WrongAnimal")
{
	std::cout << GREEN << "WrongAnimal void constructor called" << RESET << std::endl;
	return ;
}

WrongAnimal::WrongAnimal(std::string type): _type(type)
{
	std::cout << GREEN << "WrongAnimal default constructor called" << RESET << std::endl;
	return ;
}

WrongAnimal::WrongAnimal(WrongAnimal const &a)
{
	std::cout << GREEN << "WrongAnimal copy constructor called" << RESET << std::endl;
	(*this) = a;
	return ;
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout << RED << "WrongAnimal default destructor called" << RESET << std::endl;
	return ;
}

void	WrongAnimal::operator = (WrongAnimal const &a)
{
	this->_type = a.getType();
	return ;
}

std::string	WrongAnimal::getType(void) const
{
	return (this->_type);
}

void	WrongAnimal::makeSound(void) const
{
	std::cout << this->getType() << " doesn't sound!" << std::endl;
	return ;
}
