/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-stef <adi-stef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 18:03:59 by adi-stef          #+#    #+#             */
/*   Updated: 2023/05/08 18:12:31 by adi-stef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

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
# include <iomanip>

class Brain
{
	public:
		Brain(void); // default constructor
		Brain(Brain const &b); // copy constructor
		~Brain(void); // default destructor
		// operator overload
		void	operator = (Brain const &b);
		// accessors
		std::string const	*getIdeas(void) const;
	private:
		std::string	ideas[100];
};

#endif
