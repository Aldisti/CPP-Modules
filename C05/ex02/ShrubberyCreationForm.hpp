/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-stef <adi-stef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 16:54:09 by adi-stef          #+#    #+#             */
/*   Updated: 2023/05/20 17:22:53 by adi-stef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# ifndef COLORS
#  define COLORS
#  define PURPLE "\033[1;35m"
#  define GREEN "\033[1;32m"
#  define CYAN "\033[1;36m"
#  define RED "\033[1;31m"
#  define RESET "\033[0m"
# endif

# include <iostream>
# include <fstream>
# include <string>
# include <iomanip>
# include "AForm.hpp"
# include "Bureaucrat.hpp"

class AForm;

class ShrubberyCreationForm: public AForm
{
	public:
		ShrubberyCreationForm(std::string target); // constructor
		ShrubberyCreationForm(ShrubberyCreationForm const &scf); // copy constructor
		~ShrubberyCreationForm(void); // destructor
		void	operator = (ShrubberyCreationForm const &scf); // copy operator
		// accessors
		std::string	getTarget(void) const;
		// functions
		void	execute(Bureaucrat const &b) const;
	private:
		std::string	_target;
};

#endif
