#include "LocalizedString.h"

LocalizedString::LocalizedString() : _id("N/A"), _locale("N/A"), _value("")
{

}

LocalizedString::LocalizedString(std::string id, std::string locale, std::string value) : _id(id), _locale(locale), _value(value)
{

}

LocalizedString::LocalizedString(LocaleStringIdentifier id, Locale locale, std::string value) : _id(id), _locale(locale), _value(value)
{

}

LocaleStringIdentifier LocalizedString::GetID()
{
	return _id;
}

Locale LocalizedString::GetLocale()
{
	return _locale;
}

std::string LocalizedString::GetValue()
{
	return _value;
}

bool LocalizedString::IsValid()
{
	return _id.IsValid();
}

void LocalizedString::SetValue(std::string str)
{
	_value = str;
}
