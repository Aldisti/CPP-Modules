/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-stef <adi-stef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 17:05:49 by adi-stef          #+#    #+#             */
/*   Updated: 2023/05/02 10:43:32 by adi-stef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

void	HumanA::attack(void) const
{
	std::cout << this->_name << " attacks with their " << this->_weapon.getType() << std::endl;
	return ;
}

HumanA::HumanA(std::string name, Weapon &weapon) : _weapon(weapon), _name(name)
{
	std::cout << "\033[32m" << "HumanA constructor called" << "\033[0m" << std::endl;
	return ;
}

HumanA::~HumanA(void)
{
	std::cout << "\033[31m" << "HumanA destructor called" << "\033[0m" << std::endl;
	return ;
}
