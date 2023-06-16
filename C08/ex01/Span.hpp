/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-stef <adi-stef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 22:47:13 by adi-stef          #+#    #+#             */
/*   Updated: 2023/06/09 11:21:57 by adi-stef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# ifndef COLORS
#  define COLORS
#  define PURPLE "\033[1;35m"
#  define GREEN "\033[1;32m"
#  define CYAN "\033[1;36m"
#  define RED "\033[1;31m"
#  define RESET "\033[0m"
# endif

# include <algorithm>
# include <iostream>
# include <iterator>
# include <numeric>
# include <vector>

class Span
{
	public:
		Span(unsigned int n);
		Span(Span const &s);
		~Span(void);
		Span		&operator = (Span const &s);
		int	const	&operator [] (int index) const;
		// METHODS
		void			addNumber(int n);
		int				size(void) const;
		unsigned int	longestSpan(void) const;
		unsigned int	shortestSpan(void) const;
		template <typename T>
		void			addIter(T start, T end);
		// ERRORS
		class MaxSizeException: public std::exception
        {
            public:
                virtual const char	*what() const throw()
				{ return ("Max size reached"); };
        };
		class SpanException: public std::exception
        {
            public:
                virtual const char	*what() const throw()
				{ return ("Can't calculate the span"); };
        };
		class IndexOutOfBounds: public std::exception
        {
            public:
                virtual const char	*what() const throw()
				{ return ("Index out of bounds"); };
        };
	private:
		std::vector<int>	_a;
		int					_size;
		unsigned int		_maxSize;
};

std::ostream    &operator << (std::ostream &out, Span const &a);

template <typename T>
void	Span::addIter(T start, T end)
{
	if (std::distance(start, end) + this->_size > this->_maxSize)
		throw Span::MaxSizeException();
	if (std::distance(start, end) <= 0)
		return ;
	for (; start != end; start++)
		this->addNumber(*start);
	return ;
}

#endif
