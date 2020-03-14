#pragma once
#include <string>
#include "Locale.h"
#include "LocaleStringIdentifier.h"

class LocalizedString
{
public:
	// Constructors
	LocalizedString();
	LocalizedString(std::string id, std::string locale, std::string value);
	LocalizedString(LocaleStringIdentifier id, Locale locale, std::string value);


	// Getters
	LocaleStringIdentifier GetID();
	Locale GetLocale();
	std::string GetValue();

	bool IsValid();

	// Setters
	void SetValue(std::string str);

	// Static stuff
private:
	LocaleStringIdentifier _id;
	Locale _locale;
	std::string _value;
};

const static LocalizedString STRING_NOT_FOUND{ "N/A", "N/A", "STRING NOT FOUND" };
