/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-stef <adi-stef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 16:39:06 by adi-stef          #+#    #+#             */
/*   Updated: 2023/05/11 18:18:07 by adi-stef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void)
{
    Bureaucrat  a("Franco", 5);
    Bureaucrat  b("Mario", 145);

    for (int i = 0; i < 4; i++)
        a.incGrade();
    for (int i = 0; i < 5; i++)
        b.decGrade();
    
    try { a.incGrade(); }
    catch (std::exception &e) { std::cout << PURPLE << "INC exception caught" << RESET << std::endl; }

    try { b.decGrade(); }
    catch (std::exception &e) { std::cout << PURPLE << "DEC exception caught" << RESET << std::endl; }

    try { Bureaucrat  c("Test", 0); }
    catch (std::exception &e) { std::cout << PURPLE << "INV_CON exception caught" << RESET << std::endl; }

    try { Bureaucrat  c("Test", 151); }
    catch (std::exception &e) { std::cout << PURPLE << "INV_CON exception caught" << RESET << std::endl; }

	return (0);
}
