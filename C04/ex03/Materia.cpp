/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Materia.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-stef <adi-stef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 15:44:50 by adi-stef          #+#    #+#             */
/*   Updated: 2023/05/11 11:24:07 by adi-stef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Materia.hpp"
#include "Character.hpp"

AMateria::AMateria(void): _type("void")
{
	return ;
}

AMateria::AMateria(std::string const &type): _type(type)
{
	return ;
}

AMateria::AMateria(AMateria const &am)
{
	(*this) = am;
	return ;
}

AMateria::~AMateria(void)
{
	return ;
}

void	AMateria::operator = (AMateria const &am)
{
	if (this == &am)
		return ;
	this->_type = am.getType();
}

std::string const	&AMateria::getType(void) const
{
	return (this->_type);
}

void	AMateria::use(ICharacter &target)
{
	(void)target;
	return ;
}

Ice::Ice(void): AMateria("ice")
{
	return ;
}

Ice::Ice(Ice const &i): AMateria(i.getType())
{
	(*this) = i;
	return ;
}

Ice::~Ice(void)
{
	return ;
}

void	Ice::operator = (Ice const &i)
{
	if (this == &i)
		return ;
	this->_type = i.getType();
	return ;
}

AMateria	*Ice::clone(void) const
{
	AMateria	*tmp;

	tmp = new Ice(*this);
	return (tmp);
}

void	Ice::use(ICharacter &target)
{
	std::cout << PURPLE << "* shoots an ice bolt at " << target.getName() << " *" << RESET << std::endl;
	return ;
}

Cure::Cure(void): AMateria("cure")
{
	return ;
}

Cure::Cure(Cure const &i): AMateria(i.getType())
{
	(*this) = i;
	return ;
}

Cure::~Cure(void)
{
	return ;
}

void	Cure::operator = (Cure const &i)
{
	if (this == &i)
		return ;
	this->_type = i.getType();
	return ;
}

AMateria	*Cure::clone(void) const
{
	AMateria	*tmp;

	tmp = new Cure(*this);
	return (tmp);
}

void	Cure::use(ICharacter &target)
{
	std::cout << CYAN << "* heals " << target.getName() << " 's wounds *" << RESET << std::endl;
	return ;
}
