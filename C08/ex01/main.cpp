/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-stef <adi-stef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 15:39:42 by adi-stef          #+#    #+#             */
/*   Updated: 2023/06/09 16:26:44 by adi-stef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

#define ELEM 16

int	main(void)
{
	Span	s(ELEM);

	for (int i = 0; i < ELEM / 2; i++)
		s.addNumber(rand());

	std::cout << "My longest span: " << s.longestSpan() << std::endl;
	std::cout << "My shortest span: " << s.shortestSpan() << std::endl;

	std::vector<int>	tmp;

	tmp.resize(ELEM / 2);
	for (int i = 0; i < ELEM / 2; i++)
		tmp[i] = i;

	s.addIter(tmp.begin(), tmp.end());

	std::cout << "My longest span: " << s.longestSpan() << std::endl;
	std::cout << "My shortest span: " << s.shortestSpan() << std::endl;

	std::cout << s << std::endl;

	return (0);
}
