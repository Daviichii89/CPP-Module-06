/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davifer2 <davifer2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 14:28:59 by davifer2          #+#    #+#             */
/*   Updated: 2026/02/22 14:29:03 by davifer2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>
#include <limits>
#include <cstdlib>
#include <cctype>

bool ScalarConverter::isPseudo(const std::string& literal)
{
	return (literal == "nan" || literal == "+inf" || literal == "-inf" ||
	        literal == "nanf" || literal == "+inff" || literal == "-inff");
}

bool ScalarConverter::isIntegerValue(double numericValue)
{
	return (numericValue >= std::numeric_limits<int>::min() &&
	        numericValue <= std::numeric_limits<int>::max() &&
	        numericValue == static_cast<int>(numericValue));
}

bool ScalarConverter::isChar(const std::string& literal)
{
	return (literal.length() == 3 && literal[0] == '\'' && literal[2] == '\'');
}

bool ScalarConverter::isInt(const std::string& literal)
{
	if (literal.empty())
		return false;
	
	size_t i = 0;
	if (literal[i] == '+' || literal[i] == '-')
		i++;
	if (i >= literal.length())
		return false;
	while (i < literal.length())
	{
		if (!std::isdigit(literal[i]))
			return false;
		i++;
	}

	long parsedAsLong = std::strtol(literal.c_str(), NULL, 10);
	return (parsedAsLong >= std::numeric_limits<int>::min() &&
	        parsedAsLong <= std::numeric_limits<int>::max());
}

bool ScalarConverter::isFloat(const std::string& literal)
{
	if (isPseudo(literal) && literal[literal.length() - 1] == 'f')
		return true;
	if (literal.empty() || literal[literal.length() - 1] != 'f')
		return false;
	if (literal.find('.') == std::string::npos)
		return false;
	char* endPtr;
	std::strtof(literal.c_str(), &endPtr);
	return (*endPtr == 'f' && endPtr == &literal[literal.length() - 1]);
}

bool ScalarConverter::isDouble(const std::string& literal)
{
	if (isPseudo(literal) && literal[literal.length() - 1] != 'f')
		return true;
	if (!literal.empty() && literal[literal.length() - 1] == 'f')
		return false;
	
	char* endPtr;
	std::strtod(literal.c_str(), &endPtr);
	return (*endPtr == '\0' && endPtr != literal.c_str());
}

ScalarConverter::LiteralType ScalarConverter::detectType(const std::string& literal)
{
	if (isChar(literal))
		return TYPE_CHAR;
	if (isInt(literal))
		return TYPE_INT;
	if (isFloat(literal))
		return TYPE_FLOAT;
	if (isDouble(literal))
		return TYPE_DOUBLE;
	return TYPE_INVALID;
}

void ScalarConverter::printChar(double numericValue, const std::string& literal)
{
	std::cout << "char: ";
	if (isPseudo(literal))
	{
		std::cout << "impossible" << std::endl;
		return;
	}
	if (numericValue < std::numeric_limits<char>::min() ||
	    numericValue > std::numeric_limits<char>::max())
	{
		std::cout << "impossible" << std::endl;
		return;
	}
	char asChar = static_cast<char>(numericValue);
	if (!std::isprint(static_cast<unsigned char>(asChar)))
	{
		std::cout << "Non displayable" << std::endl;
		return;
	}
	std::cout << "'" << asChar << "'" << std::endl;
}

void ScalarConverter::printInt(double numericValue, const std::string& literal)
{
	std::cout << "int: ";
	if (isPseudo(literal))
	{
		std::cout << "impossible" << std::endl;
		return;
	}
	if (numericValue < std::numeric_limits<int>::min() ||
	    numericValue > std::numeric_limits<int>::max())
	{
		std::cout << "impossible" << std::endl;
		return;
	}
	int asInt = static_cast<int>(numericValue);
	std::cout << asInt << std::endl;
}

void ScalarConverter::printFloat(double numericValue, const std::string& literal)
{
	std::cout << "float: ";
	if (literal == "nanf")
	{
		std::cout << "nanf" << std::endl;
		return;
	}
	if (literal == "+inff")
	{
		std::cout << "+inff" << std::endl;
		return;
	}
	if (literal == "-inff")
	{
		std::cout << "-inff" << std::endl;
		return;
	}
	float asFloat = static_cast<float>(numericValue);
	std::cout << asFloat;
	if (isIntegerValue(static_cast<double>(asFloat)))
		std::cout << ".0";
	std::cout << "f" << std::endl;
}

void ScalarConverter::printDouble(double numericValue, const std::string& literal)
{
	std::cout << "double: ";
	if (literal == "nan" || literal == "nanf")
	{
		std::cout << "nan" << std::endl;
		return;
	}
	if (literal == "+inf" || literal == "+inff")
	{
		std::cout << "+inf" << std::endl;
		return;
	}
	if (literal == "-inf" || literal == "-inff")
	{
		std::cout << "-inf" << std::endl;
		return;
	}
	std::cout << numericValue;
	if (isIntegerValue(numericValue))
		std::cout << ".0";
	std::cout << std::endl;
}

void ScalarConverter::convertFromChar(const std::string& literal)
{
	char charFromLiteral = literal[1];
	double numericValue = static_cast<double>(charFromLiteral);
	printChar(numericValue, literal);
	printInt(numericValue, literal);
	printFloat(numericValue, literal);
	printDouble(numericValue, literal);
}

void ScalarConverter::convertFromInt(const std::string& literal)
{
	long parsedLong = std::strtol(literal.c_str(), NULL, 10);
	double numericValue = static_cast<double>(parsedLong);
	printChar(numericValue, literal);
	printInt(numericValue, literal);
	printFloat(numericValue, literal);
	printDouble(numericValue, literal);
}

void ScalarConverter::convertFromFloat(const std::string& literal)
{
	char* endPtr;
	float parsedFloat = std::strtof(literal.c_str(), &endPtr);
	double numericValue = static_cast<double>(parsedFloat);
	printChar(numericValue, literal);
	printInt(numericValue, literal);
	printFloat(numericValue, literal);
	printDouble(numericValue, literal);
}

void ScalarConverter::convertFromDouble(const std::string& literal)
{
	char* endPtr;
	double numericValue = std::strtod(literal.c_str(), &endPtr);
	printChar(numericValue, literal);
	printInt(numericValue, literal);
	printFloat(numericValue, literal);
	printDouble(numericValue, literal);
}

void ScalarConverter::convert(const std::string& literal)
{
	LiteralType detectedType = detectType(literal);
	switch (detectedType)
	{
		case TYPE_CHAR:
			convertFromChar(literal);
			break;
		
		case TYPE_INT:
			convertFromInt(literal);
			break;
		
		case TYPE_FLOAT:
			convertFromFloat(literal);
			break;
		
		case TYPE_DOUBLE:
			convertFromDouble(literal);
			break;
		
		case TYPE_INVALID:
		default:
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
			std::cout << "float: impossible" << std::endl;
			std::cout << "double: impossible" << std::endl;
			break;
	}
}