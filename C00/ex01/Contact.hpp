/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-stef <adi-stef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 14:51:21 by adi-stef          #+#    #+#             */
/*   Updated: 2023/04/30 15:47:13 by adi-stef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <iomanip>
# include <cctype>

# ifndef DATA
#  define DATA 5
# endif

class Contact
{
	public:
		// Constructor&Destructor
		Contact(void);
		~Contact(void);
		// Functions
		size_t		getIndex(void) const;
		std::string	getValue(size_t index) const;
		void		display(void) const;
		void		getData(size_t index);
	private:
		// Member variables
		size_t				_index;
		std::string			_values[DATA];
		static std::string	_types[DATA];
};

#endif
