#pragma once
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <string.h>

#include "Vector/VectorFunctions.h"

namespace O{
namespace str {

	std::string subStr(const std::string& str, const int& start, const int& length);
	std::vector<std::string> split(const std::string& str, const char& sparator);
	std::vector<std::string> split(const std::string& str, const std::string& sparator);

	int findStrInStr(const std::string& string, const std::string& find);

	void toUpper(std::string& str);
	void toLower(std::string& str);
	void toUpper(char& c);
	void toLower(char& c);
	
	bool isNumber(const std::string& str);
	bool isNumber(const sf::String& str);

	bool isNumber(const char& c);
	bool isLetter(const char& c);
	bool isUpperCaseLetter(const char& c);
	bool isLowerCaseLetter(const char& c);

	std::string remove(const std::string& source, const int& from, const int& length);
	void remove(std::string* source, const int& from, const int& length);
	std::string remove(const sf::String& source, const int& from, const int& length);
	void remove(sf::String* source, const int& from, const int& length);

	void remplace(std::string& source, const int& from, const int& length, const std::string& str);
	void remplace(sf::String& source, const int& from, const int& length, const sf::String& str);
	int remplace(std::string& source, const std::string& strIn, const std::string& str);

	void insert(std::string& source, const int& index, const std::string& data);
	void insert(sf::String& source, const int& index, const sf::String& data);

	std::vector<char> generateRandomAlphabet();

	bool isVoyelle(const char& c);
	bool isConsone(const char& c);

	void swap(std::string& str, const int& i, const int& j);
	void reverse(std::string& str);

	std::string genStringNumPuissance(const int& nb);
	std::string genStringNumIndex(const int& nb);


	int getOccurences(const std::string& str, const char& c);

	std::vector<char> toCharVector(const std::string& str);


	std::string to_string(const char& c);
	std::string to_string(const double& value, const int& precision);
	std::string to_string(const std::vector<char>& vec);
	//std::string to_string(const int& v);
	std::string to_string(const int& v);
	std::string to_string(const double& v);
	std::string to_string(const float& v);

	int to_int(const std::string& str);
	int to_int(const char& c);

	float to_float(const std::string& str);
	double to_double(const std::string& str);
}
}

std::string operator*(const std::string& str, const int& m);
std::string operator*(const int& m, const std::string& str);

std::string operator+(const std::string& str, const int& n);
std::string operator+(const std::string& str, const double& n);
std::string operator+(const std::string& str, const float& n);
std::string operator+(const int& n, const std::string& str);
std::string operator+(const double& n, const std::string& str);
std::string operator+(const float& n, const std::string& str);
void operator+=(std::string& str, const int& n);
void operator+=(std::string& str, const double& n);
void operator+=(std::string& str, const float& n);

void operator*=(std::string& str, const int& m);
