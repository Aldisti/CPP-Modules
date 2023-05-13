/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-stef <adi-stef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 14:36:10 by adi-stef          #+#    #+#             */
/*   Updated: 2023/05/08 15:02:08 by adi-stef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void): ClapTrap()
{
	std::cout << GREEN << "ScavTrap void constructor called" << RESET << std::endl;
	this->_hp = 100;
	this->_ep = 50;
	this->_atk = 20;
	return ;
}

ScavTrap::ScavTrap(std::string name): ClapTrap(name)
{
	std::cout << GREEN << "ScavTrap default constructor called" << RESET << std::endl;
	this->_hp = 100;
	this->_ep = 50;
	this->_atk = 20;
	return ;
}

ScavTrap::ScavTrap(ScavTrap const &st)
{
	std::cout << PURPLE << "ScavTrap copy constructor called" << RESET << std::endl;
	(*this) = st;
	return ;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << RED << "ScavTrap destructor called" << RESET << std::endl;
	return ;
}

void	ScavTrap::attack(const std::string& target)
{
	if (!this->getEp())
	{
		std::cout << "ScavTrap " << this->getName()
		<< " has no energy points to attack!" << std::endl;
		return ;
	}
	std::cout << "ScavTrap " << this->getName() << " attacks " << target
	<< ", causing " << this->getAtk() << " points of damage!" << std::endl;
	this->_ep--;
	return ;
}

void	ScavTrap::guardGate(void)
{
	std::cout << "ScavTrap " << this->getName()
	<< " is on guard keeper mode!" << std::endl;
	return ;
}
