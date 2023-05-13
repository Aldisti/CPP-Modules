/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-stef <adi-stef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 19:04:52 by adi-stef          #+#    #+#             */
/*   Updated: 2023/05/06 11:09:02 by adi-stef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

// Area=∣x1∗(y2−y3)+x2∗(y3−y1)+x3∗(y1−y2)∣/2
Fixed	area(Point const p1, Point const p2, Point const p3)
{
    Fixed   n = (p1.getX() * (p2.getY() - p3.getY()) + p2.getX() * (p3.getY() - p1.getY()) + p3.getX() * (p1.getY() - p2.getY()));
    if (n < 0.0f)
        return (n * -1);
    return (n);
}

bool	bsp( Point const a, Point const b, Point const c, Point const point)
{
	Fixed	A, a1, a2, a3;

    A = area(a, b, c);
    a1 = area(point, a, b);
    a2 = area(point, b, c);
    a3 = area(point, c, a);

    // std::cout << "A: " << A << std::endl;
    // std::cout << "1: " << a1 << std::endl;
    // std::cout << "2: " << a2 << std::endl;
    // std::cout << "3: " << a3 << std::endl;

    if (A - (a1 + a2 + a3) >= 0.015f || A - (a1 + a2 + a3) < 0.0f)
        return (false);
    if (a1 == 0.0f || a2 == 0.0f || a3 == 0.0f)
        return (false);
    return (true);
}

/*
Fixed	ft_dist(Point const p1, Point const p2)
{
    return ((p1.getX() - p2.getX()) * (p1.getX() - p2.getX()) + (p1.getY() - p2.getY()) * (p1.getY() - p2.getY()));
}

bool	bsp( Point const a, Point const b, Point const c, Point const point)
{
    Fixed   ab(ft_dist(a, b)), bc(ft_dist(b, c)), ca(ft_dist(c, a));
    (void)point;
    std::cout << "1: " << ab << std::endl;
    std::cout << "2: " << bc << std::endl;
    std::cout << "3: " << ca << std::endl;

    return (true);
}
*/
