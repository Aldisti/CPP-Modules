/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-stef <adi-stef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 12:50:25 by adi-stef          #+#    #+#             */
/*   Updated: 2023/05/01 15:21:06 by adi-stef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void	Zombie::announce(void)
{
	std::cout << this->getName() << ": BraiiiiiiinnnzzzZ..." << std::endl;
	return ;
}

std::string	Zombie::getName(void) const
{
	return (this->_name);
}

Zombie::Zombie(std::string name) : _name(name)
{
	std::cout << this->_name << "\033[32m" << " Constructor called" << "\033[0m" << std::endl;
	return ;
}

Zombie::~Zombie(void)
{
	std::cout << this->_name << "\033[31m" << " Destructor called" << "\033[0m" << std::endl;
	return ;
}
