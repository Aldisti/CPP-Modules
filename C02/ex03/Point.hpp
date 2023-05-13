/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-stef <adi-stef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 18:46:08 by adi-stef          #+#    #+#             */
/*   Updated: 2023/05/05 19:06:55 by adi-stef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include <iostream>
# include <iomanip>
# include <cmath>
# include "Fixed.hpp"

class Point
{
	public:
		Point(void); // default constructor
		Point(Point const &p); // copy constructor
		Point(float const x, float const y); // float constructor
		~Point(void); // default destructor
		void	operator = (Point const &p);
		Fixed	getX(void) const;
		Fixed	getY(void) const;
	private:
		Fixed const	_x;
		Fixed const	_y;
};

bool	bsp( Point const a, Point const b, Point const c, Point const point);

#endif
