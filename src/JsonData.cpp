
#include "JsonData.hpp"

JsonData::JsonData()
{

}

JsonData::JsonData(sf::String strJson)
{
    if (!isValue(strJson, *this))
    {
        std::cout << "Erreur de parsage, format invalide !" <<std::endl;
    }
}

void JsonData::readFile(std::string path)
{
    std::vector<sf::String> line = O::str::convert_UTF8_string_to_SFML_string(O::file::getAllLines(path));
    sf::String strJson = "";
    for (size_t i = 0; i < line.size(); i++)
    {
        strJson += line[i];
    }
    
    if (!isValue(strJson, *this))
    {
        std::cout << "Erreur de parsage, format invalide !" <<std::endl;
    }
}

bool JsonData::isValue(sf::String& strJson, JsonData& value)
{
    int n = getNbWhitesSpaces(strJson);
    strJson.erase(0,n);

    if (isNULL(strJson))
    {
        n = getNbWhitesSpaces(strJson);
        strJson.erase(0,n);
        return true;
    }
    else if (isBool(strJson, value))
    {
        n = getNbWhitesSpaces(strJson);
        strJson.erase(0,n);
        return true;
    }
    else if (isString(strJson, value))
    {
        n = getNbWhitesSpaces(strJson);
        strJson.erase(0,n);
        return true;
    }
    else if (isNumber(strJson, value))
    {
        n = getNbWhitesSpaces(strJson);
        strJson.erase(0,n);
        return true;
    }
    else if (isObject(strJson, value))
    {
        n = getNbWhitesSpaces(strJson);
        strJson.erase(0,n);
        return true;
    }
    else if (isArray(strJson, value))
    {
        n = getNbWhitesSpaces(strJson);
        strJson.erase(0,n);
        return true;
    }
    else
    {
        value.desaloc();
        return false;
    }
}


bool JsonData::isArray(sf::String& strJson, JsonData& value)
{
    if (value.m_value != nullptr)
    {
        value.desaloc();
    }
    if (value.m_value == nullptr)
    {
        value.m_value = new std::vector<JsonData>(0);
        value.m_valueType = ARRAY;
    }


    sf::String strJsonCpy = strJson;
    if (strJsonCpy[0] == '[')
    {
        strJsonCpy.erase(0);

        bool firstLoop = true;

        do
        {

            if (!firstLoop&&strJsonCpy[0] == ',') strJsonCpy.erase(0);

            int n = getNbWhitesSpaces(strJsonCpy);
            strJsonCpy.erase(0, n);

            JsonData subValue;

            if (firstLoop&&strJsonCpy[0] == ']')
            {
                strJsonCpy.erase(0);
                strJson = strJsonCpy;
                return true;
            }
            else if (isValue(strJsonCpy, subValue))
            {
                ((std::vector<JsonData>*) value.m_value)->push_back(subValue);
            }
            else return false;

            firstLoop = false;

        } while (strJsonCpy[0] == ',');

        if (strJsonCpy[0] == ']')
        {
            strJsonCpy.erase(0);
            strJson = strJsonCpy;
            return true;
        }
        else return false;
    }
    else return false;
}


bool JsonData::isObject(sf::String& strJson, JsonData& value)
{
    if (value.m_value != nullptr)
    {
        value.desaloc();
    }
    if (value.m_value == nullptr)
    {
        value.m_value = new std::map<sf::String, JsonData>;
        value.m_valueType = OBJECT;
    }

    sf::String strJsonCpy = strJson;
    if (strJsonCpy[0] == '{')
    {
        strJsonCpy.erase(0);

        bool firstLoop = true;

        do
        {
            if (!firstLoop&&strJsonCpy[0] == ',') strJsonCpy.erase(0);


            int n = getNbWhitesSpaces(strJsonCpy);

            strJsonCpy.erase(0, n);

            JsonData key;

            if (firstLoop&&strJsonCpy[0] == '}')
            {
                strJsonCpy.erase(0);
                strJson = strJsonCpy;
                return true;
            }
            else if (isString(strJsonCpy, key))
            {
                n = getNbWhitesSpaces(strJsonCpy);
                strJsonCpy.erase(0, n);

                if (strJsonCpy[0] == ':')
                {
                    strJsonCpy.erase(0);

                    JsonData subValue;
                    if (isValue(strJsonCpy, subValue))
                    {
                        ((std::map<sf::String, JsonData>*) value.m_value)->insert(
                            std::make_pair(*(sf::String*)key.m_value, subValue)
                        );

                        key.desaloc();
                    }
                    else
                    {
                        return false;
                    }
                }
                else return false;
            }
            else return false;

            firstLoop = false;

        } while (strJsonCpy[0] == ',');

        if (strJsonCpy[0] == '}')
        {
            strJsonCpy.erase(0);
            strJson = strJsonCpy;
            return true;
        }
        else return false;
    }
    else return false;
}


