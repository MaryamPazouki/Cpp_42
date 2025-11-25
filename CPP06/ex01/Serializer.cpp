/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpazouki <mpazouki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 09:43:35 by mpazouki          #+#    #+#             */
/*   Updated: 2025/11/17 10:27:39 by mpazouki         ###   ########.fr       */
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
    return reinterpret_cast<uintptr_t>(ptr);
}
 
Data* Serializer::deserialize(uintptr_t raw){
    return reinterpret_cast<Data *>(raw);
}