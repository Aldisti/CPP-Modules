/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pmerge.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-stef <adi-stef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 15:22:49 by adi-stef          #+#    #+#             */
/*   Updated: 2023/06/16 12:36:22 by adi-stef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pmerge.hpp"

Pmerge::Pmerge(void)
{};

Pmerge::Pmerge(Pmerge const &p)
{ *this = p; }

Pmerge::~Pmerge(void)
{}

Pmerge	&Pmerge::operator = (Pmerge const &p)
{
	(void)p;
	return (*this);
}

void	Pmerge::sort(std::string av)
{
	std::vector<int>	v;
	std::vector<int>	tmp;
	std::list<int>		l;
	clock_t				t;

	if (!Pmerge::checkAv(av))
		throw (Pmerge::InvalidArguments());

	std::cout << std::fixed << std::setprecision(3);

	v = Pmerge::getArr<std::vector<int> >(av);
	tmp.resize(v.size());
	l = Pmerge::getArr<std::list<int> >(av);

	std::cout << "Before:	";
	Pmerge::print(v);

	t = clock();
	Pmerge::merge(v, tmp, 0, v.size() - 1);
	t = clock() - t;

	std::cout << "After:	";
	Pmerge::print(v);
	std::cout << "Time to process a range of " << v.size()
	<< " elements with std::vector : " << (((double)t) / CLOCKS_PER_SEC) * 1000
	<< " ms" << std::endl;
	std::cout << "Before:	";
	Pmerge::print(l);

	t = clock();
	Pmerge::merge(l, 0, l.size() - 1);
	t = clock() - t;

	std::cout << "After:	";
	Pmerge::print(l);
	std::cout << "Time to process a range of " << l.size()
	<< " elements with std::list : " << (((double)t) / CLOCKS_PER_SEC) * 1000
	<< " ms" << std::endl;
}

void	Pmerge::merge(std::vector<int> &v, std::vector<int> &tmp, int start, int end)
{
	if (!(end - start))
		return ;

	int	ls = start, re = end;
	int	le = (start + end) / 2;
	int	rs = (start + end) / 2 + 1;
	int	i;

	merge(v, tmp, ls, le);
	merge(v, tmp, rs, re);

	i = 0;
	while (ls <= le && rs <= re)
		tmp[i++] = (v[ls] < v[rs]) ? v[ls++] : v[rs++];
	while (ls <= le)
		tmp[i++] = v[ls++];
	while (rs <= re)
		tmp[i++] = v[rs++];
	i = 0;
	while (start <= end)
		v[start++] = tmp[i++];
}

void	Pmerge::merge(std::list<int> &v, int start, int end)
{
	if (!(end - start))
		return ;

	merge(v, start, (start + end) / 2);
	merge(v, (start + end) / 2 + 1, end);

	std::list<int>::iterator	ls, le, rs, re, s;
	std::list<int>	tmp;

	s = v.begin();
	ls = v.begin();
	le = v.begin();
	rs = v.begin();
	re = v.begin();

	std::advance(s, start);
	std::advance(ls, start);
	std::advance(le, (start + end) / 2);
	std::advance(rs, (start + end) / 2 + 1);
	std::advance(re, end);

	int	i, j;

	i = std::distance(ls, le);
	j = std::distance(rs, re);

	while (i >= 0 && j >= 0)
		if (*ls < *rs)
		{
			tmp.push_back(*ls++);
			i--;
		}
		else
		{
			tmp.push_back(*rs++);
			j--;
		}
	while (i-- >= 0)
		tmp.push_back(*ls++);
	while (j-- >= 0)
		tmp.push_back(*rs++);
	while (tmp.size() > 0)
	{
		*s++ = tmp.front();
		tmp.pop_front();
	}
}

// std::vector<int>	Pmerge::getVect(std::string av)
// {
// 	std::vector<int>	tmp;
// 	double				n;
// 	int					i = 0, j = 0;

// 	while (j < (int)av.size())
// 	{
// 		if ((i = av.find(32, j)) == -1)
// 			i = av.size();
// 		n = atof(av.substr(j, i - j + 1).c_str());
// 		if (n > 2147483647 || n < 0)
// 			throw (Pmerge::InvalidArguments());
// 		tmp.push_back(n);
// 		j = i + 1;
// 	}
// 	return (tmp);
// }

// std::list<int>	Pmerge::getList(std::string av)
// {
// 	std::list<int>	tmp;
// 	double			n;
// 	int				i = 0, j = 0;

// 	while (j < (int)av.size())
// 	{
// 		if ((i = av.find(32, j)) == -1)
// 			i = av.size();
// 		n = atof(av.substr(j, i - j + 1).c_str());
// 		if (n > 2147483647 || n < 0)
// 			throw (Pmerge::InvalidArguments());
// 		tmp.push_back(n);
// 		j = i + 1;
// 	}
// 	return (tmp);
// }

bool	Pmerge::checkAv(std::string str)
{
	for (int i = 0; i < (int)str.size(); i++)
	{
		if (!isdigit(str[i]) && std::string(" +-").find(str[i]) == std::string::npos)
			return (false);
		else if (std::string("+-").find(str[i]) != std::string::npos
			&& (i == (int)str.size() - 1 || !isdigit(str[i + 1])))
			return (false);
	}
	return (true);
}
