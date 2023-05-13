/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-stef <adi-stef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 17:00:46 by adi-stef          #+#    #+#             */
/*   Updated: 2023/05/09 17:42:46 by adi-stef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# ifndef COLORS
#  define COLORS
#  define PURPLE "\033[1;35m"
#  define GREEN "\033[1;32m"
#  define CYAN "\033[1;36m"
#  define RED "\033[1;31m"
#  define RESET "\033[0m"
# endif

# include <iostream>
# include <iomanip>
# include <string>
# include "Character.hpp"
# include "Materia.hpp"

class IMateriaSource
{
	public:
		IMateriaSource(void);
		IMateriaSource(const IMateriaSource& ims);
		virtual ~IMateriaSource(void);
		void	operator = (IMateriaSource const &ims);
		virtual void		learnMateria(AMateria*) = 0;
		virtual AMateria	*createMateria(std::string const & type) = 0;
};

class MateriaSource : public IMateriaSource
{
	public:
		MateriaSource(void);
		MateriaSource(MateriaSource const &ms);
		~MateriaSource(void);
		void		operator = (MateriaSource const &ms);
		void		learnMateria(AMateria *m);
		AMateria	*createMateria(std::string const &type);
	private:
		AMateria	*_known[4];
};

#endif
