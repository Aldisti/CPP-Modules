/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-stef <adi-stef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 17:29:44 by adi-stef          #+#    #+#             */
/*   Updated: 2023/05/08 17:37:01 by adi-stef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void): Animal("Cat")
{
	std::cout << GREEN << "Cat void constructor called" << RESET << std::endl;
	return ;
}

Cat::Cat(std::string type): Animal(type)
{
	std::cout << GREEN << "Cat default constructor called" << RESET << std::endl;
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
	std::cout << RED << "Cat default destructor called" << RESET << std::endl;
	return ;
}

void	Cat::makeSound(void) const
{
	std::cout << PURPLE << this->getType() << " miaows!" << RESET << std::endl;
	return ;
}
