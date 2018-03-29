#include "INIParser.h"
#include <fstream>
#include <map>



INIParser::INIParser()
{
}


INIParser::~INIParser()
{
}

bool INIParser::LoadIniFile(const char * fileName)
{
	// Load an INI file. 
	// Create testText.txt
	std::ofstream outFile;
	std::string outputFileName = "testText.txt";

	outFile.open(outputFileName);


	if (outFile.is_open())

	{

		while (!outFile.eof())

		{



		}
		outFile.close();
	}

	// Populates the map with keys and values using the add value function.

	return false;
}

bool INIParser::AddValue(const char * section, const char * key, const char * value)
{
	// Adds a value to the map. 
	// Combines the _pcSection, with _pcKey to create a key for the map.
	return false;
}

bool INIParser::GetStringValue(const char * section, const char * key, std::string & stringValue)
{
	// Returns true if the value was found. 
	// _rStrValue will be populated with the correct data if the key is found in the map
	return false;
}

bool INIParser::GetIntValue(const char * section, const char * key, int & intValue)
{
	// Returns true if the value was found. 
	// _riValue will be populated with the correct data if the key is found in the map
	return false;
}

bool INIParser::GetFloatValue(const char * section, const char * key, float & floatValue)
{
	// Returns true if the value was found. 
	// _rfValue will be populated with the correct data if the key is found in the map. 
	return false;
}

bool INIParser::GetBoolValue(const char * section, const char * key, bool & boolValue)
{
	// Returns true if the value was found. 
	// _rbValue will be populated with the correct data if the key is found in the map. 
	return false;
}
