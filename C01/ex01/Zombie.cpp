/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-stef <adi-stef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 12:50:25 by adi-stef          #+#    #+#             */
/*   Updated: 2023/05/01 16:01:33 by adi-stef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void	Zombie::announce(void)
{
	std::cout << this->getName() << ": BraiiiiiiinnnzzzZ..." << std::endl;
	return ;
}

void	Zombie::setName(std::string name)
{
	this->_name = name;
	return ;
}

std::string	Zombie::getName(void) const
{
	return (this->_name);
}

Zombie::Zombie(void)
{
	std::cout << "\033[1;32m" << "Constructor called" << "\033[0m" << std::endl;
	return ;
}

Zombie::~Zombie(void)
{
	std::cout << "\033[1;31m" << this->_name << " Destructor called" << "\033[0m" << std::endl;
	return ;
}
