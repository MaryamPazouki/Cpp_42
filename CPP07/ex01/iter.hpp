/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpazouki <mpazouki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 14:00:15 by mpazouki          #+#    #+#             */
/*   Updated: 2026/06/01 10:47:40 by mpazouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef ITER_HPP
#define ITER_HPP

#include <cstddef> // for size_t

/* Implement a generic iter function template to apply a function to each element of an array 
(shows function-template callbacks and const/ non-const overloads). */



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
void iter(const T *array, const size_t length, F func){
    for (size_t i = 0; i < length; i++)
        func(array[i]);
}


#endif


/* So the two overloads split the use cases:

iter(T *array, ...) for callbacks that modify elements, like increment(T &)
iter(const T *array, ...) for callbacks that only read elements, like printValue(const T &)
This design allows the iter function to be flexible and work with both modifying and non-modifying callbacks, while ensuring const-correctness when needed. */