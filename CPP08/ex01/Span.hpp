#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <exception>
#include <algorithm>
#include <iostream>
#include <limits>
#include <iterator>

class Span
{
private:
    unsigned int _maxSize;
    std::vector<int> _data;

public:
    Span();
    Span(unsigned int N);
    Span(const Span &other);
    Span &operator=(const Span &other);
    ~Span();

    void addNumber(int value);

    int shortestSpan() const;
    int longestSpan() const;

    // we use iterator instead of row loops, generic programing and container abstarction

    // This method allows us to add a range of numbers to the Span using iterators,
    // which can be from any container that supports iterators (like std::vector, std::list, etc.).
    template <typename it>
    void addNumbers(it begin, it end)
    {
        size_t count = std::distance(begin, end);

        if (_data.size() + count > _maxSize)
            throw std::exception();

        _data.insert(_data.end(), begin, end);
    }
};


#endif

 /* STL containers and iterators (std::vector), algorithms (std::sort, std::min/std::max), 
 complexity reasoning (shortest via sorting O(n log n), longest via min/max O(n)), 
 exception handling, const-correctness, and class design (resource/ownership and copy semantics). */

/*  
 addNumbers is a template. Template functions/classes must be defined where the compiler can see 
 their bodies at the point of instantiation — typically in the header — 
 so the compiler can generate the concrete code for each iterator type you use.

 */
