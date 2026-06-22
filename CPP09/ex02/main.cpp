/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpazouki <mpazouki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 09:52:08 by mpazouki          #+#    #+#             */
/*   Updated: 2026/06/22 09:55:27 by mpazouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char** argv) {
    if (argc < 2) {
        std::cerr << "Error" << std::endl;
        return 1;
    }

    PmergeMe pm;

    if (!pm.parseInput(argc, argv)) {
        std::cerr << "Error" << std::endl;
        return 1;
    }

    pm.printBefore();

    pm.sortVector();
    pm.sortDeque();

    pm.printAfter();
    pm.printTimes();

    return 0;
}



/* deque’s advantage is flexibility at both ends, 
but in this exercise vector is usually the more 
efficient choice in practice. */


