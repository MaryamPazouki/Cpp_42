/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpazouki <mpazouki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 09:52:25 by mpazouki          #+#    #+#             */
/*   Updated: 2026/03/13 09:52:26 by mpazouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <string>
#include <iostream>
#include <algorithm>
#include <climits>
#include <cstdlib>
#include <cctype>
#include <ctime>

class PmergeMe {
public:
    PmergeMe();                          
    PmergeMe(const PmergeMe& other);
    PmergeMe& operator=(const PmergeMe& other);
    ~PmergeMe();

    bool parseInput(int argc, char** argv);

    void printBefore() const;
    void printAfter() const;

    void sortVector();
    void sortDeque();

    void printTimes() const;

private:
    std::vector<int> _vec;
    std::deque<int>  _deq;

    double _timeVec;
    double _timeDeq;

    bool isValidNumber(const std::string& s, int& out) const;

    /* Vector implementation */
    void fordJohnsonVector(std::vector<int>& arr) const;
    void binaryInsertVector(std::vector<int>& mainChain, int value, size_t endPos) const;

    /* Deque implementation */
    void fordJohnsonDeque(std::deque<int>& arr) const;
    void binaryInsertDeque(std::deque<int>& mainChain, int value, size_t endPos) const;

    /* Shared helper */
    std::vector<size_t> buildJacobOrder(size_t m) const;
};

#endif
