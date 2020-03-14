#pragma once
#include <string>
class Locale
{
public:
	Locale();
	Locale(std::string name);
	std::string GetName();
private:
	std::string _name;
};

