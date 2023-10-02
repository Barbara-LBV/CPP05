/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 18:18:23 by root              #+#    #+#             */
/*   Updated: 2023/09/11 18:23:13 by root             ###   ########.fr       */
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
    
    AForm   makeForm(std::string name, std::string target);    
};

std::ostream &operator<<(std::ostream &c, const Intern &i);

#endif