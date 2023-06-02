/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-stef <adi-stef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 16:39:06 by adi-stef          #+#    #+#             */
/*   Updated: 2023/05/23 17:29:12 by adi-stef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main( void )
{
	try
	{
		Bureaucrat bureaucrat("Efesto", 2);
		ShrubberyCreationForm form1("Asta");
		RobotomyRequestForm form2("Minosse");
		PresidentialPardonForm form3("President");
		Intern	schiavo;
		AForm	*form;

		std::cout << "\n--------------- Form 1 ( Shrubbery ) ---------------" << std::endl;
		bureaucrat.signForm(form1);
		bureaucrat.executeForm(form1);
		std::cout << "\n--------------- Form 2 ( Robotomy ) ---------------" << std::endl;
		bureaucrat.signForm(form2);
		bureaucrat.executeForm(form2);
		bureaucrat.executeForm(form2);
		bureaucrat.executeForm(form2);
		bureaucrat.executeForm(form2);
		bureaucrat.executeForm(form2);
		bureaucrat.executeForm(form2);
		bureaucrat.executeForm(form2);
		bureaucrat.executeForm(form2);
		std::cout << "\n--------------- Form 3 ( President ) ---------------" << std::endl;
		bureaucrat.signForm(form3);
		bureaucrat.executeForm(form3);
		std::cout << "\n---------------------- Intern ---------------------" << std::endl;
		form = schiavo.makeForm("robotomy request", "form1");
		std::cout << form->getTarget() << std::endl;
		schiavo.makeForm("'wrong request'", "form2");
		delete form;
	}
	catch (std::exception &e){ std::cout << e.what() << std::endl; }
	return (0);
}
