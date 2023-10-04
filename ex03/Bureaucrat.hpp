/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarival <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 07:28:42 by ymarival          #+#    #+#             */
/*   Updated: 2023/09/30 07:28:42 by ymarival         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include "Form.hpp"
#include <cstdlib>
#include <cstddef>

class Form;

class Bureaucrat
{
private:
    const std::string   _name;
    int                 _grade;

    Bureaucrat();

public:
    Bureaucrat( const std::string& name, int grade );
    Bureaucrat( const Bureaucrat& src );
    ~Bureaucrat();

    Bureaucrat  &operator=( const Bureaucrat& rhs );

    std::string getName() const;
    int         getGrade() const;

    void        incrementGrade();
    void        decrementGrade();

    void        signForm( Form& form );

    void        executeForm( const Form& form ) const;  

    /* ---------------- Exception Classes ---------------- */
    class GradeTooHighException : public std::exception {
        public:
            virtual const char* what() const throw() { return "Grade too high"; }
    };
    class GradeTooLowException : public std::exception {
        public:
            virtual const char* what() const throw() { return "Grade too low"; }
    };

};

std::ostream&   operator<<( std::ostream& o, const Bureaucrat& rhs );

#endif // BUREAUCRAT_HPP