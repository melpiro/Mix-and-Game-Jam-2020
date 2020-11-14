#pragma once


#include <SFML/System/String.hpp>
#include <map>
#include "Omega/String/StringFunctions.h"
#include "Omega/Files/FileFunctions.h"
#include "Omega/Vector/VectorFunctions.h"
#include "Omega/String/EncodeFunction.h"
//#ifdef __MINGW32__
//#undef BOOL
//#endif // __MINGW32__

enum TYPES{
    NULL_TYPE,
    STRING,
    NUMBER,
    OBJECT,
    ARRAY,
    BOOLEAN_
};


class JsonData
{
public:
    JsonData();
    JsonData(sf::String strJson);

    void readFile(std::string path);

    void desaloc();

    JsonData operator[](int index);
    JsonData operator[](sf::String key);

    TYPES getType() const;
    void* getValue() const;
    int getRecurLevel() const;
    void setRecurLevel(int v);



private:

    static bool isValue(sf::String& strJson, JsonData& value);

    static bool isArray(sf::String& strJson, JsonData& value);
    static bool isObject(sf::String& strJson, JsonData& value);
    static bool isNumber(sf::String& strJson, JsonData& value);
    static bool isString(sf::String& strJson, JsonData& value);
    static bool isBool(sf::String& strJson, JsonData& value);
    static bool isNULL(sf::String& strJson);


    static int getNbWhitesSpaces(sf::String& strJson);


    TYPES m_valueType = NULL_TYPE;
    void* m_value = nullptr;

    int recurLevelForPrint = 0;

};


std::ostream& operator<<(std::ostream& os, JsonData d);
