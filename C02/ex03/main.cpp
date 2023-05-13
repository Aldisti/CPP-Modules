/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-stef <adi-stef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 11:25:35 by adi-stef          #+#    #+#             */
/*   Updated: 2023/05/08 11:14:28 by adi-stef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int main( void )
{
	Point	a(2.5f, 1);
	Point	b(7.7f, 3);
	Point	c(4.85f, 5.895f);
	Point	p1(7.57f, 3);
	Point	p2(7.26f, 6);
	Point	p3(6.77f, 3.95f);

	std::cout << "p1 in abc: " << bsp(a, b, c, p1) << std::endl;
	std::cout << "p2 in abc: " << bsp(a, b, c, p2) << std::endl;
	std::cout << "p3 in abc: " << bsp(a, b, c, p3) << std::endl;
	std::cout << "a in abc: " << bsp(a, b, c, a) << std::endl;

	return (0);
}
