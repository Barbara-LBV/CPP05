/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blefebvr <blefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 13:10:28 by root              #+#    #+#             */
/*   Updated: 2023/10/04 14:03:13 by blefebvr         ###   ########.fr       */
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
    c << b.getName();
    return (c)
;}

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
    checkGrade();
}

void Bureaucrat::decrementGrade(int grade)
{
    int rank = getGrade() + grade;
    setGrade(rank);
    checkGrade();
}

void    Bureaucrat::setGrade(int nb)
{
    this->_grade = nb;
}

void   Bureaucrat::checkGrade(void)const
{
    if (this->_grade < Bureaucrat::_highestGrade)
    {
		throw Bureaucrat::GradeTooHighException();
        delete this;
    }
	else if (this->_grade > Bureaucrat::_lowestGrade)
	{
        throw Bureaucrat::GradeTooLowException();
        delete this;
    }
}

void    Bureaucrat::signForm(AForm const &f)
{
    if (f.getSigned() == 1)
        std::cout << BOLD << this->getName() << " signed " << f.getName() << DEFAULT << std::endl;
    else if (f.getSigned() == false && this->_grade < 1)
        std::cout << BOLD << this  << " couldn't sign " << f.getName() << " because grade is too high" << DEFAULT << std::endl;
    else if (f.getSigned() == false && this->_grade > 150)
        std::cout << BOLD << this << " couldn't sign " << f.getName() << " because grade is too low" << DEFAULT << std::endl;
}

bool    Bureaucrat::executeForm(AForm const &form)
{
    signForm(form);
    if (form.getSigned() == 1)
    {
        std::cout << BOLD << this->getName() << " executed " << form.getName() << DEFAULT << std::endl;
        form.execute(*this);
        return (true);
    }
    else
    {
        std::cout << BOLD << this->getName()  << " couldn't execute " << form.getName() << " because it hasn't been signed." << DEFAULT << std::endl;
        return (false);
    }
}