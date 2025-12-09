/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpazouki <mpazouki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 15:04:36 by mpazouki          #+#    #+#             */
/*   Updated: 2025/11/27 16:06:42 by mpazouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

// DEFAULT CONSTRUCTOR
template<typename T>
Array<T>::Array() : _data(NULL), _size(0) {}


// CONSTRUCTOR WITH SIZE
template<typename T>
Array<T>::Array(unsigned int n) : _data(new T[n]()),_size(n){}

//copy constructor
template <typename T>
Array<T>::Array(const Array<T> &other) : _data(NULL), _size(0)
{
    *this = other;
}
// Assignment operator
template<typename T>
Array<T>& Array<T>::operator = (const Array<T> &other)
{
    if (this != &other)
    {
        delete [] _data;
        _size = other._size;
        _data = new T[_size];

        for (unsigned int i = 0; i< _size ; i++)
            _data[i] = other._data[i];
    }
    return *this;
}

//Destructor 
template <typename T>
Array <T> :: ~Array()
{
    delete[]_data;
}

// Subscript operator (non-const)
template <typename T>
T& Array<T>::operator[](unsigned int i)
{
    if (i >= _size)
        throw std :: out_of_range("Index out of bound");
    return _data[i];
}

// Subscript operator (const)
template <typename T>
const T& Array<T>::operator[](unsigned int i) const
{
    if (i >= _size)
        throw std::out_of_range("Index out of bounds");
    return _data[i];
}

// Size getter
template <typename T>
unsigned int Array<T>::size() const
{
    return _size;
}
