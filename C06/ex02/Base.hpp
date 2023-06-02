/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-stef <adi-stef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 14:31:48 by adi-stef          #+#    #+#             */
/*   Updated: 2023/06/02 15:03:11 by adi-stef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
# define BASE_HPP

# ifndef COLORS
#  define COLORS
#  define PURPLE "\033[1;35m"
#  define GREEN "\033[1;32m"
#  define CYAN "\033[1;36m"
#  define RED "\033[1;31m"
#  define RESET "\033[0m"
# endif

# include <stdlib.h>
# include <iostream>
# include <string>

class Base
{
	public:
		virtual ~Base(void);
};

class A: public Base
{
	public:
		~A(void);
};

class B: public Base
{
	public:
		~B(void);
};

class C: public Base
{
	public:
		~C(void);
};

#endif