#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <string>

class ScalarConverter
{
private:
	enum LiteralType
	{
		TYPE_CHAR,
		TYPE_INT,
		TYPE_FLOAT,
		TYPE_DOUBLE,
		TYPE_INVALID
	};

	ScalarConverter();
	ScalarConverter(const ScalarConverter& other);
	ScalarConverter& operator=(const ScalarConverter& other);
	~ScalarConverter();

	static LiteralType	detectType(const std::string& literal);
	static bool			isChar(const std::string& literal);
	static bool			isInt(const std::string& literal);
	static bool			isFloat(const std::string& literal);
	static bool			isDouble(const std::string& literal);
	static bool			isPseudo(const std::string& literal);
	static bool			isIntegerValue(double numericValue);
	
	static void			convertFromChar(const std::string& literal);
	static void			convertFromInt(const std::string& literal);
	static void			convertFromFloat(const std::string& literal);
	static void			convertFromDouble(const std::string& literal);
	
	static void			printChar(double numericValue, const std::string& literal);
	static void			printInt(double numericValue, const std::string& literal);
	static void			printFloat(double numericValue, const std::string& literal);
	static void			printDouble(double numericValue, const std::string& literal);

public:
	static void convert(const std::string& literal);
};

#endif