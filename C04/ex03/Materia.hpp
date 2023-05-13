/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Materia.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-stef <adi-stef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 15:38:43 by adi-stef          #+#    #+#             */
/*   Updated: 2023/05/09 17:54:24 by adi-stef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIA_HPP
# define MATERIA_HPP

# ifndef COLORS
#  define COLORS
#  define PURPLE "\033[1;35m"
#  define GREEN "\033[1;32m"
#  define CYAN "\033[1;36m"
#  define RED "\033[1;31m"
#  define RESET "\033[0m"
# endif

# include <iostream>
# include <iomanip>
# include <string>
# include "Character.hpp"

class ICharacter;

class AMateria
{
	protected:
		std::string	_type;
	public:
		AMateria(void); // void constructor
		AMateria(std::string const & type); // default constructor
		AMateria(AMateria const &am); // copy constructor
		virtual ~AMateria(void); // destructor
		void	operator = (AMateria const &am); // copy operator overload
		// accessors
		std::string const & getType() const; //Returns the materia type
		// member functions
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
};

class Ice: public AMateria
{
	public:
		Ice(void); // default constructor
		Ice(Ice const &i); // copy constructor
		~Ice(void); // destructor
		void	operator = (Ice const &i); // copy operator overload
		// member functions
		AMateria	*clone() const;
		void		use(ICharacter &target);
};

class Cure: public AMateria
{
	public:
		Cure(void); // default constructor
		Cure(Cure const &i); // copy constructor
		~Cure(void); // destructor
		void	operator = (Cure const &i); // copy operator overload
		// member functions
		AMateria	*clone() const;
		void		use(ICharacter &target);
};

#endif
