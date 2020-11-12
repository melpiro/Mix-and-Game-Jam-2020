#include "String/StringFunctions.h"
#include <iomanip>
namespace O{
namespace str {

	std::string subStr(const std::string& str, const int& start, const int& length)
	{
		return str.substr(start, length);
	}
	///////////////////////////////////////////////////////////////
	std::vector<std::string> split(const std::string& str, const char& sparator)
	{
		std::vector<std::string> res;
		int lastCutIndex = 0;
		for (size_t i = 0; i < str.size(); i++)
		{
			if (str[i] == sparator)
			{
				res.push_back(subStr(str, lastCutIndex, i - lastCutIndex));
				lastCutIndex = i + 1;
			}
		}
		res.push_back(subStr(str, lastCutIndex, str.size()));
		return res;
	}
	///////////////////////////////////////////////////////////////
	std::vector<std::string> split(const std::string& str, const std::string& sparator)
	{
		std::vector<std::string> res;
		int lastCutIndex = 0;
		for (size_t i = 0; i < str.size(); i++)
		{
			if (subStr(str, i, sparator.size()) == sparator)
			{
				res.push_back(subStr(str, lastCutIndex, i - lastCutIndex));
				i += sparator.size() - 1;
				lastCutIndex = i + 1;
			}
		}
		res.push_back(subStr(str, lastCutIndex, str.size()));
		return res;
	}
	///////////////////////////////////////////////////////////////
	int findStrInStr(const std::string& string, const std::string& find)
	{
		if (find.size() > string.size()) return -1;
		for (size_t i = 0; i < string.size() - find.size() + 1; i++)
		{
			if (string.substr(i, find.size()) == find) return i;
		}
		return -1;

	}
	///////////////////////////////////////////////////////////////
	void toUpper(std::string& str)
	{
		std::for_each(str.begin(), str.end(), [](char& c) {
			c = ::toupper(c);
		});
	}
	///////////////////////////////////////////////////////////////
	void toLower(std::string& str)
	{
		std::for_each(str.begin(), str.end(), [](char& c) {
			c = ::tolower(c);
		});
	}
	///////////////////////////////////////////////////////////////
	void toUpper(char& c)
	{
		c = ::toupper(c);
	}
	///////////////////////////////////////////////////////////////
	void toLower(char& c)
	{
		c = ::tolower(c);
	}
	///////////////////////////////////////////////////////////////
	bool isNumber(const std::string& str)
	{
		size_t i = 0;
		bool point = false;
		if (str[0] == '-' && str.size() > 1) i = 1;
		for (i; i < str.size(); i++)
		{
			if (!point && i > 0 && i < str.size() - 1 && str[i] == '.')
			{
				point = true;
			}
			else if (!isNumber(str[i])) return false;
		}
		return true;
	}
	///////////////////////////////////////////////////////////////
	bool isNumber(const sf::String& str)
	{
		size_t i = 0;
		bool point = false;
		if (str[0] == '-' && str.getSize() > 1) i = 1;
		for (i; i < str.getSize(); i++)
		{
			if (!point && i > 0 && i < str.getSize() - 1 && str[i] == '.')
			{
				point = true;
			}
			else if (!isNumber(str[i])) return false;
		}
		return true;
	}
	///////////////////////////////////////////////////////////////
	bool isNumber(const char& c)
	{
		return (c >= '0' && c <= '9');
	}
	///////////////////////////////////////////////////////////////
	bool isLetter(const char& c)
	{
		return isUpperCaseLetter(c) || isLowerCaseLetter(c);
	}
	///////////////////////////////////////////////////////////////
	bool isUpperCaseLetter(const char &c)
	{
		return (c >= 'A' && c <= 'Z');
	}
	///////////////////////////////////////////////////////////////
	bool isLowerCaseLetter(const char& c)
	{
		return (c >= 'a' && c <= 'z');
	}
	///////////////////////////////////////////////////////////////
	std::string remove(const std::string& source, const int& from, const int& length)
	{
		return subStr(source, 0, from) + subStr(source, from + length, source.size() - (from + length));
	}
	///////////////////////////////////////////////////////////////
	void remove(std::string* source, const int& from, const int& length)
	{
		*source = remove(*source, from, length);
	}
	///////////////////////////////////////////////////////////////
	std::string remove(const sf::String& source, const int& from, const int& length)
	{
		return source.substring(0, from) + source.substring(from + length, source.getSize() - (from + length));
	}
	///////////////////////////////////////////////////////////////
	void remove(sf::String* source, const int& from, const int& length)
	{
		*source = remove(*source, from, length);
	}
	///////////////////////////////////////////////////////////////
	void remplace(std::string& source, const int& from, const int& length, const std::string& str)
	{
		remove(&source, from, length);
		insert(source, from, str);
	}
	///////////////////////////////////////////////////////////////
	void remplace(sf::String& source, const int& from, const int& length, const sf::String& str)
	{
		remove(&source, from, length);
		insert(source, from, str);
	}
	///////////////////////////////////////////////////////////////
	int remplace(std::string& source, const std::string& strIn, const std::string& str)
	{
		int nb = 0;
		int v = -1;
		do {
			v = findStrInStr(source, strIn);

			if (v != -1)
			{
				remplace(source, v, strIn.size(), str);
				nb++;
			}

		} while (v != -1);
		return nb;
	}
	///////////////////////////////////////////////////////////////
	void insert(std::string& source, const int& index, const std::string& data)
	{
		for (size_t i = 0; i < data.size(); i++)
		{
			source.insert(source.begin() + index + i, data[i]);
		}

	}
	///////////////////////////////////////////////////////////////
	void insert(sf::String& source, const int& index, const sf::String& data)
	{
		source.insert(index, data);
	}

