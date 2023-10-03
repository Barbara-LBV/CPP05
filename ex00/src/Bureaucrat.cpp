/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blefebvr <blefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 13:10:28 by root              #+#    #+#             */
/*   Updated: 2023/10/02 15:22:59 by blefebvr         ###   ########.fr       */
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
    checkGrade();
    return (*this);
}

std::ostream &operator<<(std::ostream &c, const Bureaucrat &b)
{
    c << b.getGrade();
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

void    Bureaucrat::checkGrade(void)const
{
    if (this->_grade < Bureaucrat::highestGrade)
		throw Bureaucrat::GradeTooHighException();
	else if (this->_grade > Bureaucrat::lowestGrade)
		throw Bureaucrat::GradeTooLowException();
}
