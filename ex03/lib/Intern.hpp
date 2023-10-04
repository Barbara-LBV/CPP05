/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blefebvr <blefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 18:18:23 by root              #+#    #+#             */
/*   Updated: 2023/10/04 16:30:52 by blefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"

class Intern
{
  public:
    Intern();
    Intern(Intern const &i);
    virtual ~Intern();

    Intern &operator=(Intern const &b);
    
    AForm   *makeForm(std::string formName, std::string target);    
};

std::ostream &operator<<(std::ostream &c, const Intern &i);

#endif