bool JsonData::isNumber(sf::String& strJson, JsonData& value)
{
    if (value.m_value != nullptr)
    {
        value.desaloc();
    }
    if (value.m_value == nullptr)
    {
        value.m_value = new double;
        value.m_valueType = NUMBER;
    }

    sf::String strJsonCpy = strJson;

    bool isNegavtive = false;
    sf::String integerPart="";
    sf::String fractionPart="";
    bool exponentPartIsNegavtive = false;
    sf::String exponentPart="";
    if (strJsonCpy[0] == '-')
    {
        isNegavtive = true;
        strJsonCpy.erase(0);
    }

    if (strJsonCpy[0] >= '0' && strJsonCpy[0] <= '9')
    {
        do
        {
            integerPart += strJsonCpy[0];
            strJsonCpy.erase(0);
        } while (strJsonCpy.getSize() > 0 && strJsonCpy[0] >= '0' && strJsonCpy[0] <= '9');

        if (strJsonCpy.getSize() == 0)
        {
            strJson = strJsonCpy;
            *(double*)value.m_value = O::str::to_int(integerPart);
            return true;
        }
        if (strJsonCpy[0] == '.')
        {
            strJsonCpy.erase(0);
            if (strJsonCpy[0] >= '0' && strJsonCpy[0] <= '9')
            {
                do
                {
                    fractionPart += strJsonCpy[0];
                    strJsonCpy.erase(0);
                } while (strJsonCpy.getSize() > 0 && strJsonCpy[0] >= '0' && strJsonCpy[0] <= '9');
            }
            else return false;
        }

        if (fractionPart == "") fractionPart = "0";

        if (strJsonCpy.getSize() == 0)
        {


            strJson = strJsonCpy;
            *(double*)value.m_value = O::str::to_double(integerPart + "." + fractionPart);
            return true;
        }
        if (strJsonCpy[0] == 'e' || strJsonCpy[0] == 'E'  )
        {
            strJsonCpy.erase(0);
            if (strJsonCpy[0] == '-')
            {
                exponentPartIsNegavtive = true;
                strJsonCpy.erase(0);
            }
            else if (strJsonCpy[0] == '+')
            {
                exponentPartIsNegavtive = false;
                strJsonCpy.erase(0);
            }

            if (strJsonCpy[0] >= '0' && strJsonCpy[0] <= '9')
            {
                do
                {
                    exponentPart += strJsonCpy[0];
                    strJsonCpy.erase(0);
                } while (strJsonCpy.getSize() > 0 && strJsonCpy[0] >= '0' && strJsonCpy[0] <= '9');
            }
            else return false;
        }

        if (exponentPart == "") exponentPart = "0";

        double expoVal = O::str::to_int(exponentPart);
        if (exponentPartIsNegavtive) expoVal *= -1.0;

        strJson = strJsonCpy;
        *(double*)value.m_value = O::str::to_double(integerPart + "." + fractionPart) * std::pow(10, expoVal);

        return true;
    }
    else return false;
}
bool JsonData::isString(sf::String& strJson, JsonData& value)
{
    if (value.m_value != nullptr)
    {
        value.desaloc();
    }
    if (value.m_value == nullptr)
    {
        value.m_value = new sf::String;
        value.m_valueType = STRING;
    }

    *(sf::String*)value.m_value = "";
    if (strJson[0] == '"')
    {
        size_t i = 1;
        while (i < strJson.getSize() && strJson[i] != '"')
        {
            i++;
        }
        if (i < strJson.getSize())
        {
            *(sf::String*)value.m_value = strJson.substring(1, i - 1);
            strJson.erase(0, i + 1);

            return true;
        }
    }
    return false;
}

bool JsonData::isBool(sf::String& strJson, JsonData& value)
{
    if (value.m_value != nullptr)
    {
        value.desaloc();
    }
    if (value.m_value == nullptr)
    {
        value.m_value = new bool;
        value.m_valueType = BOOLEAN_;
    }

    if (strJson.substring(0, 4) == "true")
    {
        strJson.erase(0, 4);
        *(bool*)value.m_value = true;
        return true;
    }
    else if (strJson.substring(0, 5) == "false")
    {
        strJson.erase(0, 5);
        *(bool*)value.m_value = false;
        return true;
    }
    return false;
}
bool JsonData::isNULL(sf::String& strJson)
{
    if (strJson.substring(0, 4) == "null")
    {
        strJson.erase(0, 4);
        return true;
    }
    return false;
}


