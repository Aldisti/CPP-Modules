/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-stef <adi-stef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 16:02:43 by adi-stef          #+#    #+#             */
/*   Updated: 2023/05/02 17:00:40 by adi-stef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>

int	main(int ac, const char **av)
{
	std::string	string = "Ciao come stai?";
	std::string	*stringPTR = &string;
	std::string	&stringREF = string;

	(void)av;
	if (ac != 1)
	{
		std::cerr << "Too many arguments!" << std::endl;
		return (1);
	}
	std::cout << "\033[1;32m" << "string\033[32m    address \033[0m" << &string << std::endl;
	std::cout << "\033[1;36m" << "stringPTR\033[36m address  \033[0m" << &stringPTR << std::endl;
	std::cout << "\033[1;35m" << "stringREF\033[35m address  \033[0m" << &stringREF << std::endl;
	std::cout << "\033[1;32m" << "string\033[32m    value    \033[0m" << string << std::endl;
	std::cout << "\033[1;36m" << "stringPTR\033[36m value    \033[0m" << *stringPTR << std::endl;
	std::cout << "\033[1;35m" << "stringREF\033[35m value    \033[0m" << stringREF << std::endl;
}
