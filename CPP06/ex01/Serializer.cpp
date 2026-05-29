/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpazouki <mpazouki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 09:43:35 by mpazouki          #+#    #+#             */
/*   Updated: 2026/05/27 11:10:54 by mpazouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer(){}
Serializer::Serializer(const Serializer &){}
Serializer &Serializer::operator = (const Serializer &){
    return *this;
}
Serializer::~Serializer(){}

uintptr_t Serializer::serialize(Data* ptr){
    return reinterpret_cast<uintptr_t>(ptr); // Convert pointer (address) to an unsigned integer type
}
 
Data* Serializer::deserialize(uintptr_t raw){
    return reinterpret_cast<Data *>(raw); // Convert the unsigned integer back to a pointer of type Data*
}