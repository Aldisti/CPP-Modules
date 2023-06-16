/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-stef <adi-stef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 22:00:39 by adi-stef          #+#    #+#             */
/*   Updated: 2023/06/08 10:10:45 by adi-stef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# ifndef COLORS
#  define COLORS
#  define PURPLE "\033[1;35m"
#  define GREEN "\033[1;32m"
#  define CYAN "\033[1;36m"
#  define RED "\033[1;31m"
#  define RESET "\033[0m"
# endif

# include <iostream>
# include <string>
# include <algorithm>
# include <vector>
# include <list>

template <typename T>
void	easyfind(T const &c, int n)
{
	
	if (std::find(c.begin(), c.end(), n) != c.end())
		std::cout << GREEN << "[" << n << "]" << " found!" << RESET << std::endl;
	else
		std::cout << RED << "[" << n << "]" << " not found!" << RESET << std::endl;
	return ;
};

#endif