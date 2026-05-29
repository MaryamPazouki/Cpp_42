/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpazouki <mpazouki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 14:24:27 by mpazouki          #+#    #+#             */
/*   Updated: 2026/05/27 08:59:49 by mpazouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <limits>
#include <cmath>
#include <cstdlib>

class ScalarConverter {
private:
    // Constructors are private → no instantiation allowed
    ScalarConverter();
    ~ScalarConverter();
    ScalarConverter(const ScalarConverter &);
    ScalarConverter &operator=(const ScalarConverter &);

    // Type detection helpers
    static bool isChar(const std::string &s);
    static bool isInt(const std::string &s);
    static bool isFloat(const std::string &s);
    static bool isDouble(const std::string &s);
    static bool isPseudoLiteral(const std::string &s);

    // Conversion handlers
    static void convertFromChar(const std::string &s);
    static void convertFromInt(const std::string &s);
    static void convertFromFloat(const std::string &s);
    static void convertFromDouble(const std::string &s);
    static void handlePseudoLiteral(const std::string &s);

    // Utility printing functions
    static void printChar(double value);
    static void printInt(double value);
    static void printFloat(double value);
    static void printDouble(double value);

public:
    // The only public method
    static void convert(const std::string &literal);
};

#endif


/* 
-static because no object state is needed
-private because they are internal helpers
-public convert is the only function meant to be called from outside */