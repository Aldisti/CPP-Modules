/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-stef <adi-stef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 17:47:55 by adi-stef          #+#    #+#             */
/*   Updated: 2023/05/08 17:48:25 by adi-stef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

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

class WrongAnimal
{
	public:
		WrongAnimal(void); // void constructor
		WrongAnimal(std::string type); // string constructor
		WrongAnimal(WrongAnimal const &a); // copy constructor
		~WrongAnimal(void); // destructor
		// operator overload
		void	operator = (WrongAnimal const &a);
		// accessors
		std::string	getType(void) const;
		// functions
		void	makeSound(void) const;
	protected:
		std::string	_type;
};

#endif
