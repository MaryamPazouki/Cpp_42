#ifndef WHATEVER_HPP
#define WHATEVER_HPP

/*Implement function templates swap, min, max to work with any type 
(demonstrates basic function templates and const/ref returns).*/


template <typename T>
/*“The function works for ANY data type, 
as long as the operations inside are supported.”*/

void swap(T &a, T &b){
    T temp = a;
    a = b;
    b = temp;
}

/*We return a reference, not a copy → faster, no temporary object.*/
template <typename T>
const T& min(const T &a, const T &b){
    return(b < a ? b : a);
}

template <typename T>
const T& max(const T &a, const T &b){
    return(b > a ? b :a);
}

#endif