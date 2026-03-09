#include "RPN.hpp"

#include<sstream>
#include<cctype>

RPN :: RPN(){};
RPN :: RPN(const RPN &other){(void ) other;}
RPN &RPN :: operator =( const RPN &other ){ (void)other; return *this;}
RPN :: ~RPN(){}

int RPN :: evaluate(const std::string &expr){
    std::stack<int> st; // STL container adaptor
    std::istringstream iss(expr);
    std::string token;

    while(iss >> token)
    {
        if (token.size() == 1 && std::isdigit(token[0])){
            st.push(token[0] - '0'); // invert charactuire into integer
        }
        else if (token == "+" || token == "-" || token == "*" || token == "/") {
            if (st.size()<2)
                throw std::runtime_error("not enough operands!" );
            
            int b = st.top(); // gives you the value
            st.pop(); //removes it.
            int a = st.top();
            st.pop();
            int r;

            if (token == "+") r = a +b;
            else if (token == "-") r = a - b;
            else if (token == "*") r = a * b;
            else{
                if (b == 0)
                    throw std::runtime_error("division by zero");
                r = a /b;    
            }
            st.push(r);
        }
        else 
            throw std:: runtime_error("invalid operator");

    }
    if (st.size() != 1)
        throw std::runtime_error("invalid expression");
    return st.top();
}


/* Your input contains:

parentheses → not allowed

infix notation → not allowed

no spaces between tokens → not allowed

operator in the middle → not RPN */