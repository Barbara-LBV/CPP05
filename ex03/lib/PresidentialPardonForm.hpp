/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blefebvr <blefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 16:05:55 by root              #+#    #+#             */
/*   Updated: 2023/10/05 14:19:03 by blefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
    public:
        PresidentialPardonForm(std::string target);
        PresidentialPardonForm(PresidentialPardonForm const &p);
        virtual ~PresidentialPardonForm();
        PresidentialPardonForm  &operator=(PresidentialPardonForm const &b);

        virtual void		execute(Bureaucrat const &executor) const;
        std::string const   getTarget(void)const;
         
    private:
        std::string _target;
};

#endif