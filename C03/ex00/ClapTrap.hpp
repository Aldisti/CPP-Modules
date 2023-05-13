/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-stef <adi-stef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 12:27:12 by adi-stef          #+#    #+#             */
/*   Updated: 2023/05/08 14:24:21 by adi-stef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# ifndef COLORS
#  define GREEN "\033[1;32m"
#  define RED "\033[1;31m"
#  define CYAN "\033[1;36m"
#  define PURPLE "\033[1;35m"
#  define RESET "\033[0m"
# endif

# include <iostream>
# include <iomanip>
# include <string>

class ClapTrap
{
	public:
		ClapTrap(void); // void constructor
		ClapTrap(std::string name); // default constructor
		ClapTrap(ClapTrap const &ct); // copy constructor
		~ClapTrap(void); // default destructor
		void	operator = (ClapTrap const &ct); // copy operator overloading
		// accessors
		std::string	getName(void) const;
		int			getHp(void) const;
		int			getEp(void) const;
		int			getAtk(void) const;
		// functions
		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
	private:
		std::string	_name;
		int			_hp;
		int			_ep;
		int			_atk;
};

#endif
