/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blefebvr <blefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 16:05:18 by root              #+#    #+#             */
/*   Updated: 2023/10/03 15:15:39 by blefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
    public:
        ShrubberyCreationForm(std::string target);
        ShrubberyCreationForm(ShrubberyCreationForm const &p);
        virtual ~ShrubberyCreationForm();
        
        ShrubberyCreationForm  &operator=(ShrubberyCreationForm const &b);
        
        virtual void		execute(const Bureaucrat &executor) const;
         std::string const   getTarget(void)const;
    
    private:
        std::string _target;
};

void    printTree(int n, std::ofstream &file);
void    printSpaces(int n, std::ofstream &file);
std::ostream &operator<<(std::ostream &c, const ShrubberyCreationForm &b);

#endif