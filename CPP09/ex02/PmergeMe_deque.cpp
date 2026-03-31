/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe_deque.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpazouki <mpazouki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 09:51:59 by mpazouki          #+#    #+#             */
/*   Updated: 2026/03/13 09:52:01 by mpazouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

/* -------------------- DEQUE BINARY INSERT -------------------- */

void PmergeMe::binaryInsertDeque(std::deque<int>& mainChain, int value, size_t endPos) const {
    size_t left = 0;
    size_t right = endPos;

    while (left < right) {
        size_t mid = (left + right) / 2;
        if (mainChain[mid] < value)
            left = mid + 1;
        else
            right = mid;
    }
    mainChain.insert(mainChain.begin() + left, value);
}

/* -------------------- DEQUE FORD–JOHNSON -------------------- */

void PmergeMe::fordJohnsonDeque(std::deque<int>& arr) const {
    if (arr.size() <= 1)
        return;

    size_t n = arr.size();
    std::deque<int> bigs;
    std::deque<int> smalls;

    bool hasOdd = (n % 2 != 0);
    int oddVal = 0;
    if (hasOdd)
        oddVal = arr[n - 1];

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

    std::vector<int> bigsVec(bigs.begin(), bigs.end());
    fordJohnsonVector(bigsVec);
    bigs.assign(bigsVec.begin(), bigsVec.end());

    std::deque<int> mainChain = bigs;

    if (!smalls.empty()) {
        int firstSmall = smalls[0];
        int firstBig   = bigs[0];

        size_t posBig = std::lower_bound(mainChain.begin(), mainChain.end(), firstBig)
                        - mainChain.begin();

        binaryInsertDeque(mainChain, firstSmall, posBig);

        std::vector<size_t> order = buildJacobOrder(smalls.size());

        for (size_t idx = 0; idx < order.size(); ++idx) {
            size_t i = order[idx];
            if (i == 0 || i >= smalls.size())
                continue;

            int s = smalls[i];
            int b = bigs[i];

            size_t posB = std::lower_bound(mainChain.begin(), mainChain.end(), b)
                          - mainChain.begin();

            binaryInsertDeque(mainChain, s, posB);
        }
    }

    if (hasOdd) {
        size_t endPos = mainChain.size();
        binaryInsertDeque(mainChain, oddVal, endPos);
    }

    arr = mainChain;
}
