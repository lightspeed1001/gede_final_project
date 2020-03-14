#pragma once
#include <string>
#include <assert.h>
class LocaleStringIdentifier
{
public:
	LocaleStringIdentifier();
	LocaleStringIdentifier(std::string id);

	bool IsValid();
private:
	std::string _id;
};

