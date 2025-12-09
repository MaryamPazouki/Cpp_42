/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpazouki <mpazouki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 14:25:47 by mpazouki          #+#    #+#             */
/*   Updated: 2025/11/27 16:20:37 by mpazouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <iostream>

int main(){
     try
     {
        std::cout << "--- Empty Array ---\n";
        Array<int> a;
        std::cout << "Size: " << a.size() << "\n\n";

        std::cout << "--- Array of 5 ints ---\n";
        Array<int> b(5);
        for (unsigned int i = 0;i < b.size(); i++)
            b[i] = 10 * i;
        for (unsigned i = 0; i < b.size(); i++)
            std::cout << b[i] << " ";
        std::cout << "\n\n";
        
        std::cout << "--- Copy Constructor ---\n";
        Array<int> c = b;
        c[0] = 999;
        std::cout << "Original b[0] = " << b[0] << "\n"; // should remain unchanged
        std::cout << "Copy c[0]     = " << c[0] << "\n\n";
        
       /*  std::cout << "--- Out of Bounds ---\n";
        std::cout << b[10] << "\n"; // should throw */
        
        //---------------- string type---------------
        std::cout << "--- Empty Array ---\n";
        Array<std::string> s;
        std::cout << "Size: " << s.size() << "\n\n";
        
        std::cout << "--- Array of 2 string ---\n";
        Array<int> s2(2);
        s2[0] = '1';
        s2[1] = '2';
        for (unsigned i = 0; i < s2.size(); i++)
            std::cout << s2[i] << " ";
        std::cout << "\n\n";
     }
     catch(const std::exception& e)
     {
        std::cerr << "Exception:" << e.what() << '\n';
     }
     
}