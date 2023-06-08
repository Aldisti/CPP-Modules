/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-stef <adi-stef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 17:36:58 by adi-stef          #+#    #+#             */
/*   Updated: 2023/06/02 17:48:22 by adi-stef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

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
# include <cctype>

template <typename T>
void	iter(T *arr, int len, void (*fun)(T &))
{
	for (int i = 0; i < len; i++)
		fun(arr[i]);
}

template <typename T>
void	print(T elem)
{ std::cout << elem << std::endl; }

#endif
