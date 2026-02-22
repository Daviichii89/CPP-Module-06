/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davifer2 <davifer2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 14:28:50 by davifer2          #+#    #+#             */
/*   Updated: 2026/02/22 14:28:52 by davifer2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <iostream>

int main()
{
	Data data;
	data.value = 42;
	data.name = "test";

	std::cout << "Original Data: value=" << data.value << ", name=\"" << data.name << "\"" << std::endl;
	std::cout << "Address of data: " << &data << std::endl;

	uintptr_t raw = Serializer::serialize(&data);
	std::cout << "Serialized (uintptr_t): " << raw << std::endl;

	Data* ptr = Serializer::deserialize(raw);
	std::cout << "Deserialized pointer: " << ptr << std::endl;
	std::cout << "Deserialized Data: value=" << ptr->value << ", name=\"" << ptr->name << "\"" << std::endl;

	if (ptr == &data)
		std::cout << "OK: deserialize(serialize(ptr)) == ptr" << std::endl;
	else
		std::cout << "ERROR: pointers differ!" << std::endl;

	return 0;
}
