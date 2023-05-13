/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-stef <adi-stef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 17:51:01 by adi-stef          #+#    #+#             */
/*   Updated: 2023/05/11 11:21:47 by adi-stef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(void): WrongAnimal("WrongCat")
{
	std::cout << GREEN << "WrongCat void constructor called" << RESET << std::endl;
	return ;
}

WrongCat::WrongCat(std::string type): WrongAnimal(type)
{
	std::cout << GREEN << "WrongCat default constructor called" << RESET << std::endl;
	return ;
}

WrongCat::WrongCat(WrongCat const &c): WrongAnimal(c.getType())
{
	std::cout << GREEN << "WrongCat copy constructor called" << RESET << std::endl;
	(*this) = c;
	return ;
}

WrongCat::~WrongCat(void)
{
	std::cout << RED << "WrongCat default destructor called" << RESET << std::endl;
	return ;
}

void	WrongCat::makeSound(void) const
{
	std::cout << PURPLE << this->getType() << " miaows!" << RESET << std::endl;
	return ;
}
