/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-stef <adi-stef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 16:00:18 by adi-stef          #+#    #+#             */
/*   Updated: 2023/05/11 17:26:03 by adi-stef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

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

class Bureaucrat
{
    public:
        Bureaucrat(std::string name, int grade); // constructor
        Bureaucrat(Bureaucrat const &b); // copy constructor
        ~Bureaucrat(void); // destructor
        void    operator = (Bureaucrat const &b); // copy operator overload
        // accessors
        std::string getName(void) const;
        int         getGrade(void) const;
        // member functions
        void        incGrade(void); // 15 -> 14
        void        decGrade(void); // 15 -> 16
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
    private:
        std::string const   _name;
        int                 _grade;
};

std::ostream    &operator << (std::ostream &out, Bureaucrat const &b);

#endif
