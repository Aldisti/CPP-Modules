/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-stef <adi-stef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 17:28:57 by adi-stef          #+#    #+#             */
/*   Updated: 2023/05/20 16:40:56 by adi-stef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

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
# include <iomanip>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
    public:
		AForm(std::string name, int gradeSign, int gradeExec); // constructor
		AForm(AForm const &f); // copy constructor
		virtual ~AForm(void); // destructor
		void	operator = (AForm const &f); // copy operator
		// accessors
		std::string	getName(void) const;
		bool		getFirmed(void) const;
		int			getGradeSign(void) const;
		int			getGradeExec(void) const;
		// member functions
		void	beSigned(Bureaucrat const &b);
		virtual std::string	getTarget(void) const = 0;
		virtual void		execute(Bureaucrat const &b) const = 0;
		// exception classes
        class GradeTooHighException: public std::exception
        {
            public:
                virtual const char* what() const throw()
                { return ("Grade Too High"); }
        };
        class GradeTooLowException: public std::exception
        {
            public:
                virtual const char* what() const throw()
                { return ("Grade Too Low"); }
        };
		class FormNotSigned: public std::exception
        {
            public:
                virtual const char* what() const throw()
                { return ("Form not signed"); }
        };
    private:
		std::string	_name;
		bool		_firmed;
		int			_gradeSign;
		int			_gradeExec;
};

std::ostream	&operator << (std::ostream &out, AForm const &f);

#endif
