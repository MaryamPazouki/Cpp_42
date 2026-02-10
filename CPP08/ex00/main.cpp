/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpazouki <mpazouki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 14:09:30 by mpazouki          #+#    #+#             */
/*   Updated: 2026/02/04 11:15:15 by mpazouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "easyfind.hpp"
#include <vector>
#include <list>

int main(){
    std::vector <int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);

    try
    {
        std::vector<int> :: iterator it = easyfind(v,20);
        std::cout << "Found: " << *it << std::endl;
    }
    catch(const std::exception &e)
    {
        std::cout << "Value not found" << std::endl;
    }
    try 
    {
        easyfind(v, 42);
    }
    catch (const std::exception &e)
    {
        std::cout<< "42 not found" << std::endl;
    }

    std::list<int> l;
    l.push_back(1);
    l.push_back(2);
    l.push_back(3);
    
    try
    {
        std::list <int> ::iterator it = easyfind(l,3);
        std::cout << "Found in list :" << *it << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << "value not found in list" << std::endl;
    }
    return 0;
    
}

 //c++ -Wall -Wextra -Werror -std=c++98 main.cpp
