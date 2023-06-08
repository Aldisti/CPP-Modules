/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-stef <adi-stef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 17:15:15 by adi-stef          #+#    #+#             */
/*   Updated: 2023/06/02 17:34:31 by adi-stef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

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
void	swap(T &a, T &b)
{
	T	tmp = a;

	a = b;
	b = tmp;
};

template <typename T>
T	min(T a, T b)
{
	if (a < b)
		return (a);
	return (b);
};

template <typename T>
T	max(T a, T b)
{
	if (a > b)
		return (a);
	return (b);
};

#endif