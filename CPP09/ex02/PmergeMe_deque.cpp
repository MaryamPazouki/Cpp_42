/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe_deque.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpazouki <mpazouki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 09:51:59 by mpazouki          #+#    #+#             */
/*   Updated: 2026/06/22 09:38:00 by mpazouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

/* ================================================================================
 * FORD-JOHNSON MERGE INSERTION SORT - DEQUE IMPLEMENTATION
 *
 * Same algorithm as the vector version, but using std::deque as the target
 * container so the differences stay limited to container-specific operations.
 * ================================================================================ */

/* -------------------- DEQUE BINARY INSERT -------------------- */

/**
 * @brief Performs a binary search to find the correct position and inserts a value
 *        into the sorted mainChain deque.
 *
 * @param mainChain  Reference to the sorted deque where the value will be inserted
 * @param value      The value to insert
 * @param endPos     The upper bound position to search up to (exclusive)
 */
void PmergeMe::binaryInsertDeque(std::deque<int>& mainChain,
                                 int value,
                                 size_t endPos) const
{
    if (endPos > mainChain.size())
        endPos = mainChain.size();

    size_t left = 0;
    size_t right = endPos;

    while (left < right) {
        size_t mid = left + (right - left) / 2;

        if (mainChain[mid] < value)
            left = mid + 1;
        else
            right = mid;
    }

    mainChain.insert(mainChain.begin() + left, value);
}

/* -------------------- DEQUE FORD–JOHNSON -------------------- */

/**
 * @brief Sorts a deque of integers using the Ford-Johnson algorithm.
 *        This mirrors the vector version so the only real differences are the
 *        container types and deque-specific insert operations.
 */
void PmergeMe::fordJohnsonDeque(std::deque<int>& arr) const
{
    if (arr.size() <= 1)
        return;

    size_t n = arr.size();
    std::deque<int> bigs;
    std::deque<int> smalls;

    /* -------- STEP 1: Handle odd-sized arrays -------- */
    bool hasOdd = (n % 2 != 0);
    int oddVal = 0;
    if (hasOdd)
        oddVal = arr[n - 1];

    /* -------- STEP 2: Pair comparison phase -------- */
    for (size_t i = 0; i + 1 < n; i += 2) {
        int a = arr[i];
        int b = arr[i + 1];

        if (a < b) {
            smalls.push_back(a);
            bigs.push_back(b);
        } else {
            smalls.push_back(b);
            bigs.push_back(a);
        }
    }

    /* -------- STEP 3: Recursively sort the bigs -------- */
    fordJohnsonDeque(bigs);

    /* -------- STEP 4: Build main chain -------- */
    std::deque<int> mainChain = bigs;

    /* -------- STEP 5: Insert smalls in Jacobsthal order -------- */
    if (!smalls.empty()) {
        // Build Jacobsthal insertion order for indices 1..m-1
        std::vector<size_t> order = buildJacobOrder(smalls.size());

        // Insert all smalls EXCEPT index 0
        for (size_t idx = 0; idx < order.size(); ++idx) {
            size_t i = order[idx];

            int s = smalls[i];
            int b = bigs[i];

            // Find upper bound for binary search
            size_t posB = std::lower_bound(mainChain.begin(), mainChain.end(), b)
                          - mainChain.begin();

            // Insert s into [0, posB]
            binaryInsertDeque(mainChain, s, posB);
        }

        /* -------- Insert small[0] LAST (required by Ford–Johnson) -------- */
        int s0 = smalls[0];
        int b0 = bigs[0];

        size_t posB0 = std::lower_bound(mainChain.begin(), mainChain.end(), b0)
                       - mainChain.begin();

        binaryInsertDeque(mainChain, s0, posB0);
    }

    /* -------- STEP 6: Insert odd leftover element -------- */
    if (hasOdd) {
        binaryInsertDeque(mainChain, oddVal, mainChain.size());
    }

    arr = mainChain;
}
