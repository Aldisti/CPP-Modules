/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-stef <adi-stef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 15:50:50 by adi-stef          #+#    #+#             */
/*   Updated: 2023/05/09 17:56:17 by adi-stef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# ifndef COLORS
#  define COLORS
#  define PURPLE "\033[1;35m"
#  define GREEN "\033[1;32m"
#  define CYAN "\033[1;36m"
#  define RED "\033[1;31m"
#  define RESET "\033[0m"
# endif

# ifndef SIZE
#  define SIZE 4
# endif

# include <iostream>
# include <iomanip>
# include <string>
# include "Materia.hpp"

class AMateria;

class ICharacter
{
	public:
		ICharacter(void);
		ICharacter(ICharacter const &ic);
		virtual ~ICharacter(void);
		void	operator=(ICharacter const &ic);
		virtual std::string const & getName(void) const = 0;
		virtual void equip(AMateria* m) = 0;
		virtual void unequip(int index) = 0;
		virtual void use(int index, ICharacter& target) = 0;
};

class Character : public ICharacter
{
	public:
		Character(std::string const &name);
		Character(Character const &c);
		~Character(void);
		void	operator=(Character const &c);
		std::string const	&getName(void) const;
		void	equip(AMateria *m);
		void	unequip(int index);
		void	use(int index, ICharacter &target);
	private:
		std::string	_name;
		AMateria	*_inventory[SIZE];
};

#endif
