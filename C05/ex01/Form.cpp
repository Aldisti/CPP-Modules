/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-stef <adi-stef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 17:29:11 by adi-stef          #+#    #+#             */
/*   Updated: 2023/05/11 18:17:27 by adi-stef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(std::string name, int gradeSign, int gradeExec): _name(name), _firmed(false), _gradeSign(gradeSign), _gradeExec(gradeExec)
{
	if (gradeSign < 1 || gradeExec < 1)
		throw Form::GradeTooHighException();
	else if (gradeSign > 150 || gradeExec > 150)
		throw Form::GradeTooLowException();
	std::cout << GREEN << "Form constructor called" << RESET << std::endl;
	return ;
}

Form::Form(Form const &f)
{
	std::cout << GREEN << "Form copy constructor called" << RESET << std::endl;
	(*this) = f;
	return ;
}

Form::~Form(void)
{
	std::cout << RED << "Form destructor called" << RESET << std::endl;
	return ;
}

void	Form::operator = (Form const &f)
{
	if (this == &f)
		return ;
	std::cout << PURPLE << "Form copy operator called" << RESET << std::endl;
	this->_name = f.getName();
	this->_firmed = f.getFirmed();
	this->_gradeSign = f.getGradeSign();
	this->_gradeExec = f.getGradeExec();
	return ;
}

std::string	Form::getName(void) const
{
	return (this->_name);
}

bool	Form::getFirmed(void) const
{
	return (this->_firmed);
}

int	Form::getGradeSign(void) const
{
	return (this->_gradeSign);
}

int	Form::getGradeExec(void) const
{
	return (this->_gradeExec);
}

void	Form::beSigned(Bureaucrat const &b)
{
	if (b.getGrade() > this->getGradeSign())
		throw Form::GradeTooLowException();
	this->_firmed = true;
	return ;
}

std::ostream    &operator << (std::ostream &out, Form const &f)
{
	out << f.getName() << ", form gradeToSign is " << f.getGradeSign()
	<< ", gradeToExecute is " << f.getGradeExec() << " and the form is ";
	if (f.getFirmed())
		out << "firmed";
	else
		out << "not firmed";
	return (out);
}
