/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-stef <adi-stef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 14:32:41 by adi-stef          #+#    #+#             */
/*   Updated: 2023/06/02 15:21:01 by adi-stef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

Base::~Base(void) { return ; }

A::~A(void) { std::cout << " - " << GREEN << "A" << RESET << std::endl; }

B::~B(void) { std::cout << " - " << GREEN << "B" << RESET << std::endl; }

C::~C(void) { std::cout << " - " << GREEN << "C" << RESET << std::endl; }

Base	*generate(void)
{
	switch (rand() % 3)
	{
		case 0:
			return (new A());
		case 1:
			return (new B());
		case 2:
			return (new C());
	}
	return (NULL);
}

void	identify(Base *p)
{
	if (dynamic_cast<A*>(p))
		std::cout << CYAN << "A" << RESET;
	else if (dynamic_cast<B*>(p))
		std::cout << CYAN << "B" << RESET;
	else
		std::cout << CYAN << "C" << RESET;
}

void	identify(Base &p)
{
	try
	{
		dynamic_cast<A&>(p);
		std::cout << CYAN << "A" << RESET;
	}
	catch (std::exception &e)
	{
		try
		{
			dynamic_cast<B&>(p);
			std::cout << CYAN << "B" << RESET;
		}
		catch (std::exception &e)
		{
			std::cout << CYAN << "C" << RESET;
		}
	}
}

int	main(void)
{
	Base	*tmp;

	for (int i = 0; i < 10; i++)
	{
		tmp = generate();
		identify(tmp);
		identify(*tmp);
		delete tmp;
	}
	return (0);
}
