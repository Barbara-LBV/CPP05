/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blefebvr <blefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 12:54:15 by root              #+#    #+#             */
/*   Updated: 2023/10/06 11:19:14 by blefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <stdexcept>
#include "Form.hpp"

# define DEFAULT "\001\033[0;39m\002"
# define RED "\001\033[1;91m\002"
# define YELLOW "\001\033[1;93m\002"
# define MAGENTA "\001\033[1;95m\002"
# define BOLD "\001\033[1;89m\002"
# define GREEN "\001\033[1;92m\002"
# define BLUE "\001\033[1;36m\002"

class Form;

class Bureaucrat
{
    public:
        Bureaucrat();
        Bureaucrat(std::string const &name, int grade);
        Bureaucrat(Bureaucrat const &b);
        ~Bureaucrat();

        Bureaucrat &operator=(Bureaucrat const &b);

        virtual std::string const    &getName(void)const;
        int                 getGrade(void)const;
        void                incrementGrade(int grade);
        void                decrementGrade(int grade);
        void                setGrade(int nb);
        void                signForm(Form &f);

    private:
        std::string const   _name;
        int                 _grade;
        void                checkGrade(void)const;
        static const int	_lowestGrade = 150;
	    static const int	_highestGrade = 1;

    public:

	class GradeTooHighException : public std::exception
	{
	public:
		virtual const char* what() const throw()
		{
			return (YELLOW "The Bureaucrat's grade is too high." DEFAULT);
		}
	};

	class GradeTooLowException : public std::exception
	{
	public:
		virtual const char* what() const throw()
		{
			return (YELLOW "The Bureaucrat's grade is too low" DEFAULT);
		}
	};
};

std::ostream &operator<<(std::ostream &c, const Bureaucrat &b);

#endif