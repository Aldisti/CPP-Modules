/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-stef <adi-stef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 17:18:59 by adi-stef          #+#    #+#             */
/*   Updated: 2023/05/08 17:36:51 by adi-stef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void): _type("Animal")
{
	std::cout << GREEN << "Animal void constructor called" << RESET << std::endl;
	return ;
}

Animal::Animal(std::string type): _type(type)
{
	std::cout << GREEN << "Animal default constructor called" << RESET << std::endl;
	return ;
}

Animal::Animal(Animal const &a)
{
	std::cout << GREEN << "Animal copy constructor called" << RESET << std::endl;
	(*this) = a;
	return ;
}

Animal::~Animal(void)
{
	std::cout << RED << "Animal default destructor called" << RESET << std::endl;
	return ;
}

void	Animal::operator = (Animal const &a)
{
	this->_type = a.getType();
	return ;
}

std::string	Animal::getType(void) const
{
	return (this->_type);
}

void	Animal::makeSound(void) const
{
	std::cout << this->getType() << " doesn't sound!" << std::endl;
	return ;
}
