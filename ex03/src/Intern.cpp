/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 18:23:41 by root              #+#    #+#             */
/*   Updated: 2023/09/12 11:21:44 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/Intern.hpp"

Intern::Intern(){};

Intern::Intern(Intern const &i)
{
    *this = i;
}

Intern::~Intern(){}

Intern &Intern::operator=(Intern const &b)
{
    if (*this != b)
        
}

AForm   Intern::makeForm(std::string name, std::string target)
{
    AForm f;
    
    
}