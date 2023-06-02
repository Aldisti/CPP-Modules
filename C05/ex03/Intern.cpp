/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-stef <adi-stef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 17:02:33 by adi-stef          #+#    #+#             */
/*   Updated: 2023/05/30 18:04:36 by adi-stef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern(void)
{
	std::cout << GREEN << "Intern constructor called" << RESET << std::endl;
	return ;
}

Intern::Intern(Intern const &i)
{
	(void)i;
	std::cout << GREEN << "Intern constructor called" << RESET << std::endl;
	return ;
}

Intern::~Intern(void)
{
	std::cout << RED << "Intern destructor called" << RESET << std::endl;
	return ;
}

void	Intern::operator = (Intern const &i)
{
	if (this == &i)
		return ;
	return ;
}

AForm	*Intern::makeForm(std::string name, std::string target)
{
	AForm	*form;

	if (name != "shrubbery request" && name != "robotomy request"
		&& name != "presidential request")
	{
		std::cout << CYAN << name << " name not found" << RESET << std::endl;
		return (0);
	}
	switch (name[0] % 10)
	{
		case 2:
			form = new RobotomyRequestForm(target);
			break ;
		case 3:
			form = new ShrubberyCreationForm(target);
			break ;
		default:
			form = new PresidentialPardonForm(target);
	}
	std::cout << PURPLE << "Intern cretes " << name << RESET << std::endl;
	return (form);
}
