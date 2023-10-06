/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blefebvr <blefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 10:51:33 by root              #+#    #+#             */
/*   Updated: 2023/10/06 12:39:08 by blefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("Shrub Form", 72, 45), _target(target)
{
    std::cout << YELLOW "ShrubberyCreationForm Parametrical Constructor -> called" DEFAULT << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &b) : AForm("Shrub Form", 72, 45)
{
    std::cout << YELLOW "ShrubberyCreationForm Copy Constructor -> called" DEFAULT << std::endl;
    *this = b;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &b)
{
     std::cout << YELLOW "ShrubberyCreationForm Assignement Operator -> called" DEFAULT << std::endl;
    if (this != &b)
        _target = b._target;
    checkGrade();
    return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout << RED "ShrubberyCreationForm Destructor -> called" DEFAULT << std::endl;
}

std::string const    ShrubberyCreationForm::getTarget(void)const
{
    return (_target);
}

void    ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
    if (executor.getGrade() == getGradeExec())
    {
        std::string filename = getTarget();
        filename.insert(filename.size(), "_shrubbery");
        std::ofstream file(filename.c_str());
        if (!file.is_open())
            throw AForm::CantOpenFile();
        printTree(3, file);
        std::cout << "Bureaucrat " << executor.getName() << " wrote trees in " << filename << " file."<< std::endl;
    }
    else
    {
		throw AForm::CantExecuteForm();
    }
}

void printSpaces(int n, std::ofstream &file)
{
    for (int i = 0; i < n; i++)
        file << " ";
}

void printTree(int n, std::ofstream &file) 
{
    for(int i = 0; i < n; i++)
    {
        printSpaces(5, file);
        file << "#" << std::endl;
        printSpaces(4, file);
        file << "###" << std::endl;
        printSpaces(3, file);
        file << "#####" << std::endl;
        printSpaces(2, file);
        file << "#######"  << std::endl;
        printSpaces(1, file);
        file << "#########"  << std::endl;
        printSpaces(4, file);
        file << "||" << std::endl << std::endl;
    }
    
}