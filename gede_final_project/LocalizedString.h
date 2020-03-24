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
	const LocaleStringIdentifier GetID();
	const Locale GetLocale();
	const std::string GetValue();

	const bool IsValid();

	// Setters
	void SetValue(std::string str);

	// Static stuff
private:
	LocaleStringIdentifier _id;
	Locale _locale;
	std::string _value;
};

const static LocalizedString STRING_NOT_FOUND{ "N/A", "N/A", "STRING NOT FOUND" };
