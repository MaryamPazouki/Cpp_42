/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpazouki <mpazouki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 08:44:40 by mpazouki          #+#    #+#             */
/*   Updated: 2026/06/09 10:14:50 by mpazouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Span.hpp"

#include <ctime>
#include <cstdlib>
#include <vector>
#include <limits>

int main()
{
    
    // === Basic example ===
    // Create a Span with capacity 10 and add several numbers.
    std::cout << "-- Basic Span test --" << std::endl;
    Span sp = Span(10);
    std::cout << "Span capacity: 10" << std::endl;
    std::cout << "int min: " << std::numeric_limits<int>::min() << std::endl;
    std::cout << "int max: " << std::numeric_limits<int>::max() << std::endl;

    std::cout << "Adding numbers: 6 3 17 9 11" << std::endl;
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    

    std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
    std::cout << "Longest span:  " << sp.longestSpan() << std::endl << std::endl;

    //----------------------------------------------
    // === Add a vector of random numbers ===
    std::cout << "-- Vector -> Span test --" << std::endl;
    std::cout << "Generating 10 random numbers (0-99)" << std::endl;
    std ::srand(std ::time(NULL));

    std::vector<int> v;

    for (size_t i = 0; i < 10; i++)
        v.push_back(std::rand() % 100); // numbers 0-99

    std::cout << "Random values: ";
    for (size_t i = 0; i < v.size(); i++)
        std::cout << v[i] << " ";
    std::cout << std::endl;

    // Add the generated values to a Span and report results.
    Span bigSp(50);
    try
    {
        bigSp.addNumbers(v.begin(), v.end());
        std::cout << "Added " << v.size() << " numbers to bigSp." << std::endl;
        std::cout << "bigSp shortest span: " << bigSp.shortestSpan() << std::endl;
        std::cout << "bigSp longest span:  " << bigSp.longestSpan() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Error: Span capacity exceeded when adding vector" << std::endl;
    }
    
    //------------------------------------------------
    // add huge numbers
    // === Large test (stress) ===
    std::cout << std::endl << "-- Large Span test --" << std::endl;
    std::cout << "Filling a large Span with 1,000,000 random numbers (may take a moment)" << std::endl;
    Span huge(10000000);
    for (int i = 0; i < 1000000; i++)
        huge.addNumber(std::rand());

    std::cout << "Example safe bounds for int tests: " << std::numeric_limits<int>::min()
              << " to " << std::numeric_limits<int>::max() << std::endl;

    std::cout << "huge shortest span: " << huge.shortestSpan() << std::endl;
    std::cout << "huge longest span:  " << huge.longestSpan() << std::endl;
    return 0;
}