/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpazouki <mpazouki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 14:09:30 by mpazouki          #+#    #+#             */
/*   Updated: 2026/06/09 08:50:34 by mpazouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "easyfind.hpp"
#include <vector>
#include <list>

int main(){
    
    //--------------------------Testing with vector----------------------------------------------
    //we define a vector of integers and populate it with some values. 
    //We then use the easyfind function to search for specific values, 
    //demonstrating both successful and unsuccessful searches. 
    
    
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

    //-----------------------------Testing with list-------------------------------
    //We also test the function with a list to show its versatility with different STL containers.
    
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

    //-----------------------Testing duplicate values (first occurrence)----------------
    std::vector<int> v2;
    v2.push_back(5);
    v2.push_back(10);
    v2.push_back(10);
    v2.push_back(15);

    try
    {
        std::vector<int>::iterator it2 = easyfind(v2, 10);
        std::cout << "Found first occurrence in v2: " << *it2 << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << "10 not found in v2" << std::endl;
    }
    
   /*  //-----------------------Testing with char container----------------
    std::vector<char> vc;
    vc.push_back('x');
    vc.push_back('y');
    vc.push_back('z');

    try
    {
        std::vector<char>::iterator itc = easyfind(vc, 'y');
        std::cout << "Found char in vc: " << *itc << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << "char not found in vc" << std::endl;
    }
    return 0; */
    
}

 //c++ -Wall -Wextra -Werror -std=c++98 main.cpp
