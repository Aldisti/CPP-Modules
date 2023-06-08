/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-stef <adi-stef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 09:19:18 by adi-stef          #+#    #+#             */
/*   Updated: 2023/06/08 16:08:55 by adi-stef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# ifndef COLORS
#  define COLORS
#  define PURPLE "\033[1;35m"
#  define GREEN "\033[1;32m"
#  define CYAN "\033[1;36m"
#  define RED "\033[1;31m"
#  define RESET "\033[0m"
# endif

# include <iostream>
# include <string>
# include <cctype>

template <typename T>
void	swap(T &a, T &b)
{
	T	tmp = a;
	a = b;
	b = tmp;
};

template <typename T>
class Array
{
	public:
		Array(void);
		Array(unsigned int n);
		Array(Array const &a);
		~Array(void);
		// OPERATORS
		Array	&operator = (Array const &a);
		T		&operator [] (int index);
		T const	&operator [] (int index) const;
		Array	&operator + (Array const &a);
		bool	operator == (Array const &a) const;
		bool	operator != (Array const &a) const;
		void	operator += (Array const &a);
		// METHODS
		int		size(void) const;
		T		&max(void) const;
		T		min(void) const;
		void	append(T value);
		int		count(T value) const;
		int		index(T value) const;
		void	remove(T value, int times = 1);
		void	insert(int index, T value);
		void	reverse(void);
		void	sort(void);
		// ERRORS
		class IndexOutOfBounds: public std::exception
        {
            public:
                virtual const char	*what() const throw()
				{ return ("Index out of bounds"); };
        };
	private:
		T	*_arr;
		int	_size;
};

template <typename T>
Array<T>::Array(void): _arr(0), _size(0)
{
	return ;
};

template <typename T>
Array<T>::Array(unsigned int n): _arr(new T[n]), _size(n)
{
	for (int i = 0; i < (int)n; i++)
		this->_arr[i] = 0;
	return ;
};

template <typename T>
Array<T>::Array(Array<T> const &a): _arr(0), _size(0)
{
	*this = a;
	return ;
};

template <typename T>
Array<T>::~Array(void)
{
	delete [] this->_arr;
	return ;
};

template <typename T>
std::ostream    &operator << (std::ostream &out, Array<T> const &a)
{
	out << "[";
	for (int i = 0; i < (int)a.size(); i++)
	{
		out << a[i];
		if (i != (int)a.size() - 1)
			out << ", ";
	}
	out << "]";
	return (out);
}

template <typename T>
Array<T>	&Array<T>::operator = (Array<T> const &a)
{
	if (this == &a)
		return (*this);
	delete [] this->_arr;
	this->_arr = new T[a.size()];
	this->_size = a.size();
	for (int i = 0; i < this->_size; i++)
		this->_arr[i] = a._arr[i];
	return (*this);
}

template <typename T>
T	&Array<T>::operator [] (int index)
{
	if (index < 0)
		index += this->_size;
	if (index >= this->_size || index < 0)
		throw Array::IndexOutOfBounds();
	return (this->_arr[index]);
}

template <typename T>
T const	&Array<T>::operator [] (int index) const
{
	if (index < 0)
		index += this->_size;
	if (index >= this->_size || index < 0)
		throw Array::IndexOutOfBounds();
	return (this->_arr[index]);
}

template <typename T>
Array<T>	&Array<T>::operator + (Array<T> const &a)
{
	Array<T>	*tmp = new Array<T>(this->_size + a.size());
	for (int i = 0; i < this->_size; i++)
		(*tmp)[i] = this->_arr[i];
	for (int i = 0; i < a._size; i++)
		(*tmp)[i + this->_size] = a[i];
	return (*tmp);
}

template <typename T>
bool	Array<T>::operator == (Array<T> const &a) const
{
	if (this->size() != a.size())
		return (false);
	for (int i = 0; i < this->_size; i++)
		if ((*this)[i] != a[i])
			return (false);
	return (true);
}

template <typename T>
bool	Array<T>::operator != (Array<T> const &a) const
{
	int	c = 0;
	if (this->size() != a.size())
		return (true);
	for (int i = 0; i < this->_size; i++)
		c += ((*this)[i] == a[i]);
	return (c != this->_size);
}

template <typename T>
void	Array<T>::operator += (Array<T> const &a)
{
	T	*tmp = new T[this->_size + a.size()];
	for (int i = 0; i < this->_size; i++)
		tmp[i] = this->_arr[i];
	for (int i = 0; i < a._size; i++)
		tmp[i + this->_size] = a[i];
	delete [] this->_arr;
	this->_arr = tmp;
	this->_size += a.size();
}

/*
RETURN
Returns the size of the array.
*/
template <typename T>
int	Array<T>::size(void) const
{
	return (this->_size);
}

