/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-stef <adi-stef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 17:21:28 by adi-stef          #+#    #+#             */
/*   Updated: 2023/05/11 11:26:52 by adi-stef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

IMateriaSource::IMateriaSource(void)
{
	return ;
}

IMateriaSource::IMateriaSource(IMateriaSource const &ims)
{
	(*this) = ims;
	return ;
}

IMateriaSource::~IMateriaSource(void)
{
	return ;
}

void	IMateriaSource::operator = (IMateriaSource const &ims)
{
	if (this == &ims)
		return ;
	return ;
}

MateriaSource::MateriaSource(void): IMateriaSource()
{
	for (int i = 0; i < 4; i++)
		this->_known[i] = NULL;
	return ;
}

MateriaSource::MateriaSource(MateriaSource const &ms): IMateriaSource()
{
	(*this) = ms;
	return ;
}

MateriaSource::~MateriaSource(void)
{
	for (int i = 0; i < 4; i++)
		if (this->_known[i])
			delete this->_known[i];
	return ;
}

void	MateriaSource::operator = (MateriaSource const &ms)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_known[i])
			delete this->_known[i];
		this->_known[i] = ms._known[i];
	}
	return ;
}

void	MateriaSource::learnMateria(AMateria *m)
{
	for (int i = 0; i < 4; i++)
		if (!(this->_known[i]))
		{
			this->_known[i] = m;
			break ;
		}
	return ;
}

AMateria	*MateriaSource::createMateria(std::string const &type)
{
	AMateria	*tmp = NULL;

	for (int i = 0; i < 4; i++)
		if (this->_known[i] && this->_known[i]->getType() == type)
		{
			tmp = this->_known[i]->clone();
			break ;
		}
	return (tmp);
}
