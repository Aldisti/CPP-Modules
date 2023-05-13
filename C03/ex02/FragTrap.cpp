/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-stef <adi-stef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 14:46:22 by adi-stef          #+#    #+#             */
/*   Updated: 2023/05/08 15:00:36 by adi-stef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void): ClapTrap()
{
	std::cout << GREEN << "FragTrap void constructor called" << RESET << std::endl;
	this->_hp = 100;
	this->_ep = 100;
	this->_atk = 30;
	return ;
}

FragTrap::FragTrap(std::string name): ClapTrap(name)
{
	std::cout << GREEN << "FragTrap default constructor called" << RESET << std::endl;
	this->_hp = 100;
	this->_ep = 100;
	this->_atk = 30;
	return ;
}

FragTrap::FragTrap(FragTrap const &st)
{
	std::cout << PURPLE << "FragTrap copy constructor called" << RESET << std::endl;
	(*this) = st;
	return ;
}

FragTrap::~FragTrap(void)
{
	std::cout << RED << "FragTrap destructor called" << RESET << std::endl;
	return ;
}

void	FragTrap::attack(const std::string& target)
{
	if (!this->getEp())
	{
		std::cout << "FragTrap " << this->getName()
		<< " has no energy points to attack!" << std::endl;
		return ;
	}
	std::cout << "FragTrap " << this->getName() << " attacks " << target
	<< ", causing " << this->getAtk() << " points of damage!" << std::endl;
	this->_ep--;
	return ;
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << this->getName()
	<< " is asking for an high five, guys!" << std::endl;
	return ;
}
