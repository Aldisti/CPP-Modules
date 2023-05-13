/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-stef <adi-stef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 18:23:15 by adi-stef          #+#    #+#             */
/*   Updated: 2023/05/02 12:04:00 by adi-stef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

void	HumanB::setWeapon(Weapon &new_weapon)
{
	this->_weapon = &new_weapon;
	return ;
}

void	HumanB::attack(void)
{
	std::cout << this->_name << " attacks with their " << this->_weapon->getType() << std::endl;
	return ;
}

HumanB::HumanB(std::string name) : _weapon(NULL), _name(name)
{
	std::cout << "\033[32m" << "HumanB constructor called" << "\033[0m" << std::endl;
	return ;
}

HumanB::~HumanB(void)
{
	std::cout << "\033[31m" << "HumanB destructor called" << "\033[0m" << std::endl;
	return ;
}
