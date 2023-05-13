/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-stef <adi-stef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 17:25:10 by adi-stef          #+#    #+#             */
/*   Updated: 2023/05/02 11:40:03 by adi-stef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <iostream>
# include <iomanip>

class Weapon
{
	public:
		Weapon(std::string type);
		~Weapon(void);
		// functions
		const std::string	&getType(void);
		void				setType(std::string new_type);
	private:
		std::string	_type;
};

#endif
