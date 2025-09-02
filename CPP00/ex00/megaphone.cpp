/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpazouki <mpazouki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 11:11:01 by mpazouki          #+#    #+#             */
/*   Updated: 2025/09/01 20:57:36 by mpazouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cctype>



int	main(int argc, char **argv)
{
	if (argc != 1)
	{
		for(int i = 1; argv[i]; i++)
		{
			for(int j = 0; argv[i][j]; j++)
				std::cout << (char)toupper(argv[i][j]);
			std::cout << " ";
		}
		std::cout << std::endl;
	}
	else
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	return (0);
}



 //https://www.youtube.com/watch?v=eNofmKYzje4&list=PL43pGnjiVwgSSRlwfahAuIqoJ8TfDIlHq


/* 

std::string to_uppercase(const std::string &input) {

	std::string result;
	result.reserve(input.length());

	std::size_t i = 0;
	while(i < input.length())
	{
		result += static_cast<char>(std::toupper(static_cast<unsigned char>(input[i])));
		++i;
	}
	return result;
};

int main(int argc, char** argv) {
 	int i;
	
 	i = 0;
 	if (argc < 2)
 	{
 		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
 	}
 	else 
 	{
 		i = 1;
 		while(argv[i]){
 			
 			std::cout << to_uppercase(argv[i]);
 			++i;
 		}
 		std::cout << std::endl;
	}	
	return 0;
}
 */
