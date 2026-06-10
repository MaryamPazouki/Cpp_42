/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpazouki <mpazouki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 11:15:24 by mpazouki          #+#    #+#             */
/*   Updated: 2026/06/09 08:52:26 by mpazouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define  EASYFIND_HPP

#include <algorithm>
#include <exception>

#include<iostream>

template <typename T>
typename T::iterator easyfind(T &container, int value)
{
    //We use the std::find algorithm to search for the specified value within the container.
    // returning an iterator to the first element == value, or container.end() if none match.
    //If the value is not found, std::find returns an iterator to the end of the container,
    typename T::iterator it = std::find(container.begin(), container.end(), value);
    if (it == container.end())
        throw std::exception();
    return it;
}

/*
// when you hva ediffernet types of container you can use template specialization to provide specific implementations for certain types.

 template <typename T, typename U>
typename T::iterator easyfind(T &container, const U &value)
{
    // Use std::find to search the range [begin, end) for `value`.
    // Returns iterator to first matching element or container.end() if not found.
    typename T::iterator it = std::find(container.begin(), container.end(), value);
    if (it == container.end())
        throw std::exception();
    return it;
} */


#endif

/* an STL container is a template type from the C++ Standard Library that stores and manages collections of objects 
and provides iterator-based access and operations (insert, erase, traversal, etc.). 

- Purpose: hold groups of values with well-defined behavior and complexity guarantees.
- Main categories: Sequence (std::vector, std::deque, std::list, std::array, std::forward_list); 
                   Associative (std::set, std::map, std::multiset, std::multimap); 
                   Unordered associative (std::unordered_set, std::unordered_map); Adaptors (std::stack, std::queue, std::priority_queue).
- Key features:  templates (type-generic), iterators for algorithms, value semantics, optional custom allocators, documented complexity for operations.
- Example usages: std::vector<int> v; v.push_back(10); and std::map<std::string,int> m; m["key"]=1;

- Pick a container by required operations: 
    random access (vector/array), 
    frequent middle insertions (list), 
    ordered lookup (map/set), 
    hashed lookup (unordered_map).



*/