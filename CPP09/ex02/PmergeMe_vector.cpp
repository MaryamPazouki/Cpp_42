/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe_vector.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpazouki <mpazouki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 09:51:37 by mpazouki          #+#    #+#             */
/*   Updated: 2026/06/17 09:37:31 by mpazouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

/* ================================================================================
 * FORD-JOHNSON MERGE INSERTION SORT - VECTOR IMPLEMENTATION
 * 
 * Algorithm: Ford-Johnson (also known as Merge Insertion Sort) is one of the most
 * efficient comparison-based sorting algorithms, using very few comparisons by
 * comparing pairs first, then intelligently inserting remaining elements using
 * a mathematically optimal insertion order (Jacobsthal sequence).
 * ================================================================================ */

/* -------------------- VECTOR BINARY INSERT -------------------- */

/**
 * @brief Performs a binary search to find the correct position and inserts a value
 *        into the sorted mainChain vector.
 * 
 * @param mainChain  Reference to the sorted vector where the value will be inserted
 * @param value      The value to insert
 * @param endPos     The upper bound position to search up to (exclusive)
 * 
 * @detail Uses binary search to locate the insertion point, then inserts the value.
 *         This maintains O(log n) search time, though insertion is O(n).
 */
void PmergeMe::binaryInsertVector(std::vector<int>& mainChain,
                                  int value,
                                  size_t endPos) const
{
    // Clamp endPos to valid range
    if (endPos > mainChain.size())
        endPos = mainChain.size();

    size_t left = 0;
    size_t right = endPos;

    // Binary search in the restricted range [0, endPos)
    while (left < right) {
        size_t mid = left + (right - left) / 2;

        if (mainChain[mid] < value)
            left = mid + 1;
        else
            right = mid;
    }

    // Insert at the correct position
    mainChain.insert(mainChain.begin() + left, value);
}


/* -------------------- VECTOR FORD–JOHNSON -------------------- */

/**
 * @brief Sorts a vector of integers using the Ford-Johnson algorithm.
 *        This algorithm minimizes the number of comparisons needed by:
 *        1. Pairing elements and comparing pairs
 *        2. Recursively sorting the "big" elements
 *        3. Binary inserting "small" elements using an optimal Jacobsthal order
 * 
 * @param arr Reference to the vector to be sorted (sorted in-place)
 * 
 * @detail Time Complexity: O(n log^2 n) in average/worst case
 *         Space Complexity: O(n) for auxiliary vectors
 *         This algorithm is notable for using near-optimal number of comparisons.
 */
void PmergeMe::fordJohnsonVector(std::vector<int>& arr) const {
    if (arr.size() <= 1)
        return;

    size_t n = arr.size();
    std::vector<int> bigs;
    std::vector<int> smalls;

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
    fordJohnsonVector(bigs);

    /* -------- STEP 4: Build main chain -------- */
    std::vector<int> mainChain = bigs;

    /* -------- STEP 5: Insert smalls in Jacobsthal order -------- */
    if (!smalls.empty()) {

        // Build Jacobsthal insertion order for indices 1..m-1
        std::vector<size_t> order = buildJacobOrder(smalls.size());

        // Insert all smalls EXCEPT index 0
        for (size_t idx = 0; idx < order.size(); ++idx) {
            size_t i = order[idx];

            int s = smalls[i];
            int b = bigs[i]; // same index in bigs corresponds to the paired small

            // Find upper bound for binary search
            size_t posB = std::lower_bound(mainChain.begin(), mainChain.end(), b)
                          - mainChain.begin(); //  posB is the search limit

            // Insert s into [0, posB]
            binaryInsertVector(mainChain, s, posB);
        }

        /* -------- Insert small[0] LAST (required by Ford–Johnson) -------- */
        int s0 = smalls[0];
        int b0 = bigs[0];

        size_t posB0 = std::lower_bound(mainChain.begin(), mainChain.end(), b0)
                       - mainChain.begin();

        binaryInsertVector(mainChain, s0, posB0);
    }

    /* -------- STEP 6: Insert odd leftover element -------- */
    if (hasOdd) {
        binaryInsertVector(mainChain, oddVal, mainChain.size());
    }

    arr = mainChain;
}
