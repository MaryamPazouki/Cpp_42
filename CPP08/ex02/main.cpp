/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpazouki <mpazouki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 10:31:43 by mpazouki          #+#    #+#             */
/*   Updated: 2026/02/10 13:22:36 by mpazouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

#include <list>

/* 
int main()
{
    MutantStack<int> mstack;
    
    mstack.push(5);
    mstack.push(17);

    std::cout << mstack.top() << std::endl;
    
    mstack.pop();
    
    std::cout << mstack.size() << std::endl;
    
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    //[...]
    mstack.push(0);
    
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    
    ++it;
    --it;

    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    
    std::stack<int> s(mstack);
    
    return 0;
} */


int main()
{
    std::list<int> mstack;
    mstack.push_back(5);
    mstack.push_back(17);

    std::cout << mstack.back() << std::endl;

    mstack.pop_back();

    std::cout << mstack.size() << std::endl;

    mstack.push_back(3);
    mstack.push_back(5);
    mstack.push_back(737);
    mstack.push_back(0);

    std::list<int>::iterator it = mstack.begin();
    std::list<int>::iterator ite = mstack.end();

    ++it;
    --it;

    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }

    return 0;
}




/* The project wants you to understand two STL ideas at the same time:

Container adaptors (like std::stack)

Iterators (begin/end, const iterators, etc.)

std::stack is intentionally not iterable.
You can push, pop, and look at the top — but you cannot loop through it.

MutantStack is a small custom class that behaves like a stack but also exposes iterators, so you can do:

cpp
for (auto it = m.begin(); it != m.end(); ++it)
    std::cout << *it << std::endl;
This is the entire point of the exercise. 

=>  What you gain from MutantStack
You get:

-All stack operations (push, pop, top)

-Ability to iterate through the stack

-Compatibility with STL algorithms (std::find, std::sort if container allows it)

-A deeper understanding of how container adaptors work


*/
