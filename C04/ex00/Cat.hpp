/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-stef <adi-stef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 17:29:46 by adi-stef          #+#    #+#             */
/*   Updated: 2023/05/08 17:50:15 by adi-stef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

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

class Cat: public Animal
{
	public:
		Cat(void); // void constructor
		Cat(std::string type); // string constructor
		Cat(Cat const &c); // copy constructor
		~Cat(void); // destructor
		// functions
		void	makeSound(void) const;
};

#endif
