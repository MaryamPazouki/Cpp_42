/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpazouki <mpazouki@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-09-02 10:39:26 by mpazouki          #+#    #+#             */
/*   Updated: 2025-09-02 10:39:26 by mpazouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Harl.hpp"

int main(int argc, char **argv){
    if (argc != 2){
        std::cout << "Usage: Harl [DEBUG|INFO|WARNING|ERROR]" << std::endl;
        return 1;
    }
    Harl harl;
    harl.complain(argv[1]);
    return 0;
}