/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe_utils.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpazouki <mpazouki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 09:52:31 by mpazouki          #+#    #+#             */
/*   Updated: 2026/06/30 06:21:32 by mpazouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

/* -------------------- INPUT VALIDATION -------------------- */

bool PmergeMe::isValidNumber(const std::string &s, int &out) const
{
    if (s.empty())
        return false;

    for (size_t i = 0; i < s.size(); ++i)
        if (!std::isdigit(static_cast<unsigned char>(s[i])))
            return false;

    long val = std::strtol(s.c_str(), NULL, 10);
    if (val <= 0 || val > INT_MAX)
        return false;

    out = static_cast<int>(val);
    return true;
}

/* -------------------- PARSE INPUT -------------------- */

bool PmergeMe::parseInput(int argc, char **argv)
{
    for (int i = 1; i < argc; ++i)
    {
        int value;
        if (!isValidNumber(argv[i], value))
            return false;

        _vec.push_back(value);
        _deq.push_back(value);
    }
    return true;
}

/* -------------------- PRINTING -------------------- */

void PmergeMe::printBefore() const
{
    std::cout << "Before:";
    for (size_t i = 0; i < _vec.size(); ++i)
        std::cout << " " << _vec[i];
    std::cout << std::endl;
}

void PmergeMe::printAftervec() const
{
    std::cout << "After Vector:";
    for (size_t i = 0; i < _vec.size(); ++i)
        std::cout << " " << _vec[i];
    std::cout << std::endl;
}

void PmergeMe::printAfterdeq() const
{
    std::cout << "After Deque:";
    for (size_t i = 0; i < _deq.size(); ++i)
        std::cout << " " << _deq[i];
    std::cout << std::endl;
}

/* -------------------- TIMING -------------------- */

void PmergeMe::sortVector()
{
    clock_t start = clock();
    fordJohnsonVector(_vec);
    clock_t end = clock();
    _timeVec = (double)(end - start) / CLOCKS_PER_SEC * 1e6; // microseconds
}

void PmergeMe::sortDeque()
{
    clock_t start = clock();
    fordJohnsonDeque(_deq);
    clock_t end = clock();
    _timeDeq = (double)(end - start) / CLOCKS_PER_SEC * 1e6;
}

void PmergeMe::printTimes() const
{
    std::cout << "Time to process a range of " << _vec.size()
              << " elements with std::vector : " << _timeVec << " us" << std::endl;

    std::cout << "Time to process a range of " << _deq.size()
              << " elements with std::deque  : " << _timeDeq << " us" << std::endl;
}

/* -------------------- JACOBSTHAL ORDER -------------------- */

std::vector<size_t> PmergeMe::buildJacobOrder(size_t m) const
{
    std::vector<size_t> order;
    if (m == 0)
        return order;

    // Jacobsthal numbers: 0, 1, 1, 3, 5, 11, 21, ...
    std::vector<size_t> J;
    J.push_back(0);
    J.push_back(1);

    // Generate Jacobsthal numbers until >= m
    while (J.back() < m) {
        size_t next = J[J.size() - 1] + 2 * J[J.size() - 2];
        J.push_back(next);
    }

    // Insert blocks in descending order:
    // Block k = (J[k] - 1) down to (J[k-1])
    // But we skip index 0 because smalls[0] is inserted separately.
    for (size_t k = 2; k < J.size(); ++k) {
        size_t start = (J[k] < m ? J[k] : m);
        size_t end   = J[k - 1];

        for (size_t i = start; i > end; --i) {
            if (i - 1 < m && i - 1 != 0)
                order.push_back(i - 1);
        }
    }

    return order;
}

/* The effect of Jacobthals order is that:
Each insertion searches a smaller interval than the previous one

No insertion ever re-searches a large interval

The algorithm stays O(n log n) with the lowest known constant factor

This is why Ford–Johnson is the optimal comparison sort for small n. */