/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpazouki <mpazouki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 14:26:04 by mpazouki          #+#    #+#             */
/*   Updated: 2025/11/19 14:58:20 by mpazouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

template <typename T>
class Array{
    private:
        T* data;
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

