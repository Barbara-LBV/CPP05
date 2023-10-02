/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 16:05:55 by root              #+#    #+#             */
/*   Updated: 2023/09/09 16:14:13 by root             ###   ########.fr       */
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

        virtual void		execute(const Bureaucrat &executor) const;
         std::string const   getTarget(void)const;
         
    private:
        std::string _target;
};

std::ostream &operator<<(std::ostream &c, const PresidentialPardonForm &b);

#endif