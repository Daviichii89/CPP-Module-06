/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davifer2 <davifer2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 14:29:08 by davifer2          #+#    #+#             */
/*   Updated: 2026/02/22 14:29:10 by davifer2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>

int main(int argc, char** argv)
{
	if (argc != 2)
	{
		std::cerr << "Usage: " << argv[0] << " <literal>" << std::endl;
		std::cerr << "Examples:" << std::endl;
		std::cerr << "  " << argv[0] << " 0" << std::endl;
		std::cerr << "  " << argv[0] << " 42.0f" << std::endl;
		std::cerr << "  " << argv[0] << " \"'Z'\"   (char: use double quotes around 'x')" << std::endl;
		std::cerr << "  " << argv[0] << " nan" << std::endl;
		return 1;
	}

	ScalarConverter::convert(argv[1]);
	
	return 0;
}