/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-stef <adi-stef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 17:29:11 by adi-stef          #+#    #+#             */
/*   Updated: 2023/05/11 18:17:27 by adi-stef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(std::string name, int gradeSign, int gradeExec): _name(name), _firmed(false), _gradeSign(gradeSign), _gradeExec(gradeExec)
{
	if (gradeSign < 1 || gradeExec < 1)
		throw AForm::GradeTooHighException();
	else if (gradeSign > 150 || gradeExec > 150)
		throw AForm::GradeTooLowException();
	std::cout << GREEN << "AForm constructor called" << RESET << std::endl;
	return ;
}

AForm::AForm(AForm const &f)
{
	std::cout << GREEN << "AForm copy constructor called" << RESET << std::endl;
	(*this) = f;
	return ;
}

AForm::~AForm(void)
{
	std::cout << RED << "AForm destructor called" << RESET << std::endl;
	return ;
}

void	AForm::operator = (AForm const &f)
{
	if (this == &f)
		return ;
	std::cout << PURPLE << "AForm copy operator called" << RESET << std::endl;
	this->_name = f.getName();
	this->_firmed = f.getFirmed();
	this->_gradeSign = f.getGradeSign();
	this->_gradeExec = f.getGradeExec();
	return ;
}

std::string	AForm::getName(void) const
{
	return (this->_name);
}

bool	AForm::getFirmed(void) const
{
	return (this->_firmed);
}

int	AForm::getGradeSign(void) const
{
	return (this->_gradeSign);
}

int	AForm::getGradeExec(void) const
{
	return (this->_gradeExec);
}

void	AForm::beSigned(Bureaucrat const &b)
{
	if (b.getGrade() > this->getGradeSign())
		throw AForm::GradeTooLowException();
	this->_firmed = true;
	return ;
}

std::ostream    &operator << (std::ostream &out, AForm const &f)
{
	out << f.getName() << ", form gradeToSign is " << f.getGradeSign()
	<< ", gradeToExecute is " << f.getGradeExec() << " and the form is ";
	if (f.getFirmed())
		out << "firmed";
	else
		out << "not firmed";
	return (out);
}
