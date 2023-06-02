/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-stef <adi-stef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 16:00:20 by adi-stef          #+#    #+#             */
/*   Updated: 2023/05/11 17:25:22 by adi-stef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string name, int grade): _name(name), _grade(grade)
{
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    else if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
    std::cout << GREEN << "Bureaucrat constructor called" << RESET << std::endl;
    return ;
}

Bureaucrat::Bureaucrat(Bureaucrat const &b)
{
    std::cout << GREEN << "Bureaucrat copy constructor called" << RESET << std::endl;
    (*this) = b;
    return ;
}

Bureaucrat::~Bureaucrat(void)
{
    std::cout << RED << "Bureaucrat destructor called" << RESET << std::endl;
    return ;
}

void    Bureaucrat::operator = (Bureaucrat const &b)
{
    if (this == &b)
        return ;
    std::cout << PURPLE << "Bureaucrat copy operator called" << RESET << std::endl;
    (std::string)this->_name = b.getName();
    this->_grade = b.getGrade();
    return ;
}

std::string Bureaucrat::getName(void) const
{
    return (this->_name);
}

int Bureaucrat::getGrade(void) const
{
    return (this->_grade);
}

void    Bureaucrat::incGrade(void)
{
    if (this->getGrade() <= 1)
        throw Bureaucrat::GradeTooHighException();
    this->_grade--;
    std::cout << CYAN << "Grade increased to grade " << this->getGrade() << RESET << std::endl;
    return ;        
}

void    Bureaucrat::decGrade(void)
{
    if (this->getGrade() >= 150)
        throw Bureaucrat::GradeTooHighException();
    this->_grade++;
    std::cout << CYAN << "Grade decreased to grade " << this->getGrade() << RESET << std::endl;
    return ;
}

std::ostream    &operator << (std::ostream &out, Bureaucrat const &b)
{
    out << b.getName() << ", bureaucrat grade " << b.getGrade();
    return (out);
}
