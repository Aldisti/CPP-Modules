/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-stef <adi-stef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 17:34:21 by adi-stef          #+#    #+#             */
/*   Updated: 2023/05/08 17:37:09 by adi-stef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

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
# include "Animal.hpp"

class Dog: public Animal
{
	public:
		Dog(void); // void constructor
		Dog(std::string type); // string constructor
		Dog(Dog const &c); // copy constructor
		~Dog(void); // destructor
		// functions
		void	makeSound(void) const;
};

#endif