int JsonData::getNbWhitesSpaces(sf::String& strJson)
{
    int i = 0;
    while (i < strJson.getSize() &&
        (strJson[i] == ' ' ||strJson[i] == '\n' ||strJson[i] == '\r' ||strJson[i] == '\t' ))
    {
        i++;
    }
    return i;
}

JsonData JsonData::operator[](int index)
{
    if (m_valueType == ARRAY)
    {
        return ((std::vector<JsonData>*)m_value)->at(index);
    }
    else std::cout << "Error not an array" <<std::endl;

    return JsonData();
}
JsonData JsonData::operator[](sf::String key)
{
    if (m_valueType == OBJECT)
    {
        return ((std::map<sf::String,JsonData>*)m_value)->at(key);
    }
    else std::cout << "Error not an object" <<std::endl;

    return JsonData();
}

void JsonData::desaloc()
{
    if (m_value != nullptr)
    {
        if (m_valueType == ARRAY)
        {
        auto it = ((std::vector<JsonData>*)m_value)->begin();
            for (it; it != ((std::vector<JsonData>*)m_value)->end(); it++)
            {
                it->desaloc();
            }

            delete m_value;
            m_value = nullptr;
            m_valueType = NULL_TYPE;
        }
        else if (m_valueType == OBJECT)
        {
            auto it = ((std::map<sf::String, JsonData>*)m_value)->begin();
            for (it; it != ((std::map<sf::String, JsonData>*)m_value)->end(); it++)
            {
                it->second.desaloc();
            }

            delete m_value;
            m_value = nullptr;
            m_valueType = NULL_TYPE;
        }
        else if (m_valueType == NUMBER)
        {
            delete m_value;
            m_value = nullptr;
            m_valueType = NULL_TYPE;
        }
        else if (m_valueType == STRING)
        {
            delete m_value;
            m_value = nullptr;
            m_valueType = NULL_TYPE;
        }
        else if (m_valueType == BOOLEAN_)
        {
            delete m_value;
            m_value = nullptr;
            m_valueType = NULL_TYPE;
        }
    }
}

TYPES JsonData::getType() const
{
    return m_valueType;
}
void* JsonData::getValue() const
{
    return m_value;
}

int JsonData::getRecurLevel() const
{
    return recurLevelForPrint;
}


void JsonData::setRecurLevel(int v)
{
    recurLevelForPrint = v;
}

std::ostream& operator<<(std::ostream& os, JsonData d)
{
    if (d.getType() == NULL_TYPE)
    {
        os << std::string("\t") * d.getRecurLevel() <<"null";
    }
    else if (d.getType() == BOOLEAN_)
    {
        os<< std::string("\t") * d.getRecurLevel() << *((bool*) d.getValue());
    }
    else if (d.getType() == NUMBER)
    {
        os << std::string("\t") * d.getRecurLevel()<< *((double*) d.getValue());

    }
    else if (d.getType() == STRING)
    {
        os << std::string("\t") * d.getRecurLevel()<<'"' <<((sf::String*)(d.getValue()))->toAnsiString()<<'"';
    }
    else if (d.getType() == OBJECT)
    {
        std::map<sf::String,JsonData>* array = (std::map<sf::String,JsonData>*)d.getValue();

        d.setRecurLevel(d.getRecurLevel()+1);
        os<<"\n" << std::string("\t") * d.getRecurLevel()<< "{\n";
        auto it = array->begin();
        int i = 0;
        for (it; it != array->end();it++)
        {
            os<< std::string("\t") * d.getRecurLevel() << it->first.toAnsiString()<<" : ";
            os<< it->second;
            os<< "\n";

            i++;
        }

        os << std::string("\t") * d.getRecurLevel()<< "}";

        d.setRecurLevel(d.getRecurLevel()-1);


    }
    else if (d.getType() == ARRAY)
    {
        std::vector<JsonData>* array = (std::vector<JsonData>*)d.getValue();

        os<<'\n' << std::string("\t") * d.getRecurLevel()<< "[\n";

        d.setRecurLevel(d.getRecurLevel()+1);
        auto it = array->begin();
        for (it; it!= array->end();it++)
        {
            os<< std::string("\t") * d.getRecurLevel() << *it<<"\n";
        }
        d.setRecurLevel(d.getRecurLevel()-1);

        os << std::string("\t") * d.getRecurLevel()<< "]";

    }


    return os;
}
