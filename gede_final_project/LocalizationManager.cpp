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
	if (DoesLocaleExist(lstr.GetLocale()))
	{
		// Locale does exist, get the map for it and put the thing in there
		ID2String* idStringMap = GetMapForLocale(lstr.GetLocale());
		(*idStringMap)[lstr.GetID()] = lstr;
	}
	else
	{
		// Locale doesn't exist, need to init the map for it
		ID2String idStringMap;
		idStringMap[lstr.GetID()] = lstr;
		LocaleTuple lt = std::tuple(lstr.GetLocale(), idStringMap);
		_localizedStrings.push_back(lt);
	}
	return true;
}

bool LocalizationManager::ChangeLocale(Locale l)
{
	if (!DoesLocaleExist(l))
		return false;

	_locale = l;
	return true;
}

bool LocalizationManager::DoesLocaleExist(Locale l)
{
	for (LocaleTuple& lt : _localizedStrings)
	{
		auto& [locale, idStrMap] = lt;
		if (locale.GetName() == l.GetName())
			return true;
	}
	return false;
}

bool LocalizationManager::DoesStringIDExist(LocaleStringIdentifier id)
{
	for (LocaleTuple& lt : _localizedStrings)
	{
		auto& [locale, idStrMap] = lt;
		auto iterator = idStrMap.find(id);
		if (iterator != idStrMap.end())
			return true;
	}
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

bool LocalizationManager::IsEverythingOK()
{
	return false;
}

std::set<Locale> LocalizationManager::GetAllLocales()
{
	std::set<Locale> allLocales;
	for (LocaleTuple& lt : _localizedStrings)
	{
		auto& [locale, idStrMap] = lt;
		allLocales.insert(locale);
	}
	return allLocales;
}

std::set<LocaleStringIdentifier> LocalizationManager::GetAllIDs()
{
	std::set<LocaleStringIdentifier> allIDs;
	for (LocaleTuple& lt : _localizedStrings)
	{
		auto& [locale, idStrMap] = lt;
		for (auto idstrTuple : idStrMap)
		{
			auto [id, lstr] = idstrTuple;
			allIDs.insert(id);
		}
	}
	return allIDs;
}

std::set<std::tuple<LocaleStringIdentifier, Locale>> LocalizationManager::GetAllMissingStrings()
{
	return std::set<std::tuple<LocaleStringIdentifier, Locale>>();
}

Locale LocalizationManager::GetLocale()
{
	return _locale;
}

ID2String* LocalizationManager::GetMapForLocale(Locale l)
{
	for (LocaleTuple& lt : _localizedStrings)
	{
		auto& [locale, str] = lt;
		if (locale.GetName() == l.GetName())
			return &str;
	}
	return nullptr;
}

void LocalizationManager::MakeSureDestinationExists(std::string path)
{
}
