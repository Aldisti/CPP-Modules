/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-stef <adi-stef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 11:24:01 by adi-stef          #+#    #+#             */
/*   Updated: 2023/06/17 16:22:32 by adi-stef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>
#include <stack>

class RPN
{
	public:
		RPN(std::string const &av);
		RPN(RPN const &rpn);
		~RPN(void);
		RPN	&operator = (RPN const &rpn);
		// METHODS
		int		getOut(void) const;
		void	calculate(void);
		template <typename T>
		void	doOp(std::stack<T>	&s, char op);
		// ERRORS
		class InvalidOperator: public std::exception
        {
            public:
                virtual const char* what() const throw()
                { return ("Invalid operator"); }
        };
	private:
		// ATTRIBUTES
		std::string	_line;
		int			_ops;
		int			_out;
};

RPN::RPN(std::string const &av): _line(av), _ops(0), _out(0)
{
	if (av.size() <= 0)
		throw (RPN::InvalidOperator());
	for (int i = 0; i < (int)av.size(); i++)
	{
		if (!isdigit(av[i]) && std::string("+-*/ ").find(av[i]) == std::string::npos)
			throw (RPN::InvalidOperator());
		if (std::string("+-*/").find(av[i]) != std::string::npos
			&& i + 1 != (int)av.size() && av[i + 1] != 32)
			throw (RPN::InvalidOperator());
		if (isdigit(av[i]) && !isdigit(av[i + 1]) && av[i + 1] != 32)
			throw (RPN::InvalidOperator());
	}
}

RPN::RPN(RPN const &rpn)
{ *this = rpn; }

RPN::~RPN(void)
{ }

RPN	&RPN::operator = (RPN const &rpn)
{
	if (this == &rpn)
		return (*this);
	this->_line = rpn._line;
	this->_ops = rpn._ops;
	this->_out = rpn._out;
	return (*this);
}

int	RPN::getOut(void) const
{ return (this->_out); }

void	RPN::calculate(void)
{
	std::stack<int>	s;
	std::string		tmp;
	int				i = 0, j = 0;

	while (42)
	{
		if (j >= (int)this->_line.size())
			break ;
		i = this->_line.find(32, j);
		if (i == -1)
			i = this->_line.size();
		tmp = this->_line.substr(j, i - j + 1);
		if (!tmp[0])
			break ;
		j = i + 1;
		if (std::string("+-*/").find(tmp[0]) != std::string::npos)
		{
			this->doOp(s, tmp[0]);
			this->_ops++;
			continue ;
		}
		s.push(atof(tmp.c_str()));
	}
	this->_out = s.top();
}

template <typename T>
void	RPN::doOp(std::stack<T> &s, char op)
{
	T	a, b;

	if (!s.size())
		throw (RPN::InvalidOperator());
	b = s.top();
	s.pop();
	if (!s.size())
		throw (RPN::InvalidOperator());
	a = s.top();
	s.pop();
	switch (op % 10)
	{
		case 2:
			s.push(a * b); // *
			break ;
		case 3:
			s.push(a + b); // -
			break ;
		case 5:
			s.push(a - b); // +
			break ;
		case 7:
			s.push(a / b); // /
			break ;
	}
}
