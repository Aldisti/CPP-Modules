/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-stef <adi-stef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 11:08:54 by adi-stef          #+#    #+#             */
/*   Updated: 2023/05/04 18:41:57 by adi-stef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int	Fixed::_fbits = 8;

Fixed::Fixed(void) : _value(0)
{
	// std::cout << "\033[1;32m" << "Default constructor called" << "\033[0m" << std::endl;
	return ;
}

Fixed::Fixed(Fixed const &fixed)
{
	// std::cout << "\033[1;32m" << "Copy constructor called" << "\033[0m" << std::endl;
	*this = fixed;
	return ;
}

Fixed::Fixed(int const i)
{
	// std::cout << "\033[1;32m" << "Int constructor called" << "\033[0m" << std::endl;
	this->_value = i;
	this->_value <<= this->_fbits;
	return ;
}

Fixed::Fixed(float const f)
{
	// std::cout << "\033[1;32m" << "Float constructor called" << "\033[0m" << std::endl;
	this->_value = std::roundf(f * std::pow(2, this->_fbits));
	return ;
}

Fixed::~Fixed(void)
{
	// std::cout << "\033[1;31m" << "Destructor called" << "\033[0m" << std::endl;
	return ;
}

void	Fixed::operator = (Fixed const &fixed)
{
	// std::cout << "\033[1;35m" << "Copy assignment operator called" << "\033[0m" << std::endl;
	this->_value = fixed.getRawBits();
	return ;
}

int	Fixed::toInt(void) const
{
	return ((int)(this->_value >> this->_fbits));
}

float	Fixed::toFloat(void) const
{
	return ((float)(this->_value / std::pow(2, this->_fbits)));
}

int		Fixed::getRawBits(void) const
{
	return (this->_value);
}

void	Fixed::setRawBits(int const raw)
{
	this->_value = raw;
	return ;
}

std::ostream	&operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return (out);
}

// tmp.setRawBits(((this->toInt() + fixed.toInt()) << this->_fbits) + this->getRawBits() - (this->toInt() << this->_fbits) + fixed.getRawBits() - (fixed.toInt() << fixed._fbits));
// addition
Fixed	Fixed::operator + (Fixed const &fixed)
{
	Fixed	tmp;

	tmp.setRawBits(this->getRawBits() + fixed.getRawBits());
	return (tmp);
}

// subtraction
Fixed	Fixed::operator - (Fixed const &fixed)
{
	Fixed	tmp;

	tmp.setRawBits(this->getRawBits() - fixed.getRawBits());
	return (tmp);
}

// multiplication
Fixed	Fixed::operator * (Fixed const &fixed)
{
	Fixed	tmp;

	tmp.setRawBits((this->getRawBits() * fixed.getRawBits()) >> this->_fbits);
	return (tmp);
}

// division
Fixed	Fixed::operator / (Fixed const &fixed)
{
	Fixed	tmp;

	tmp.setRawBits((this->getRawBits() / (fixed.getRawBits() >> fixed._fbits)));
	return (tmp);
}

// lower
bool	Fixed::operator < (Fixed const &fixed) const
{
	return (this->getRawBits() < fixed.getRawBits());
}

// greater
bool	Fixed::operator > (Fixed const &fixed) const
{
	return (this->getRawBits() > fixed.getRawBits());
}

// lower or equal
bool	Fixed::operator <= (Fixed const &fixed)const
{
	return (this->getRawBits() <= fixed.getRawBits());
}

// greater or equal
bool	Fixed::operator >= (Fixed const &fixed) const
{
	return (this->getRawBits() >= fixed.getRawBits());
}

// equal
bool	Fixed::operator == (Fixed const &fixed) const
{
	return (this->getRawBits() == fixed.getRawBits());
}

// prefix ++
Fixed	&Fixed::operator ++ (void)
{
	this->_value++;
	return (*this);
}

// postfix ++
Fixed	Fixed::operator ++ (int)
{
	Fixed	tmp(*this);
	this->_value++;
	return (tmp);
}

// prefix --
Fixed	&Fixed::operator -- (void)
{
	this->_value--;
	return (*this);
}

// postfix --
Fixed	Fixed::operator -- (int)
{
	Fixed	tmp(*this);
	this->_value--;
	return (tmp);
}

Fixed	&Fixed::min(Fixed &f1, Fixed &f2)
{
	if (f1 > f2)
		return (f2);
	return (f1);
}

Fixed	&Fixed::max(Fixed &f1, Fixed &f2)
{
	if (f1 < f2)
		return (f2);
	return (f1);
}

Fixed const	&Fixed::min(Fixed const &f1, Fixed const &f2)
{
	if (f1 > f2)
		return (f2);
	return (f1);
}

Fixed const	&Fixed::max(Fixed const &f1, Fixed const &f2)
{
	if (f1 < f2)
		return (f2);
	return (f1);
}
