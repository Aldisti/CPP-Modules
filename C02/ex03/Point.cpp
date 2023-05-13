/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-stef <adi-stef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 18:46:06 by adi-stef          #+#    #+#             */
/*   Updated: 2023/05/06 10:54:05 by adi-stef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(void) : _x(0), _y(0)
{
	// std::cout << "\033[1;32m" << "Default constructor called" << "\033[0m" << std::endl;
	return ;
}

Point::Point(Point const &p)
{
	// std::cout << "\033[1;32m" << "Copy constructor called" << "\033[0m" << std::endl;
	*this = p;
	return ;
}

Point::Point(float const x, float const y) : _x(x), _y(y)
{
	// std::cout << "\033[1;32m" << "Float constructor called" << "\033[0m" << std::endl;
	return ;
}

Point::~Point(void)
{
	// std::cout << "\033[1;31m" << "Destructor called" << "\033[0m" << std::endl;
	return ;
}

void	Point::operator = (Point const &p)
{
	// std::cout << "\033[1;35m" << "Copy assignment operator called" << "\033[0m" << std::endl;
	if (this == &p)
		return ;
	Fixed	&x = const_cast<Fixed&>(this->_x);
	Fixed	&y = const_cast<Fixed&>(this->_y);
	x = p.getX();
	y = p.getY();
	return ;
}

Fixed	Point::getX(void) const
{
	return (this->_x);
}

Fixed	Point::getY(void) const
{
	return (this->_y);
}
