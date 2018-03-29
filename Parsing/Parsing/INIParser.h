#include <map>

#pragma once

class INIParser
{
public:
	INIParser();
	~INIParser();

	bool LoadIniFile(const char * fileName);
	bool AddValue(const char * section, const char* key, const char* value);
	bool GetStringValue(const char* section, const char* key, std::string& stringValue);
	bool GetIntValue(const char* section, const char* key, int& intValue);
	bool GetFloatValue(const char* section, const char* key, float& floatValue);
	bool GetBoolValue(const char* section, const char* key, bool& boolValue);



private:
	std::map<std::string, std::string> map;
};

