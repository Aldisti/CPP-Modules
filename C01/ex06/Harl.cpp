/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-stef <adi-stef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 14:26:19 by adi-stef          #+#    #+#             */
/*   Updated: 2023/05/02 16:44:17 by adi-stef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

// I W D E % 10
// 3 7 8 9 % 7
// 3 0 1 2

void	Harl::complain(std::string level)
{
	void	(Harl::*p[4])() = {&Harl::_warning, &Harl::_debug, &Harl::_error, &Harl::_info};

	switch (level[0] % 10 % 7)
	{
		case 1:
			(this->*p[1])();
		case 3:
			(this->*p[3])();
		case 0:
			(this->*p[0])();
		case 2:
			(this->*p[2])();
			break ;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
	return ;
}

void	Harl::_debug(void)
{
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger." << std::endl;
	std::cout << "I really do!\n" << std::endl;
	return ;
}

void	Harl::_info(void)
{
	std::cout << "[ INFO ]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money." << std::endl;
	std::cout << "You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!\n" << std::endl;
	return ;
}

void	Harl::_warning(void)
{
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free." << std::endl;
	std::cout << "I've been coming for years whereas you started working here since last month.\n" << std::endl;
	return ;
}

void	Harl::_error(void)
{
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now.\n" << std::endl;
	return ;
}

Harl::Harl(void)
{
	return ;
}

Harl::~Harl(void)
{
	return ;
}
