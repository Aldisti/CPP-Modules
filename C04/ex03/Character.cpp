/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-stef <adi-stef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 16:12:33 by adi-stef          #+#    #+#             */
/*   Updated: 2023/05/11 11:26:01 by adi-stef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "Materia.hpp"

ICharacter::ICharacter(void)
{
	return ;
}

ICharacter::ICharacter(ICharacter const &ic)
{
	(*this) = ic;
	return ;
}

ICharacter::~ICharacter(void)
{
	return ;
}

void	ICharacter::operator = (ICharacter const &ic)
{
	if (this == &ic)
		return ;
	return ;
}

Character::Character(std::string const &name): ICharacter(), _name(name)
{
	for (int i = 0; i < SIZE; i++)
		this->_inventory[i] = NULL;
	return ;
}

Character::Character(Character const &c): ICharacter()
{
	(*this) = c;
	return ;
}

Character::~Character(void)
{
	for (int i = 0; i < SIZE; i++)
		if (this->_inventory[i])
			delete this->_inventory[i];
	return ;
}

void	Character::operator = (Character const &c)
{
	if (this == &c)
		return ;
	this->_name = c.getName();
	for (int i = 0; i < SIZE; i++)
	{
		if (this->_inventory[i])
			delete this->_inventory[i];
		this->_inventory[i] = c._inventory[i];
	}
	return ;
}

std::string const	&Character::getName(void) const
{
	return (this->_name);
}

void	Character::equip(AMateria *m)
{
	for (int i = 0; i < SIZE; i++)
		if (!(this->_inventory[i]))
		{
			this->_inventory[i] = m;
			break ;
		}
	return ;
}

void	Character::unequip(int index)
{
	if (index >= SIZE || !(this->_inventory[index]))
		return ;
	this->_inventory[index] = NULL;
	return ;
}

void	Character::use(int index, ICharacter &target)
{
	if (index >= SIZE || !(this->_inventory[index]))
		return ;
	this->_inventory[index]->use(target);
	return ;
}
