/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-stef <adi-stef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 17:17:58 by adi-stef          #+#    #+#             */
/*   Updated: 2023/05/23 17:28:24 by adi-stef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target): AForm("RobotomyRequestForm", 72, 45), _target(target)
{
	std::cout << GREEN << "RobotomyRequestForm constructor called" << RESET << std::endl;
	return ;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &scf): AForm(scf)
{
	(*this) = scf;
	std::cout << GREEN << "RobotomyRequestForm copy constructor called" << RESET << std::endl;
	return ;
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	std::cout << RED << "RobotomyRequestForm destructor called" << RESET << std::endl;
	return ;
}

void	RobotomyRequestForm::operator = (RobotomyRequestForm const &rrf)
{
	if (this == &rrf)
		return ;
	this->_target = rrf.getTarget();
	return ;
}

std::string	RobotomyRequestForm::getTarget(void) const
{
	return (this->_target);
}

void	RobotomyRequestForm::execute(Bureaucrat const &b) const
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
	std::cout << CYAN << "Making some drilling noises..." << RESET << std::endl;
	if (rand() % 2)
		std::cout << PURPLE << this->getTarget() << " has been robotomized" << RESET << std::endl;
	else
		std::cout << PURPLE << this->getTarget() << " robotomy failed" << RESET << std::endl;
	return ;
}
