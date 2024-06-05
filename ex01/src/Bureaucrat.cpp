/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blefebvr <blefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 13:10:28 by root              #+#    #+#             */
/*   Updated: 2023/11/23 12:48:22 by blefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Default B."), _grade (150)
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
    c << b.getName() << " Bureaucrat has a " << b.getGrade() << " grade." << std::endl;
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

 void    Bureaucrat::checkGrade(void)const
{
    try
    {
        //std::cout << "1/ in check grade bureaucrate\n";
        if (this->_grade < 1)
            throw Bureaucrat::GradeTooHighException();
        else if (this->_grade > 150)
            throw Bureaucrat::GradeTooLowException();
      //  std::cout << "2/ in check grade bureaucrate\n";
    }
    catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
    
}

void	Bureaucrat::signForm(Form &f)
{
	try
	{
		f.beSigned(*this);
		std::cout << this->_name << " signed " << f.getName() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << this->_name << " can't sign " << f.getName()
			<< " because they don't have the required grade." << std::endl;
		std::cout << e.what() << std::endl;
	}
}
