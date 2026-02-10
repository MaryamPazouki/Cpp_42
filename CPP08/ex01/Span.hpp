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