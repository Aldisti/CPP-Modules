/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-stef <adi-stef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 17:42:17 by adi-stef          #+#    #+#             */
/*   Updated: 2023/05/20 17:48:35 by adi-stef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target): AForm("PresidentialPardonForm", 25, 5), _target(target)
{
	std::cout << GREEN << "PresidentialPardonForm constructor called" << RESET << std::endl;
	return ;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &scf): AForm(scf)
{
	(*this) = scf;
	std::cout << GREEN << "PresidentialPardonForm copy constructor called" << RESET << std::endl;
	return ;
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
	std::cout << RED << "PresidentialPardonForm destructor called" << RESET << std::endl;
	return ;
}

void	PresidentialPardonForm::operator = (PresidentialPardonForm const &ppf)
{
	if (this == &ppf)
		return ;
	this->_target = ppf.getTarget();
	return ;
}

std::string	PresidentialPardonForm::getTarget(void) const
{
	return (this->_target);
}

void	PresidentialPardonForm::execute(Bureaucrat const &b) const
{
    if (!this->getFirmed())
	{
        throw AForm::FormNotSigned();
		return ;
	}
    else if (b.getGrade() > this->getGradeExec())
	{
        throw AForm::GradeTooLowException();
		return ;
	}
	std::cout << PURPLE << this->getTarget() << " has been pardoned by Zaphod Beeblebrox"
	<< RESET << std::endl;
	return ;
}
