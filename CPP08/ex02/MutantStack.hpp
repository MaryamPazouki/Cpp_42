/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpazouki <mpazouki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 10:32:24 by mpazouki          #+#    #+#             */
/*   Updated: 2026/02/10 13:15:50 by mpazouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>
#include <deque>
#include <iostream>


// Template class inheriting from std::stack
// Goal: expose iterators of the underlying container

template <typename T>
class MutantStack : public std::stack<T>{ //inherit from std::stack<T>
public: 
    MutantStack(){};
    MutantStack(const MutantStack& other) : std::stack<T>(other){};
    MutantStack& operator=(const MutantStack & other){
        std::stack<T>::operator=(other);
        return *this;
    }
    ~MutantStack(){}
    // expose iterator types from std::stack<T>::container_type
    typedef typename std::stack<T>::container_type::iterator iterator;
    typedef typename std::stack<T>::container_type::const_iterator const_iterator;
    typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
    typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;
    
    // c is a protected member of std::stack,
    // so derived classes (like MutantStack) can access it.
    
    iterator begin(){return this->c.begin();}
    iterator end(){return this->c.end();}
    
    
    const_iterator begin() const { return this->c.begin(); } 
    const_iterator end() const { return this->c.end(); } 
    
    reverse_iterator rbegin() { return this->c.rbegin(); } 
    reverse_iterator rend() { return this->c.rend(); } 
    
    const_reverse_iterator rbegin() const { return this->c.rbegin(); } 
    const_reverse_iterator rend() const { return this->c.rend(); } 
    //You effectively make std::stack iterable without changing how it stores data.

};


#endif

/* 
-std::stack<T> is a container adaptor.

-Internally, it stores another container (by default std::deque<T>).

-The type of that internal container is called container_type.

-So std::stack<T>::container_type is basically “whatever container the stack is using inside”.

-From that internal container, we take its iterator types:

-::iterator — a normal iterator (read/write, non-const).

-::const_iterator — an iterator that cannot modify the elements.

-::reverse_iterator — iterates from the end to the beginning.

-::const_reverse_iterator — reverse iterator that cannot modify elements.
 */





/* 

CPP08 ex02 is not about data structures. It’s about:

understanding STL container adaptors

understanding protected members

exposing iterators through inheritance

using typedefs / using-aliases

writing clean template classes 



=> A container adaptor takes an existing STL container and restricts it so it behaves like a different data structure.

Examples:

std::stack — adapts a container to behave like a LIFO stack

std::queue — adapts a container to behave like a FIFO queue

std::priority_queue — adapts a container to behave like a heap-based priority queue

They don’t store elements directly. They store a container inside them.

=> std::stack — adapts a container to behave like a LIFO stack

The adaptor exposes only the operations that match its behavior.

For std::stack:

push

pop

top

size

empty

Everything else is hidden.

The underlying container is stored in a protected member named c.

A container adaptor is a wrapper that restricts a container to behave 
like a specific data structure, and MutantStack is 
an example of re‑opening that wrapper to expose the underlying iterators.

*/