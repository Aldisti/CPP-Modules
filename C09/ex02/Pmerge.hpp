/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pmerge.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-stef <adi-stef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 15:07:34 by adi-stef          #+#    #+#             */
/*   Updated: 2023/06/16 12:37:13 by adi-stef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#define PRINTABLES 7

#include <stdlib.h>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <ctime>
#include <list>

class Pmerge
{
	public:
		static void	sort(std::string av);
		// ERRORS
		class InvalidArguments: public std::exception
        {
            public:
                virtual const char* what() const throw()
                { return ("Invalid arguments"); }
        };
	private:
		Pmerge(void);
		Pmerge(Pmerge const &p);
		~Pmerge(void);
		Pmerge	&operator = (Pmerge const &p);
		// FUNCTIONS
		static void	merge(std::vector<int> &v, std::vector<int> &tmp, int start, int end);
		static void	merge(std::list<int> &v, int start, int end);
		static std::vector<int>	getVect(std::string av);
		static std::list<int>	getList(std::string av);
		template <typename T>
		static T				getArr(std::string av);
		static bool				checkAv(std::string str);
		template <typename T>
		static void				print(T v);
};

template <typename T>
void	Pmerge::print(T v)
{
	int	j = 0;
	for (typename T::iterator i = v.begin(); i != v.end() && j < PRINTABLES; i++)
	{
		std::cout << *i << " ";
		j++;
	}
	if (j == PRINTABLES && (int)v.size() > j)
		std::cout << "[...]";
	std::cout << std::endl;
}

template <typename T>
T	Pmerge::getArr(std::string av)
{
	T		tmp;
	double	n;
	int		i = 0, j = 0;

	while (j < (int)av.size())
	{
		if ((i = av.find(32, j)) == -1)
			i = av.size();
		n = atof(av.substr(j, i - j + 1).c_str());
		if (n > 2147483647 || n < 0)
			throw (Pmerge::InvalidArguments());
		tmp.push_back(n);
		j = i + 1;
	}
	return (tmp);
}
