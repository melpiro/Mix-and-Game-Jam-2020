#pragma once

#include <SFML/System.hpp>
#include <vector>

namespace O{
namespace str {
	std::string convert_SFML_string_to_UTF8_string(const sf::String& str);
	sf::String convert_UTF8_string_to_SFML_string(const std::string& str);
	std::vector<sf::String> convert_UTF8_string_to_SFML_string(const std::vector<std::string>& str);
}
}
