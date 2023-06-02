/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-stef <adi-stef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 12:13:02 by adi-stef          #+#    #+#             */
/*   Updated: 2023/06/02 12:35:16 by adi-stef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <stdint.h>
# include <iostream>
# include <iomanip>
# include <string>
# include <cctype>

typedef struct data
{
	std::string	data;
}	Data;

class Serializer
{
	public:
		Serializer(void);
		Serializer(Serializer const &s);
		~Serializer(void);
		Serializer	&operator = (Serializer const &s);
		// functions
		static uintptr_t	serialize(Data *ptr);
		static Data			*deserialize(uintptr_t raw);
};

#endif