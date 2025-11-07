/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpazouki <mpazouki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 14:45:47 by mpazouki          #+#    #+#             */
/*   Updated: 2025/11/05 15:01:17 by mpazouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <cctype>
#include <iomanip>

// ─────────────────────────────────────────────
// Type Detection
// ─────────────────────────────────────────────

bool ScalarConverter::isChar(const std::string &s){
    return s.length() == 1 && std::isprint(s[0]) && !std::isdigit(s[0]);
}

bool ScalarConverter::isInt(const std::string &s){
    size_t i = 0;
    if (s[i] == '+' || s[i] == '-') i++;
    for (; i< s.length();i++)
        if (!std::isdigit(s[i])) return false;
    return true;
}