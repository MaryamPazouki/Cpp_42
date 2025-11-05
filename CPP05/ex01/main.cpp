/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpazouki <mpazouki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 12:01:19 by mpazouki          #+#    #+#             */
/*   Updated: 2025/11/05 12:01:20 by mpazouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(){
    try{
        Bureaucrat john("John", 46);
        Form contract("Work contract", 45, 20);

        
        john.signForm(contract);// too low

        john.incrementGrade();
        john.incrementGrade();
        john.signForm(contract);// too low
        john.decrementGrade(); // throws exception
    }
    catch (std::exception & e){
        std::cerr << e.what() << std::endl;
    }
}