	///////////////////////////////////////////////////////////////
	std::vector<char> generateRandomAlphabet()
	{
		return vector::shuffle(vector::createVector(26, 'A', 1));

	}
	bool isVoyelle(const char& c)
	{
		if (!isLetter(c)) return false;
		return (c == 'a' || c == 'o' || c == 'i' || c == 'e' || c == 'u' || c == 'y')
			|| (c == 'A' || c == 'O' || c == 'I' || c == 'E' || c == 'U' || c == 'Y');
	}
	bool isConsone(const char& c)
	{
		if (!isLetter(c)) return false;
		return !isVoyelle(c);
	}
	void swap(std::string& str, const int& i, const int& j)
	{
		char tmp = str[i];
		str[i] = str[j];
		str[j] = tmp;
	}
	void reverse(std::string& str)
	{
		std::string res = "";
		for (int i = str.size() - 1 ; i >= 0; i--)
		{
			res += str[i];
		}
		str = res;
	}

	
	int getOccurences(const std::string& str, const char& c)
	{
		int nb = 0;
		for (size_t i = 0; i < str.size(); i++)
		{
			if (c == str[i]) nb ++;
		}
		return nb;
	}

	std::vector<char> toCharVector(const std::string& str)
	{
		return std::vector<char>(str.c_str(), str.c_str() + str.size());
	}

	std::string to_string(const char& c)
	{
		return std::string(1, c);
	}

	std::string to_string(const double& value, const int& precision)
	{
		std::stringstream ss;
		ss << std::fixed << std::setprecision(precision) << value;
		std::string mystring = ss.str();

		return mystring;
	}

	std::string to_string(const std::vector<char>& vec)
	{
		std::string str = "";
		for (size_t i = 0; i < vec.size(); i++)
		{
			str+=vec[i];
		}
		return str;
	}
	//std::string to_string(const int& v) { return std::to_string(v); }
	std::string to_string(const double& v) { return std::to_string(v); }
	std::string to_string(const float& v) { return std::to_string(v); }
	std::string to_string(const int& v) { return std::to_string(v); }
	int to_int(const std::string& str)
	{
		return atoi(str.c_str());
	}

	int to_int(const char& c)
	{
		return to_int(to_string(c));
	}

	float to_float(const std::string& str)
	{
		return atof(str.c_str());
	}

	double to_double(const std::string& str)
	{
		return to_float(str);
	}
}	
}

std::string operator*(const std::string& str, const int& m)
{
	std::string res = "";
	for (int i = 0; i < m; i++)
	{
		res += str;
	}
	return res;
}

std::string operator*(const int& m, const std::string& str)
{
	std::string res = "";
	for (int i = 0; i < m; i++)
	{
		res += str;
	}
	return res;

}


void operator*=(std::string& str, const int& m)
{
	str = str * m;
}

std::string operator+(const std::string& str, const int& n)
{
	return str + O::str::to_string(n);
}
std::string operator+(const std::string& str, const double& n)
{
	return str + O::str::to_string(n);
}
std::string operator+(const std::string& str, const float& n)
{
	return str + O::str::to_string(n);
}
std::string operator+(const int& n, const std::string& str)
{
	return O::str::to_string(n) + str;
}
std::string operator+(const double& n, const std::string& str)
{
	return O::str::to_string(n) + str;
}
std::string operator+(const float& n, const std::string& str)
{
	return O::str::to_string(n) + str;
}


void operator+=(std::string& str, const int& n)
{
	str = str + n; 
}
void operator+=(std::string& str, const double& n)
{
	str = str + n;
}
void operator+=(std::string& str, const float& n)
{
	str = str + n;
}


