/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-stef <adi-stef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 18:04:16 by adi-stef          #+#    #+#             */
/*   Updated: 2023/05/08 18:16:24 by adi-stef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void)
{
	std::cout << GREEN << "Brain default constructor called" << RESET << std::endl;
	for (int i = 0; i < 100; i++)
		this->ideas[i] = "idea";
	return ;
}

Brain::Brain(Brain const &b)
{
	std::cout << GREEN << "Brain copy constructor called" << RESET << std::endl;
	(*this) = b;
	return ;
}

Brain::~Brain(void)
{
	std::cout << RED << "Brain default destructor called" << RESET << std::endl;
	return ;
}

void	Brain::operator = (Brain const &b)
{
	for (int i = 0; i < 100; i++)
		this->ideas[i] = b.ideas[i];
	return ;
}

std::string const	*Brain::getIdeas(void) const
{
	return (this->ideas);
}
