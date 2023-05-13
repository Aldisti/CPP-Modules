/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-stef <adi-stef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 12:44:21 by adi-stef          #+#    #+#             */
/*   Updated: 2023/05/01 15:59:34 by adi-stef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <iomanip>

class Zombie
{
	public:
		Zombie(void);
		~Zombie(void);
		// Functions
		void		announce(void);
		std::string	getName(void) const;
		void		setName(std::string name);
	private:
		std::string	_name;
};

Zombie	*zombieHorde(int N, std::string name);

#endif
