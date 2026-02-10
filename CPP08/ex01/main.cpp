/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpazouki <mpazouki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 08:44:40 by mpazouki          #+#    #+#             */
/*   Updated: 2026/02/10 10:25:21 by mpazouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Span.hpp"

#include <ctime>
#include <cstdlib>
#include <vector>

int main()
{
    //
    Span sp = Span(10);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;

    // create random vector for tesing huge numbers
    std::cout << "add vector to span" << std::endl;
    std ::srand(std ::time(NULL));

    std::vector<int> v;

    for (size_t i = 0; i < 10; i++)
        v.push_back(std::rand() % 100); // numbers 0-99

    for (size_t i = 0; i < v.size(); i++)
        std::cout << v[i] << " ";
    std::cout << std::endl;
    // Now add vector to Span
    Span bigSp(50);

    try
    {
        bigSp.addNumbers(v.begin(), v.end());
    }
    catch (std::exception &e)
    {
        std::cout << "Error: Span capacity exceeded" << std::endl;
    }

    std::cout << bigSp.shortestSpan() << std::endl;
    std::cout << bigSp.longestSpan() << std::endl;

    // add huge numbers
    std::cout << "add huge vector to span" << std::endl;
    Span huge(10000000);
    for (int i = 0; i < 1000000; i++)
        huge.addNumber(rand());

    std::cout << huge.shortestSpan() << std::endl;
    std::cout << huge.longestSpan() << std::endl;
    return 0;
}