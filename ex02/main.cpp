/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davifer2 <davifer2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 14:27:59 by davifer2          #+#    #+#             */
/*   Updated: 2026/02/22 15:13:57 by davifer2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <exception>

Base* generate(void)
{
	int r = rand() % 3;
	if (r == 0)
		return new A();
	if (r == 1)
		return new B();
	return new C();
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p))
	{
		std::cout << "A" << std::endl;
		return;
	}
	if (dynamic_cast<B*>(p))
	{
		std::cout << "B" << std::endl;
		return;
	}
	if (dynamic_cast<C*>(p))
	{
		std::cout << "C" << std::endl;
		return;
	}
}

void identify(Base& r)
{
	try
	{
		(void)dynamic_cast<A&>(r);
		std::cout << "A" << std::endl;
		return;
	}
	catch (std::exception& e) { (void)e; }
	try
	{
		(void)dynamic_cast<B&>(r);
		std::cout << "B" << std::endl;
		return;
	}
	catch (std::exception& e) { (void)e; }
	try
	{
		(void)dynamic_cast<C&>(r);
		std::cout << "C" << std::endl;
		return;
	}
	catch (std::exception& e) { (void)e; }
}

int main()
{
	srand(time(NULL));
	for (int i = 0; i < 10; i++)
	{
		Base* p = generate();
		
		std::cout << "Test " << i + 1 << ": " << std::endl;
		std::cout << "  Pointer:   ";
		identify(p);
		std::cout << std::endl;

		std::cout << "  Reference: ";
		identify(*p);
		std::cout << std::endl;

		delete p;
		std::cout << "---------------------------------------------" << std::endl;
	}
	return 0;
}
