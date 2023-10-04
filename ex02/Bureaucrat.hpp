/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarival <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 21:05:05 by ymarival          #+#    #+#             */
/*   Updated: 2023/09/27 21:05:05 by ymarival         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <cstdlib>
#include "Form.hpp"

class Form;

class Bureaucrat
{
    private:
        const std:: string _name;
        int         _grade;

        Bureaucrat();

    public:
        Bureaucrat(const std::string& name, int grade);
        Bureaucrat(const Bureaucrat& src);
        ~Bureaucrat();
        
        Bureaucrat& operator=(const Bureaucrat& src);

        std::string getName() const;
        int         getGrade() const;

        void        incrementGrade();
        void        decrementGrade();

        void        signForm(Form& form);

        void        executeForm(const Form& form)const;

        class GradeTooHighException : public std::exception
        {
            public:
                virtual const char* what() const throw() {
                    return ("Grade is too high");
                };
        };

        class GradeTooLowException : public std::exception
        {
            public:
                virtual const char* what() const throw() {
                    return ("Grade is too low");
                };
        };
};

std::ostream& operator<<(std::ostream& o, const Bureaucrat& rhs);

#endif