/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpazouki <mpazouki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 09:14:27 by mpazouki          #+#    #+#             */
/*   Updated: 2025/11/17 09:26:10 by mpazouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ScalarConverter.hpp"
#include <cctype>
#include <iomanip>

ScalarConverter::ScalarConverter(){}
ScalarConverter::ScalarConverter(const ScalarConverter &){}
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &)
{
    return *this;
}
ScalarConverter::~ScalarConverter(){}


// ─────────────────────────────────────────────
// Type Detection
// ─────────────────────────────────────────────

bool ScalarConverter::isChar(const std::string &s){
    return s.length() == 1 && std::isprint(s[0]) && !std::isdigit(s[0]);
}

bool ScalarConverter::isInt(const std::string &s){
    size_t i = (s[0] == '+' || s[0] == '-') ? 1 : 0;
    for (; i< s.length();i++)
        if (!std::isdigit(s[i])) return false;
    return true;
}

bool ScalarConverter::isFloat(const std::string &s){
    if (s=="nanf" || s=="+inff" || s=="-inff")
       return true;
    if (s[s.size()-1] != 'f') return false;
    size_t i = (s[0] == '+' || s[0] == '-') ? 1 : 0;
    bool pointSeen = false;
    for (; i < s.length() - 1; i++){
       if (s[i] == '.'){
           if (pointSeen) return false;
           pointSeen = true;
       } else if (!std::isdigit(s[i])) return false;
    }
    return pointSeen;
}

bool ScalarConverter::isDouble(const std::string &s){
    if (s=="nan" || s=="+inf" || s=="-inf")
       return true;
    size_t i = (s[0] == '+' || s[0] == '-') ? 1 : 0;
    bool pointSeen = false;
    for (; i < s.length(); i++){
       if (s[i] == '.'){
           if (pointSeen) return false;
           pointSeen = true;
       } else if (!std::isdigit(s[i])) return false;
    }
    return pointSeen;
}

bool ScalarConverter::isPseudoLiteral(const std::string &s){
    return (s == "nan" || s == "nanf" ||
            s == "+inf" || s == "+inff" ||
            s == "-inf" || s == "-inff");
}

// ─────────────────────────────────────────────
//   Conversions
// ─────────────────────────────────────────────

void ScalarConverter::convertFromChar(const std::string &s){
    double value = static_cast<double>(s[0]);
    printChar(value);
    printInt(value);
    printFloat(value);
    printDouble(value);
}

void ScalarConverter::convertFromInt(const std::string &s){
    int i = std::atoi(s.c_str());
    double value = static_cast<double>(i);
    printChar(value);
    printInt(value);
    printFloat(value);
    printDouble(value);
}

void ScalarConverter::convertFromFloat(const std::string &s){
    float f = std::strtof(s.c_str(), NULL);
    double value = static_cast<double>(f);
    printChar(value);
    printInt(value);
    printFloat(value);
    printDouble(value);
}

void ScalarConverter::convertFromDouble(const std::string &s) {
    double d = std::strtod(s.c_str(), NULL);
    printChar(d);
    printInt(d);
    printFloat(d);
    printDouble(d);
}

void ScalarConverter::handlePseudoLiteral(const std::string &s) {
    std::string base = s;
    if (s[s.size() -1] == 'f')
        base = s.substr(0, s.size() - 1);
    std::cout << "char: impossible\n";
    std::cout << "int: impossible\n";
    std::cout << "float: " << base << "f\n";
    std::cout << "double: " << base << std::endl;
}

// ─────────────────────────────────────────────
//  Printing
// ─────────────────────────────────────────────

void ScalarConverter::printChar(double value) {
    std::cout << "char: ";
    if (std::isnan(value) || value < 0 || value > 127)
        std::cout << "impossible" << std::endl;
    else if (std::isprint(static_cast<int>(value)))
        std::cout << "'" << static_cast<char>(value) << "'" << std::endl;
    else
        std::cout << "Non displayable" << std::endl;
}

void ScalarConverter::printInt(double value) {
    std::cout << "int: ";
    if (std::isnan(value) || value > std::numeric_limits<int>::max() || value < std::numeric_limits<int>::min())
        std::cout << "impossible" << std::endl;
    else
        std::cout << static_cast<int>(value) << std::endl;
}

void ScalarConverter::printFloat(double value) {
    float f = static_cast<float>(value);
    std::cout << std::fixed << std::setprecision(1);
    std::cout << "float: " << f << "f" << std::endl;
}

void ScalarConverter::printDouble(double value) {
    std::cout << std::fixed << std::setprecision(1);
    std::cout << "double: " << value << std::endl;
}

// ─────────────────────────────────────────────
//  Main conversion entry point
// ─────────────────────────────────────────────
void ScalarConverter::convert(const std::string &literal) {
    if (isChar(literal))
        convertFromChar(literal);
    else if (isInt(literal))
        convertFromInt(literal);
    else if (isFloat(literal))
        convertFromFloat(literal);
    else if (isDouble(literal))
        convertFromDouble(literal);
    else if (isPseudoLiteral(literal))
        handlePseudoLiteral(literal);
    else
        std::cout << "Error: invalid literal" << std::endl;
}