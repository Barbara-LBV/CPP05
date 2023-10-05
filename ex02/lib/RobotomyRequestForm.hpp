/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blefebvr <blefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 16:05:33 by root              #+#    #+#             */
/*   Updated: 2023/10/05 17:41:40 by blefebvr         ###   ########.fr       */
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

        void	        	execute(Bureaucrat const &executor) const;
         std::string const  getTarget(void)const;
    
    private:
        std::string _target;
};

#endif
