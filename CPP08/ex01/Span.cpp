/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpazouki <mpazouki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 08:44:45 by mpazouki          #+#    #+#             */
/*   Updated: 2026/02/10 10:18:17 by mpazouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"


Span :: Span(): _maxSize(0){} //Default Constructor

Span::Span(unsigned int num) : _maxSize(num){}; // Parameter Constructor

Span :: Span(const Span& other){   
    *this = other;
}

Span& Span::operator = (const Span& other){
    if (this != &other)
    {
        _maxSize = other._maxSize;
        _data = other._data;
        
    }
    return *this;   
}

Span::~Span(){};


void Span::addNumber( int n){
    if (_data.size() >= _maxSize)
        throw std::exception();
    _data.push_back(n);
}



int Span::longestSpan() const {
    if (_maxSize < 2)
        throw std::exception();
    //std::vector<int>::iterator it = std::min_element(_data.begin(), _data.end());
    // int min_value = *it
    int min_value = *std::min_element(_data.begin(), _data.end());
    int max_value = *std::max_element(_data.begin(), _data.end());

    return ( max_value - min_value );
    
}

int Span::shortestSpan() const{
    if (_data.size() < 2)
        throw std::exception();
    
    std::vector<int> tmp = _data;
    std::sort(tmp.begin(), tmp.end());
    
    int shortest = std::numeric_limits<int>::max();
    // 
    std::vector<int> :: iterator it = tmp.begin() +1;
    while (it != tmp.end() )
    {
        int diff  = *it - *(it -1);
        if (diff < shortest)
            shortest = diff;
        it++; 
    }
    return shortest;    
}