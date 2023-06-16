/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-stef <adi-stef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 22:05:53 by adi-stef          #+#    #+#             */
/*   Updated: 2023/06/03 22:12:34 by adi-stef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main(void)
{
	int	arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

	std::vector< int >      vect( arr, arr + sizeof( arr ) / sizeof( int ) );
	std::list< int >        list( arr, arr + sizeof( arr ) / sizeof( int ) );

	easyfind(vect, 2);
	easyfind(list, 7);

	easyfind(vect, 11);
	easyfind(list, -1);

	return (0);
}
