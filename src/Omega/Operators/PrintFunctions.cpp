#include "Operators/PrintFunctions.h"


std::ostream& operator<<(std::ostream& os, sf::String str)
{
	os << O::str::convert_SFML_string_to_UTF8_string(str);
	return os;
}

std::ostream& operator<<(std::ostream& os, const sf::Color v)
{ 
	os<< "("<< (int)v.r<<", "<<(int)v.g<<", "<<(int)v.b<<", "<<(int)v.a<<")";
	return os;
}