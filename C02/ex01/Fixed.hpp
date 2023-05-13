/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-stef <adi-stef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 11:08:44 by adi-stef          #+#    #+#             */
/*   Updated: 2023/05/04 15:08:50 by adi-stef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <complex>
# include <iomanip>
# include <cmath>

class Fixed
{
	public:
		Fixed(void);
		Fixed(Fixed const &fixed); // copy constructor
		Fixed(int const i); // int constructor
		Fixed(float const f); // float constructor
		~Fixed(void);
		void				operator=(const Fixed &fixed);
		// functions
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		int		toInt(void) const;
		float	toFloat(void) const;
	private:
		int					_value;
		static const int	_fbits;
};

std::ostream	&operator<<(std::ostream &out, const Fixed &fixed);

#endif
