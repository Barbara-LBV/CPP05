/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 13:11:01 by root              #+#    #+#             */
/*   Updated: 2023/09/11 15:48:31 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <string>
#include <stdexcept>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include "Bureaucrat.hpp"

# define DEFAULT "\001\033[0;39m\002"
# define RED "\001\033[1;91m\002"
# define YELLOW "\001\033[1;93m\002"
# define MAGENTA "\001\033[1;95m\002"
# define BOLD "\001\033[1;89m\002"
# define GREEN "\001\033[1;92m\002"
# define BLUE "\001\033[1;36m\002"

class Bureaucrat;

class AForm
{
    public:
        AForm(std::string const &name, int const gradeSigned, int const gradeExec);
        AForm(AForm const &b);
        virtual ~AForm();

        AForm &operator=(AForm const &b);

        std::string const   &getName(void)const;
        int const           &getGradeSigned(void)const;
        int const           &getGradeExec(void)const;
        bool const          &getSigned(void)const;
        void                setSigned(int i);
        void                beSigned(Bureaucrat b);
        void                checkGrade(void)const;
        virtual void        execute(Bureaucrat const &executor)const = 0;

    private:
        AForm(); // why in private ?
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
			return (MAGENTA "The execution or signed grade for the Form is too high" DEFAULT);
		}
	};

	class GradeTooLowException : public std::exception
	{
	public:
		virtual const char* what() const throw()
		{
			return (MAGENTA "The execution or signed grade for the Form is too low" DEFAULT);
		}
	};

    class CantExecuteForm : public std::exception
	{
	public:
		virtual const char* what() const throw()
		{
			return ("The form cannot be executed, either because it wasn't sign"
					"ed, or because the executor has a rank too low");
		}
	};
	
	class CantOpenFile: public std::exception
	{
	public:
		virtual const char* what() const throw()
		{
			return ("Couldn't create _shrubbery File");
		}
	};
};

std::ostream &operator<<(std::ostream &c, const AForm &f);

#endif