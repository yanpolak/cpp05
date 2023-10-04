/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarival <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 22:48:22 by ymarival          #+#    #+#             */
/*   Updated: 2023/09/25 22:48:22 by ymarival         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
    private:
        const std::string   _name;
        bool                _signed;
        const int           _gradeToSign;
        const int           _gradeToExecute;

        Form();
    
    public:
        Form(const std::string& name, int gradeToSign);
        Form(const std::string& name, int gradeToSign, int gradeToExecute);
        Form(const Form& src);
        ~Form();
        
        Form& operator=(const Form& rhs);

        std::string getName() const;
        bool        getSigned() const;
        int         getGradeToSign() const;
        int         getGradeToExecute() const;

        void        beSigned(const Bureaucrat& bureaucrat);

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

std::ostream& operator<<(std::ostream& o, const Form& rhs);

#endif
