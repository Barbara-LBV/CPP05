/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blefebvr <blefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 13:11:01 by root              #+#    #+#             */
/*   Updated: 2023/10/06 12:28:36 by blefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
#include <stdexcept>
#include "Bureaucrat.hpp"

# define DEFAULT "\001\033[0;39m\002"
# define RED "\001\033[1;91m\002"
# define YELLOW "\001\033[1;93m\002"
# define MAGENTA "\001\033[1;95m\002"
# define BOLD "\001\033[1;89m\002"
# define GREEN "\001\033[1;92m\002"
# define BLUE "\001\033[1;36m\002"

class Bureaucrat;

class Form
{
    public:
        Form();
        Form(std::string const &name, int const gradeSigned, int const gradeExec);
        Form(Form const &b);
        ~Form();

        Form &operator=(Form const &b);

        virtual std::string const   &getName(void)const;
        int const                   &getGradeSigned(void)const;
        int const                   &getGradeExec(void)const;
        bool const                  &getSigned(void)const;
        void                        setSigned(int i);
        void                        beSigned(Bureaucrat const &b);
        void                        checkGrades(void)const;
        void                        checkExec(const Bureaucrat &b)const;
        

    private:
        std::string const   _name;
        int const           _gradeSigned;
        int const           _gradeExec;
        bool                _signed;
        static const int	_lowestGrade = 150;
	    static const int	_highestGrade = 1;
    
    public:

	class GradeTooHighException : public std::exception
	{
	public:
		virtual const char* what() const throw()
		{
			return (MAGENTA "-> The Form can't be signed, Bureaucrat's grade is too high <-" DEFAULT);
		}
	};

	class GradeTooLowException : public std::exception
	{
	public:
		virtual const char* what() const throw()
		{
			return (MAGENTA "-> The Form can't be signed, Bureaucrat's grade is too low <-" DEFAULT);
		}
	};

    class CantExecuteForm : public std::exception
	{
	public:
		virtual const char* what() const throw()
		{
			return ("The Form can't be executed.");
		}
	};
};

std::ostream &operator<<(std::ostream &c, const Form &f);

#endif