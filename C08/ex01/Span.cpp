/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-stef <adi-stef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 23:02:07 by adi-stef          #+#    #+#             */
/*   Updated: 2023/06/09 11:21:28 by adi-stef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(unsigned int n): _size(0), _maxSize(n)
{
	this->_a.resize(n);
	return ;
}

Span::Span(Span const &s)
{
	*this = s;
	return ;
}

Span::~Span(void)
{
	return ;
}

std::ostream    &operator << (std::ostream &out, Span const &a)
{
	out << "[";
	for (int i = 0; i < a.size(); i++)
	{
		out << a[i];
		if (i != a.size() - 1)
			out << ", ";
	}
	out << "]";
	return (out);
}

Span	&Span::operator = (Span const &s)
{
	if (this == &s)
		return (*this);
	this->_a = s._a;
	this->_maxSize = s._maxSize;
	this->_size = s._size;
	return (*this);
}

int	const	&Span::operator [] (int index) const
{
	if (index < 0 || index >= this->_size)
		throw Span::IndexOutOfBounds();
	return (this->_a[index]);
}

void	Span::addNumber(int n)
{
	if (this->_size == (int)this->_maxSize)
		throw Span::MaxSizeException();
	this->_a.at(this->_size++) = n;
	return ;
}

int	Span::size(void) const
{
	return (this->_size);
}

unsigned int	Span::longestSpan(void) const
{
	std::vector<int>	tmp = this->_a;
	int					diff = -1;

	for (std::vector<int>::iterator i = tmp.begin(); i != tmp.end() - 1; i++)
		if (std::abs(*i - *(i + 1)) > diff)
			diff = std::abs(*i - *(i + 1));
	return (diff);
}

unsigned int	Span::shortestSpan(void) const
{
	std::vector<int>	tmp = this->_a;
	int					diff = 2147483647;

	for (std::vector<int>::iterator i = tmp.begin(); i != tmp.end() - 1; i++)
		if (std::abs(*i - *(i + 1)) < diff)
			diff = std::abs(*i - *(i + 1));
	return (diff);
}