/*
RETURN
Returns the reference to the highest value in the array.
*/
template <typename T>
T	&Array<T>::max(void) const
{
	T	tmp = 0;
	for (int i = 1; i < this->_size; i++)
		if (this->_arr[i] > this->_arr[tmp])
			tmp = i;
	return (this->_arr[tmp]);
}

/*
RETURN
Returns the reference to the smallest value in the array.
*/
template <typename T>
T	Array<T>::min(void) const
{
	T	tmp = 0;
	for (int i = 1; i < this->_size; i++)
		if (this->_arr[i] < this->_arr[tmp])
			tmp = i;
	return (this->_arr[tmp]);
};

/*
DESCRIPTION
Adds an element at the end of the array.
*/
template <typename T>
void	Array<T>::append(T value)
{
	T	*tmp = new T[this->_size + 1];
	for (int i = 0; i < this->_size; i++)
		tmp[i] = this->_arr[i];
	tmp[this->_size++] = value;
	delete [] this->_arr;
	this->_arr = tmp;
};

/*
DESCRITPION
Returns the number of elements with the specified value.
*/
template <typename T>
int	Array<T>::count(T value) const
{
	int	c = 0;
	for (int i = 0; i < this->_size; i++)
		c += (this->_arr[i] == value);
	return (c);
};

/*
DESCRIPTION
Returns the index of the first element with the specified value,
if not found returns 0.
*/
template <typename T>
int	Array<T>::index(T value) const
{
	if (this->_size == 0)
		return (-1);
	for (int i = 0; i < this->_size; i++)
		if (this->_arr[i] == value)
			return (i);
	return (-1);
};

/*
DESCRIPTION
This function removes [times] elements with [value] value from the array.
if [times] is -1 than will remove all the occurences of [value] in the array.
*/
template <typename T>
void	Array<T>::remove(T value, int times)
{
	if (!times)
		return ;
	int	toRemove = 0;
	int	c = this->count(value);
	toRemove = (times >= 0 && times <= c) ? times : c;
	T	*tmp = new T[this->_size - toRemove];
	int	j = 0;
	for (int i = 0; i < this->_size; i++)
	{
		if (this->_arr[i] == value && toRemove-- > 0)
			continue ;
		tmp[j++] = this->_arr[i];
	}
	delete [] this->_arr;
	this->_arr = tmp;
	this->_size = j;
};

/*
DESCRIPTION
Adds an element at the specified position.
*/
template <typename T>
void	Array<T>::insert(int index, T value)
{
	if (index < 0)
		index += this->_size;
	if (index < 0)
		index = 0;
	if (index > this->_size)
		index = this->_size;
	T	*tmp = new T[this->_size + 1];
	this->_size++;
	int	j = 0;
	for (int i = 0; i < this->_size; i++)
	{
		if (i == index)
			tmp[i] = value;
		else
			tmp[i] = this->_arr[j++];
	}
	delete [] this->_arr;
	this->_arr = tmp;
};

/*
DESCRIPTION
Reverses the order of the array.
*/
template <typename T>
void	Array<T>::reverse(void)
{
	T	*tmp = new T[this->_size];
	for (int i = 0; i < this->_size; i++)
		tmp[i] = this->_arr[this->_size - 1 - i];
	delete [] this->_arr;
	this->_arr = tmp;
}

/*
DESCRIPTION
Sorts the array with an optimized version of bubble sort.
*/
template <typename T>
void	Array<T>::sort(void)
{
	bool	swapped;
	for (int i = 0; i < this->_size - 1; i++)
	{
		swapped = false;
		for (int j = 0; j < this->_size - i - 1; j++)
		{
			if (this->_arr[j] > this->_arr[j + 1])
			{
				swap(this->_arr[j], this->_arr[j + 1]);
				swapped = true;
			}
		}
		if (!swapped)
			break;
	}
}

#endif