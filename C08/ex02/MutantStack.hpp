/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-stef <adi-stef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 16:58:40 by adi-stef          #+#    #+#             */
/*   Updated: 2023/06/09 15:15:35 by adi-stef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <algorithm>
#include <iterator>
#include <stack>

template <typename T>
class MutantStack: public std::stack<T>
{
	public:
		MutantStack(void): std::stack<T>() {};
		MutantStack(MutantStack const &ms): std::stack<T>(ms) {};
		~MutantStack(void) {};
		MutantStack	&operator = (MutantStack const &ms)
		{
			if (this == &ms)
				return (*this);
			this->c = ms.c;
			return (*this);
		};
		typedef typename std::stack<T>::container_type::iterator	iterator;
		iterator	begin(void) { return this->c.begin(); }
		iterator	end(void) { return this->c.end(); }
};
