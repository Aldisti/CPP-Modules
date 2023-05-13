/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-stef <adi-stef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 11:25:35 by adi-stef          #+#    #+#             */
/*   Updated: 2023/05/08 11:07:19 by adi-stef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main( void )
{
	Fixed	a(4);
	Fixed	b(5.05f);
	Fixed	c(b);
	bool	cond;

	std::cout << "a = " << a << std::endl;
	std::cout << "b = " << b << std::endl;
	std::cout << "c = " << c << std::endl;

	std::cout << std::endl;

	std::cout << a << " + " << b << " = " << a + b << std::endl;
	std::cout << a << " - " << b << " = " << a - b << std::endl;
	std::cout << a << " * " << b << " = " << a * b << std::endl;
	std::cout << b << " / " << a << " = " << b / a << std::endl;

	std::cout << std::endl;

	cond = c < b;
	std::cout << c << " < " << b << " = " << cond << std::endl;
	cond = c > b;
	std::cout << c << " > " << b << " = " << cond << std::endl;
	cond = a < b;
	std::cout << a << " < " << b << " = " << cond << std::endl;
	cond = c > a;
	std::cout << c << " > " << a << " = " << cond << std::endl;
	cond = c <= b;
	std::cout << c << " <= " << b << " = " << cond << std::endl;
	cond = c >= b;
	std::cout << c << " >= " << b << " = " << cond << std::endl;
	cond = c == b;
	std::cout << c << " == " << b << " = " << cond << std::endl;
	cond = c == a;
	std::cout << c << " == " << a << " = " << cond << std::endl;

	std::cout << std::endl;

	std::cout << a++ << " a++ " << a << std::endl;
	std::cout << b++ << " b++ " << b << std::endl;
	std::cout << a-- << " a-- " << a << std::endl;
	std::cout << b-- << " b-- " << b << std::endl;

	std::cout << std::endl;

	std::cout << ++a << " ++a " << a << std::endl;
	std::cout << ++b << " ++b " << b << std::endl;
	std::cout << --a << " --a " << a << std::endl;
	std::cout << --b << " --b " << b << std::endl;

	return 0;
}