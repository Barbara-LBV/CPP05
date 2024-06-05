/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blefebvr <blefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 13:10:28 by root              #+#    #+#             */
/*   Updated: 2023/10/11 15:52:19 by blefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name(""), _grade (0)
{
    std::cout << BLUE "Bureaucrat Default Constructor -> called" DEFAULT << std::endl;
}

Bureaucrat::Bureaucrat(std::string const &name, int grade) : _name(name), _grade(grade)
{
    std::cout << BLUE "Bureaucrat Parametric Constructor -> called" DEFAULT << std::endl;
    _grade = grade;
    checkGrade();
}

Bureaucrat::Bureaucrat(Bureaucrat const &b)
{
    std::cout << BLUE "Bureaucrat Copy Constructor -> called" DEFAULT << std::endl;
    *this = b;
}

Bureaucrat::~Bureaucrat()
{
    std::cout << RED "Bureaucrat Destructor -> called" DEFAULT << std::endl;
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &b)
{
     std::cout << BLUE "Bureaucrat Assignement Operator -> called" DEFAULT << std::endl;
    if (this != &b)
        _grade = b._grade;
    b.getName();
    checkGrade();
    return (*this);
}

std::ostream &operator<<(std::ostream &c, const Bureaucrat &b)
{
    c << b.getName() << " Bureaucrat has a " << b.getGrade();
    return (c);
}

std::string const    &Bureaucrat::getName(void)const
{
    return (this->_name);
}

int Bureaucrat::getGrade(void)const
{
    return (this->_grade);
}

void    Bureaucrat::incrementGrade(int grade)
{
    int rank = getGrade() - grade;
    setGrade(rank);
}

void Bureaucrat::decrementGrade(int grade)
{
    int rank = getGrade() + grade;
    setGrade(rank);
}

void    Bureaucrat::setGrade(int nb)
{
    this->_grade = nb;
    checkGrade();
}

void   Bureaucrat::checkGrade(void)const
{
    if (this->_grade < Bureaucrat::_highestGrade)
		throw Bureaucrat::GradeTooHighException();
	else if (this->_grade > Bureaucrat::_lowestGrade)
        throw Bureaucrat::GradeTooLowException();
}

void	Bureaucrat::signForm(AForm &f)
{
	try
	{
		f.beSigned(*this);
		std::cout << this->_name << " signs " << f.getName() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << this->_name << " can't sign " << f.getName()
			<< " because it hasn't the requested grade." << std::endl;
		std::cout << e.what() << std::endl;
	}
}

void    Bureaucrat::executeForm(AForm const &form)
{
    try
	{
        form.execute(*this);
		std::cout << this->getName() << " executed the " << form.getName() << DEFAULT << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}