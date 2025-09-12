/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpazouki <mpazouki@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-09-12 08:44:43 by mpazouki          #+#    #+#             */
/*   Updated: 2025-09-12 08:44:43 by mpazouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include<string>
#include<iostream>

class Brain{
    private:
        std::string ideas[100];
    public:
        Brain();
        Brain(Brain &other);
        Brain &operator=(Brain &other);
        ~Brain();

        //getter and setter
        const std::string &getIdea(int index) const;
        void setIdea(int index, const std::string& idea);
};





#endif