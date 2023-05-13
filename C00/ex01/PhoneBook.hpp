/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-stef <adi-stef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 15:47:24 by adi-stef          #+#    #+#             */
/*   Updated: 2023/04/30 15:57:57 by adi-stef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <iomanip>
# include <cctype>
# include "Contact.hpp"

# ifndef SIZE
#  define SIZE 8
# endif
# ifndef PAD
#  define PAD 10
# endif

class PhoneBook
{
	public:
		// Constructor&Destructor
		PhoneBook(void);
		~PhoneBook(void);
		// Functions
		void	add(void);
		void	search(void);
	private:
		Contact	_contacts[8];
		size_t	_nbContacts;
		size_t	_next;
};

#endif
