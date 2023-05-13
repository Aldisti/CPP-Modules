/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-stef <adi-stef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 17:34:53 by adi-stef          #+#    #+#             */
/*   Updated: 2023/05/10 11:36:09 by adi-stef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void): Animal("Dog")
{
	std::cout << GREEN << "Dog void constructor called" << RESET << std::endl;
	this->brain = new Brain();
	return ;
}

Dog::Dog(Dog const &c): Animal(c.getType())
{
	std::cout << GREEN << "Dog copy constructor called" << RESET << std::endl;
	(*this) = c;
	return ;
}

Dog::~Dog(void)
{
	delete this->brain;
	std::cout << RED << "Dog default destructor called" << RESET << std::endl;
	return ;
}

void	Dog::operator = (Dog const &c)
{
	if (this == &c)
		return ;
	this->_type = c.getType();
	this->brain = new Brain(*(c.brain));
	return ;
}

void	Dog::makeSound(void) const
{
	std::cout << CYAN << this->getType() << " barks!" << RESET << std::endl;
	return ;
}
