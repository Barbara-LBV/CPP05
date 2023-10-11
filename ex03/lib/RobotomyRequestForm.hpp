/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blefebvr <blefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 16:05:33 by root              #+#    #+#             */
/*   Updated: 2023/10/06 13:00:14 by blefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
    public:
        RobotomyRequestForm(std::string target);
        RobotomyRequestForm(RobotomyRequestForm const &p);
        virtual ~RobotomyRequestForm();
        
        RobotomyRequestForm  &operator=(RobotomyRequestForm const &b);

        virtual void		execute(Bureaucrat const &executor) const;
        std::string const   getTarget(void)const;
    
    private:
        std::string _target;
};

#endif
