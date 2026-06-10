/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpazouki <mpazouki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 10:31:43 by mpazouki          #+#    #+#             */
/*   Updated: 2026/06/10 09:15:52 by mpazouki         ###   ########.fr       */
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

/* 
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
 */


// Improved demo showing two cases:
// 1) the original 'list' example (to show iteration behaviour)
// 2) the `MutantStack` example (stack operations + iterators)

int main()
{
    // -----------------------------
    // Case A: std::list demo
    // -----------------------------
    std::cout << "=== std::list demo ===" << std::endl;

    // Use list to mimic the behaviour shown in the subject's example
    std::list<int> l;
    l.push_back(5);   // push 5
    l.push_back(17);  // push 17

    // show the last element (like stack::top)
    std::cout << "back(): " << l.back() << std::endl;

    // remove the last element
    l.pop_back();

    // show current size
    std::cout << "size(): " << l.size() << std::endl;

    // push more elements
    l.push_back(3);
    l.push_back(5);
    l.push_back(737);
    l.push_back(0);

    // iterate from begin() to end() — demonstrates standard iterator usage
    std::cout << "elements:" << std::endl;
    for (std::list<int>::iterator it = l.begin(); it != l.end(); ++it)
        std::cout << "  " << *it << std::endl;

    std::cout << std::endl;

    // -----------------------------
    // Case B: MutantStack demo
    // -----------------------------
    std::cout << "=== MutantStack demo ===" << std::endl;

    // MutantStack behaves like std::stack (LIFO) but exposes iterators.
    MutantStack<int> mstack;
    mstack.push(5);    // push 5
    mstack.push(17);   // push 17

    // top() accesses the most recently pushed element
    std::cout << "top(): " << mstack.top() << std::endl;

    // pop the top element
    mstack.pop();

    // size() returns number of elements
    std::cout << "size(): " << mstack.size() << std::endl;

    // push more elements
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);

    // MutantStack supports normal iterator traversal
    std::cout << "elements (from bottom to top):" << std::endl;
    for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it)
        std::cout << "  " << *it << std::endl;

    // You can also use reverse iterators to traverse from top to bottom
    std::cout << "elements (from top to bottom):" << std::endl;
    for (MutantStack<int>::reverse_iterator rit = mstack.rbegin(); rit != mstack.rend(); ++rit)
        std::cout << "  " << *rit << std::endl;

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
