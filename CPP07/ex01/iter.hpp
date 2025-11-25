/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpazouki <mpazouki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 14:00:15 by mpazouki          #+#    #+#             */
/*   Updated: 2025/11/19 14:01:11 by mpazouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef ITER_HPP
#define ITER_HPP

#include <cstddef> // for size_t

/* define two overloads:

-One is for modifying elements (func(T&))
-One is for read-only elements (func(const T&))
*/

template < typename T, typename F>
void iter(T *array, const size_t length, F func){
    for (size_t i = 0; i<length ; i++)
        func(array[i]);
}


template< typename T, typename F>
void inter (const T*array, const size_t length, F func){
    for (size_t i = 0 ; length ; i++)
        func(array[i]);
}


#endif