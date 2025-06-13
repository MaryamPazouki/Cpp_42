/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpazouki <mpazouki@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-06-13 11:11:01 by mpazouki          #+#    #+#             */
/*   Updated: 2025-06-13 11:11:01 by mpazouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cctype>

void make_upper(char **str){
	
	int i = 0;

	while((*str)[i])
	{
		if ((*str)[i] >= 'a' || (*str)[i] <= 'z')
			(*str)[i] -= 32;
		i++;
	}
};

// int main(int argc, char** argv)
// {
// 	int i;
	
// 	i = 0;
// 	if (argc < 2)
// 	{
// 		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
// 	}
// 	else 
// 	{
// 		i = 1;
// 		while(argv[i]){
// 			make_upper(&argv[i]);
// 			std::cout << argv[i];
// 			i++;
// 		}
// 		std::cout << "\n";
// 	}	
// 	return 0;
// }



int main(int argc, char** argv) {
    if (argc < 2) {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
        return 0;
    }

    for (int i = 1; i < argc; ++i) {
        std::string word = argv[i];
        for (char& c : word)
            std::cout << (char)std::toupper(c);
    }

    std::cout << std::endl;
    return 0;
}
