/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-stef <adi-stef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 11:08:44 by adi-stef          #+#    #+#             */
/*   Updated: 2023/05/06 10:26:16 by adi-stef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
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
		void	operator = (Fixed const &fixed);
		Fixed	operator + (Fixed const &fixed);
		Fixed	operator - (Fixed const &fixed);
		Fixed	operator * (Fixed const &fixed);
		Fixed	operator / (Fixed const &fixed);
		bool	operator < (Fixed const &fixed) const;
		bool	operator > (Fixed const &fixed) const;
		bool	operator <= (Fixed const &fixed) const;
		bool	operator >= (Fixed const &fixed) const;
		bool	operator == (Fixed const &fixed) const;
		bool	operator != (Fixed const &fixed) const;
		Fixed	&operator ++ (void); // prefix
		Fixed	operator ++ (int); // postfix
		Fixed	&operator -- (void); // prefix
		Fixed	operator -- (int); // postfix
		// functions
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		int		toInt(void) const;
		float	toFloat(void) const;
		static Fixed		&min(Fixed &f1, Fixed &f2);
		static Fixed		&max(Fixed &f1, Fixed &f2);
		static Fixed const	&min(Fixed const &f1, Fixed const &f2);
		static Fixed const	&max(Fixed const &f1, Fixed const &f2);
	private:
		int					_value;
		static const int	_fbits;
};

std::ostream	&operator<<(std::ostream &out, const Fixed &fixed);

#endif
