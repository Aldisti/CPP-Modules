/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-stef <adi-stef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 16:53:50 by adi-stef          #+#    #+#             */
/*   Updated: 2023/05/20 17:41:07 by adi-stef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target): AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
	std::cout << GREEN << "ShrubberyCreationForm constructor called" << RESET << std::endl;
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &scf): AForm(scf)
{
	(*this) = scf;
	std::cout << GREEN << "ShrubberyCreationForm copy constructor called" << RESET << std::endl;
	return ;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	std::cout << RED << "ShrubberyCreationForm destructor called" << RESET << std::endl;
	return ;
}

void	ShrubberyCreationForm::operator = (ShrubberyCreationForm const &scf)
{
	if (this == &scf)
		return ;
	this->_target = scf.getTarget();
	return ;
}

std::string	ShrubberyCreationForm::getTarget(void) const
{
	return (this->_target);
}

void	ShrubberyCreationForm::execute(Bureaucrat const &b) const
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
	std::ofstream	file((this->getTarget() + "_shrubbery").c_str());
	for (int i = 0; i < 10; i++)
		file << "ASCII trees" << std::endl;
	file.close();
	return ;
}

