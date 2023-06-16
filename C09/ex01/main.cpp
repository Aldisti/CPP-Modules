/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-stef <adi-stef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 17:42:55 by adi-stef          #+#    #+#             */
/*   Updated: 2023/06/14 11:08:50 by adi-stef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "Error\nType: 'invalid arguments'" << std::endl;
		return (1);
	}
	try
	{
		RPN	rpn(av[1]);
		rpn.calculate();
		std::cout << "Result is: [" << rpn.getOut() << "]" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << "Error\nType: '" << e.what() << "'" << std::endl;
	}
	return (0);
}
