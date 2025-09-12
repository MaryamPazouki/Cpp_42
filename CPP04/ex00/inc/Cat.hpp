/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpazouki <mpazouki@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-09-12 08:43:40 by mpazouki          #+#    #+#             */
/*   Updated: 2025-09-12 08:43:40 by mpazouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP
#include "Animal.hpp"


class Cat : public Animal{
    
    public:
        Cat();
        Cat(const Cat &other);
        Cat& operator = (const Cat& other);
        ~Cat();

        void makeSound()const; //override
};

#endif
