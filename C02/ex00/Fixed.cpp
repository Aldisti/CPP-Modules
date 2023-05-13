/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-stef <adi-stef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 11:08:54 by adi-stef          #+#    #+#             */
/*   Updated: 2023/05/04 15:03:35 by adi-stef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int	Fixed::_fbits = 8;

Fixed::Fixed(void) : _value(0)
{
	std::cout << "\033[1;32m" << "Default constructor called" << "\033[0m" << std::endl;
	return ;
}

Fixed::Fixed(Fixed const &fixed)
{
	std::cout << "\033[1;32m" << "Copy constructor called" << "\033[0m" << std::endl;
	*this = fixed;
	return ;
}

Fixed::~Fixed(void)
{
	std::cout << "\033[1;31m" << "Destructor called" << "\033[0m" << std::endl;
	return ;
}

void	Fixed::operator=(const Fixed &fixed)
{
	std::cout << "\033[1;35m" << "Copy assignment operator called" << "\033[0m" << std::endl;
	this->_value = fixed.getRawBits();
	return ;
}

int		Fixed::getRawBits(void) const
{
	std::cout << "\033[1;36m" << "getRawBits member function called" << "\033[0m" << std::endl;
	return (this->_value);
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << "\033[1;36m" << "setRawBits member function called" << "\033[0m" << std::endl;
	this->_value = raw;
	return ;
}
