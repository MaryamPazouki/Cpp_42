/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpazouki <mpazouki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 14:54:58 by mpazouki          #+#    #+#             */
/*   Updated: 2025/11/24 13:59:03 by mpazouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_TPP
#define ARRAY_TPP

// DEFAULT CONSTRUCTOR
template<typename T>
Array<T>::Array() : _data(NULL), _size(0) {}


// CONSTRUCTOR WITH SIZE
template<typanem T>
Array<T>::Array(unsigned int n) : _data(new T[n]()),_size(n){}



#endif