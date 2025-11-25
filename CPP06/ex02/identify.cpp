/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   identify.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpazouki <mpazouki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 11:42:54 by mpazouki          #+#    #+#             */
/*   Updated: 2025/11/18 12:44:52 by mpazouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "identify.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

void identify(Base* p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "A*" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "B*" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "C*" << std::endl;
    else
        std::cout << "Unknown" << std::endl;
}

void identify(Base& p)
{
    try {
        (void)dynamic_cast<A&>(p);
        std::cout << "A&" << std::endl;
        return;
    } catch(...) {}

    try {
        (void)dynamic_cast<B&>(p);
        std::cout << "B&" << std::endl;
        return;
    } catch(...) {}

    try {
        (void)dynamic_cast<C&>(p);
        std::cout << "C&" << std::endl;
        return;
    } catch(...) {}

    std::cout << "Unknown" << std::endl;
}

