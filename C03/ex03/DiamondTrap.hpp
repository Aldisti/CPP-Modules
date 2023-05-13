/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-stef <adi-stef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 15:09:10 by adi-stef          #+#    #+#             */
/*   Updated: 2023/05/08 15:46:39 by adi-stef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

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
# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class DiamondTrap : virtual public ScavTrap, virtual public FragTrap
{
	public:
		DiamondTrap(void); // void constructor
		DiamondTrap(std::string name); // default constructor
		DiamondTrap(DiamondTrap const &ct); // copy constructor
		~DiamondTrap(void); // default destructor
		// accessors
		std::string	getName(void) const;
		// functions
		void		whoAmI(void);
		using	ScavTrap::attack;
	private:
		std::string	_name;
};

#endif
