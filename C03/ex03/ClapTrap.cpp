/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-stef <adi-stef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 12:37:58 by adi-stef          #+#    #+#             */
/*   Updated: 2023/05/08 15:57:35 by adi-stef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void): _name("Unit-Z"), _hp(10), _ep(10), _atk(0)
{
	std::cout << GREEN << "ClapTrap void constructor called" << RESET << std::endl;
	return ;
}

ClapTrap::ClapTrap(std::string name): _name(name), _hp(10), _ep(10), _atk(0)
{
	std::cout << GREEN << "ClapTrap default constructor called" << RESET << std::endl;
	return ;
}

ClapTrap::ClapTrap(ClapTrap const &ct)
{
	std::cout << PURPLE << "ClapTrap copy constructor called" << RESET << std::endl;
	(*this) = ct;
	return ;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << RED << "ClapTrap destructor called" << RESET << std::endl;
	return ;
}

void	ClapTrap::operator = (ClapTrap const &ct)
{
	this->_name = ct.getName();
	this->_hp = ct.getHp();
	this->_ep = ct.getEp();
	this->_atk = ct.getAtk();
	return ;
}

std::string	ClapTrap::getName(void) const
{
	return (this->_name);
}

int	ClapTrap::getHp(void) const
{
	return (this->_hp);
}

int	ClapTrap::getEp(void) const
{
	return (this->_ep);
}

int	ClapTrap::getAtk(void) const
{
	return (this->_atk);
}

void	ClapTrap::attack(const std::string& target)
{
	if (!this->getEp())
	{
		std::cout << "ClapTrap " << this->getName()
		<< " has no energy points to attack!" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << this->getName() << " attacks " << target
	<< ", causing " << this->getAtk() << " points of damage!" << std::endl;
	this->_ep--;
	return ;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "ClapTrap " << this->getName()
	<< " has taken damage about " << amount << " points!" << std::endl;
	this->_hp -= amount;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (!this->getEp())
	{
		std::cout << "ClapTrap " << this->getName()
		<< " has no energy points to be repaired!" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << this->getName()
	<< " is being repaired about " << amount << " points!" << std::endl;
	this->_hp += amount;
	this->_ep--;
	return ;
}
