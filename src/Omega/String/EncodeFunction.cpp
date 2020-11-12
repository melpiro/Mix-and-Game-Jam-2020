#include "String/EncodeFunction.h"
namespace O{
namespace str {

    
    std::string convert_SFML_string_to_UTF8_string(const sf::String& str)
    {
        auto cUtf8 = str.toUtf8(); // on convertis de l'utf 8 (encodage unicode clasique des std string)
        std::string res="";
        for (size_t i = 0; i < cUtf8.size(); i++)
        {
            res += cUtf8[i];
        }
        return res;
    }


    sf::String convert_UTF8_string_to_SFML_string(const std::string& str)
    {
        return sf::String::fromUtf8(str.begin(), str.end());
    }

    std::vector<sf::String> convert_UTF8_string_to_SFML_string(const std::vector<std::string>& str)
    {
        std::vector<sf::String> r;
        for (size_t i = 0; i < str.size(); i++)
        {
            r.push_back(convert_UTF8_string_to_SFML_string(str[i]));
        }
        return r;
    }

	
}
}

