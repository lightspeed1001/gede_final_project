#pragma once
#include <string>
#include <assert.h>
class LocaleStringIdentifier
{
public:
	LocaleStringIdentifier();
	LocaleStringIdentifier(std::string id);

	bool IsValid();
	const std::string GetName() { return _id;  }
	friend bool operator<(const LocaleStringIdentifier& l, const LocaleStringIdentifier& r);
private:
	std::string _id;
};
