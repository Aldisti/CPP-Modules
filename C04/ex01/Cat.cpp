/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-stef <adi-stef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 17:29:44 by adi-stef          #+#    #+#             */
/*   Updated: 2023/05/10 11:35:30 by adi-stef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void): Animal("Cat")
{
	std::cout << GREEN << "Cat void constructor called" << RESET << std::endl;
	this->brain = new Brain();
	return ;
}

Cat::Cat(Cat const &c): Animal(c.getType())
{
	std::cout << GREEN << "Cat copy constructor called" << RESET << std::endl;
	(*this) = c;
	return ;
}

Cat::~Cat(void)
{
	delete this->brain;
	std::cout << RED << "Cat default destructor called" << RESET << std::endl;
	return ;
}

void	Cat::operator = (Cat const &c)
{
	if (this == &c)
		return ;
	this->_type = c.getType();
	this->brain = new Brain(*(c.brain));
	return ;
}

void	Cat::makeSound(void) const
{
	std::cout << PURPLE << this->getType() << " miaows!" << RESET << std::endl;
	return ;
}
