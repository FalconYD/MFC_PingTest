#include "pch.h"
#include "FileManager.h"

bool FileManager::INISave(const std::string filename, const std::string section, const std::string key, const std::string value)
{
	bool bRet = WritePrivateProfileStringA(section.c_str(), key.c_str(), value.c_str(), filename.c_str());
	return bRet;
}
bool FileManager::INISave(const std::string filename, const std::string section, const std::string key, const int value)
{
	return INISave(filename, section, key, string_format("%d", value));
}

bool FileManager::INISave(const std::string filename, const std::string section, const std::string key, const double value)
{
	return INISave(filename, section, key, string_format("%lf", value));
}
std::string	FileManager::INILoad(const std::string filename, const std::string section, const std::string key, const std::string default)
{
	char chValue[MAXSTRINGLENGTH] = { 0, };
	GetPrivateProfileStringA(section.c_str(), key.c_str(), default.c_str(), chValue, MAXSTRINGLENGTH, filename.c_str());
	return string_format("%s", chValue);
}

int FileManager::INILoad(const std::string filename, const std::string section, const std::string key, const int default) 
{
	std::string strValue = INILoad(filename, section, key, string_format("%d",default));
	return atoi(strValue.c_str());
}

double FileManager::INILoad(const std::string filename, const std::string section, const std::string key, const double default) 
{
	std::string strValue = INILoad(filename, section, key, string_format("%lf", default));
	return atof(strValue.c_str());
}