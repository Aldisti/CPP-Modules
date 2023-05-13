/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-stef <adi-stef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 17:38:34 by adi-stef          #+#    #+#             */
/*   Updated: 2023/05/10 11:36:36 by adi-stef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int	main(void)
{
	Animal	*zoo[10];
	Cat		cat;
	Cat		cpy_cat = cat;
	Dog		dog;
	Dog		cpy_dog = dog;

	for (int i = 0; i < 5; i++)
		zoo[i] = new Cat();
	
	for (int i = 5; i < 10; i++)
		zoo[i] = new Dog();

	for (int i = 0; i < 10; i++)
		delete zoo[i];

	return (0);
}
