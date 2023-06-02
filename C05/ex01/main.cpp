/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-stef <adi-stef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 16:39:06 by adi-stef          #+#    #+#             */
/*   Updated: 2023/05/11 18:17:56 by adi-stef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
    Bureaucrat  a("Tutore", 5);
    Bureaucrat  b("Alunno", 145);
	Form		c("Nota", 50, 100);

	std::cout << c << std::endl;
	b.signForm(c);
	std::cout << c << std::endl;
	a.signForm(c);
	std::cout << c << std::endl;

	return (0);
}
