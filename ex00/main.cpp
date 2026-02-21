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