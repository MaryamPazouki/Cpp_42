/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpazouki <mpazouki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 14:26:04 by mpazouki          #+#    #+#             */
/*   Updated: 2025/11/27 16:05:01 by mpazouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <stdexcept>
#include <iostream>

template <typename T>
class Array{
    private:
        T* _data;
        unsigned int _size;
    public:
        Array();
        Array(unsigned int n); 
        Array(const Array & other);
        Array & operator= (const Array& other);
        ~Array();
        
        // Subscript operator
        T& operator[](unsigned int i);
        const T& operator[](unsigned int i) const;
        
        // Size getter
        unsigned int size() const;
        

};

#include "Array.tpp" // Template implementarion



#endif

