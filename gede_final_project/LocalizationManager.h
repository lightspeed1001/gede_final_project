#pragma once
#include <string>
#include <map>
#include <vector>
#include "LocalizedString.h"
typedef std::map<LocaleStringIdentifier, LocalizedString> ID2String;
typedef std::tuple<Locale, ID2String> LocaleTuple;

class LocalizationManager
{
public:
	// Does fuck all
	LocalizationManager();
	// Will automatically load strings from file and choose the first locale it finds
	LocalizationManager(std::string path);
	// Will automatically load strings from file and change to the supplied locale
	LocalizationManager(std::string path, Locale l);

	// Searches through the strings and finds the string you are looking for
	// If it doesn't find that string, it returns string not found
	LocalizedString GetStringForID(LocaleStringIdentifier id);

	// Returns true if it succeeded, false if not
	bool AddString(LocaleStringIdentifier id, Locale l, std::string str);
	bool AddString(LocalizedString lstr);
	
	// Returns true if it managed to change
	// Fails if locale doesn't exist
	bool ChangeLocale(Locale l);

	bool DoesLocaleExist(Locale l);
	bool DoesStringIDExist(LocaleStringIdentifier id);

	// Returns true on success, false on failure
	bool LoadStringsFromFile(std::string path);
	bool SaveStringsToFile(std::string path);

	// Getters
	Locale GetLocale();

	// Setters

private:
	ID2String GetMapForLocale(Locale l);
	void MakeSureDestinationExists(std::string path);

	Locale _locale;
	std::vector<LocaleTuple> _localizedStrings;
};
