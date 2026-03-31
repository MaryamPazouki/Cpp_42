/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpazouki <mpazouki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 09:51:50 by mpazouki          #+#    #+#             */
/*   Updated: 2026/03/13 09:51:51 by mpazouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "PmergeMe.hpp"

PmergeMe::PmergeMe() : _timeVec(0.0), _timeDeq(0.0) {}

PmergeMe::PmergeMe(const PmergeMe& other)
    : _vec(other._vec),
      _deq(other._deq),
      _timeVec(other._timeVec),
      _timeDeq(other._timeDeq) {}

PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
    if (this != &other) {
        _vec = other._vec;
        _deq = other._deq;
        _timeVec = other._timeVec;
        _timeDeq = other._timeDeq;
    }
    return *this;
}

PmergeMe::~PmergeMe() {}
