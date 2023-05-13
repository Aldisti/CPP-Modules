/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-stef <adi-stef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 15:15:22 by adi-stef          #+#    #+#             */
/*   Updated: 2023/05/08 15:46:08 by adi-stef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void): ClapTrap(), ScavTrap(), FragTrap()
{
	std::cout << GREEN << "DiamondTrap void constructor called" << RESET << std::endl;
	this->_hp = FragTrap::_hp;
	this->_ep = ScavTrap::_ep;
	this->_atk = FragTrap::_atk;
	this->_name = ClapTrap::_name;
	ClapTrap::_name = this->_name + "_clap_name";
	return ;
}

DiamondTrap::DiamondTrap(std::string name): ClapTrap(name), ScavTrap(name), FragTrap(name)
{
	std::cout << GREEN << "DiamondTrap default constructor called" << RESET << std::endl;
	this->_hp = FragTrap::_hp;
	this->_ep = ScavTrap::_ep;
	this->_atk = FragTrap::_atk;
	this->_name = ClapTrap::_name;
	ClapTrap::_name = this->_name + "_clap_name";
	return ;
}

DiamondTrap::DiamondTrap(DiamondTrap const &st)
{
	std::cout << PURPLE << "DiamondTrap copy constructor called" << RESET << std::endl;
	(*this) = st;
	return ;
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << RED << "DiamondTrap destructor called" << RESET << std::endl;
	return ;
}

std::string	DiamondTrap::getName(void) const
{
	return (this->_name);
}

void	DiamondTrap::whoAmI(void)
{
	std::cout << "Who the hell am I, " << this->getName() << " or "
	<< ClapTrap::getName() << "?" << std::endl;
	return ;
}
