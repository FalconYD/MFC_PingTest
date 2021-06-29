#pragma once
class FileManager
{
private:
public:
	static bool			INISave(const std::string filename, const std::string section, const std::string key, const std::string value);
	static bool			INISave(const std::string filename, const std::string section, const std::string key, const int value);
	static bool			INISave(const std::string filename, const std::string section, const std::string key, const double value);
	static std::string	INILoad(const std::string filename, const std::string section, const std::string key, const std::string default);
	static int			INILoad(const std::string filename, const std::string section, const std::string key, const int default);
	static double		INILoad(const std::string filename, const std::string section, const std::string key, const double default);
};

