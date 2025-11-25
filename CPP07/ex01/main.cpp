/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpazouki <mpazouki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 14:00:07 by mpazouki          #+#    #+#             */
/*   Updated: 2025/11/19 14:19:52 by mpazouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "iter.hpp"

// as Example : two simple function

template <typename T>
void printValue(const T &value)
{
    std::cout << value << " ";
}

//Fucntion that modifies values
template <typename T>
void increment (T &value){
    value ++;
}

int main(){
    
    std::cout<<  "--- INT ARRAY ---\n";
    int arr[] = {1,2,3,4,5};
    iter(arr, 5, printValue<int>);
    std::cout << "\n";

    iter(arr, 5, increment<int>);
    iter(arr, 5, printValue<int>);
     std::cout << "\n\n";
    
    std::cout << "--- STRING ARRAY ---\n";
    std::string strs[] = {"hello", "world", "cpp"};
    iter(strs, 3, printValue<std::string>);
    std::cout << "\n\n";

    std::cout << "--- CONST ARRAY ---\n";
    const int constArr[] = {10, 20, 30};
    iter(constArr, 3, printValue<int>);
    //iter(constArr, 3, increment<int>);
    std::cout << "\n";
    
    return 0;
}