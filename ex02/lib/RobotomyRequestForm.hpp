/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 16:05:33 by root              #+#    #+#             */
/*   Updated: 2023/09/09 16:14:17 by root             ###   ########.fr       */
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

        virtual void		execute(const Bureaucrat &executor) const;
         std::string const   getTarget(void)const;
    
    private:
        std::string _target;
};

std::ostream &operator<<(std::ostream &c, const RobotomyRequestForm &b);

#endif
