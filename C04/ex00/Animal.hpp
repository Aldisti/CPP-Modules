/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-stef <adi-stef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 17:18:54 by adi-stef          #+#    #+#             */
/*   Updated: 2023/05/08 17:43:01 by adi-stef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

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

class Animal
{
	public:
		Animal(void); // void constructor
		Animal(std::string type); // string constructor
		Animal(Animal const &a); // copy constructor
		virtual ~Animal(void); // destructor
		// operator overload
		void	operator = (Animal const &a);
		// accessors
		std::string	getType(void) const;
		// functions
		virtual void	makeSound(void) const;
	protected:
		std::string	_type;
};

#endif
