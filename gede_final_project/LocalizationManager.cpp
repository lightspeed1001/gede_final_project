#include "LocalizationManager.h"

LocalizationManager::LocalizationManager()
{

}

LocalizationManager::LocalizationManager(std::string path)
{
}

LocalizationManager::LocalizationManager(std::string path, Locale l)
{
}

LocalizedString LocalizationManager::GetStringForID(LocaleStringIdentifier id)
{
	return LocalizedString();
}

bool LocalizationManager::AddString(LocaleStringIdentifier id, Locale l, std::string str)
{
	return false;
}

bool LocalizationManager::AddString(LocalizedString lstr)
{
	return false;
}

bool LocalizationManager::ChangeLocale(Locale l)
{
	return false;
}

bool LocalizationManager::DoesLocaleExist(Locale l)
{
	return false;
}

bool LocalizationManager::DoesStringIDExist(LocaleStringIdentifier id)
{
	return false;
}

bool LocalizationManager::LoadStringsFromFile(std::string path)
{
	return false;
}

bool LocalizationManager::SaveStringsToFile(std::string path)
{
	return false;
}

Locale LocalizationManager::GetLocale()
{
	return _locale;
}

ID2String LocalizationManager::GetMapForLocale(Locale l)
{
	return ID2String();
}

void LocalizationManager::MakeSureDestinationExists(std::string path)
{
}
