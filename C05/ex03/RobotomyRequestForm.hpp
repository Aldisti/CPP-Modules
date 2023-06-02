/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-stef <adi-stef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 17:17:48 by adi-stef          #+#    #+#             */
/*   Updated: 2023/05/20 17:29:10 by adi-stef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# ifndef COLORS
#  define COLORS
#  define PURPLE "\033[1;35m"
#  define GREEN "\033[1;32m"
#  define CYAN "\033[1;36m"
#  define RED "\033[1;31m"
#  define RESET "\033[0m"
# endif

# include <iostream>
# include <cstdlib>
# include <string>
# include <iomanip>
# include "AForm.hpp"
# include "Bureaucrat.hpp"

class AForm;

class RobotomyRequestForm: public AForm
{
	public:
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(RobotomyRequestForm const &rrf);
		~RobotomyRequestForm(void);
		void	operator = (RobotomyRequestForm const &rrf);
		// accessors
		std::string	getTarget(void) const;
		// functions
		void	execute(Bureaucrat const &b) const;
	private:
		std::string	_target;
};

#endif
