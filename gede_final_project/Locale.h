#pragma once
#include <string>
class Locale
{
public:
	Locale();
	Locale(std::string name);
	std::string GetName();

	friend bool operator<(const Locale& l, const Locale& r);
private:
	std::string _name;
};

