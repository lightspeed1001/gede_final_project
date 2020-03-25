#include <iostream>
#include "LocalizationManager.h"

int main()
{
	LocalizedString first_en{ "First", "en", "Pants, but with extra steps." };
	LocalizedString first_is{ "First", "is", "Buxur, nema með auka skrefum." };
	LocalizedString second_en{ "Second", "en", "Meow." };

	LocalizationManager manager;

	manager.AddString(first_en);
	manager.AddString(first_is);
	manager.AddString(second_en);

	manager.ChangeLocale(Locale("en"));

	std::cout << "===============================" << std::endl << "Locale checks: " << std::endl;
	std::cout << "Does en exist? Should be true " << manager.DoesLocaleExist(Locale("en")) << std::endl;
	std::cout << "Does is exist? Should be true " << manager.DoesLocaleExist(Locale("is")) << std::endl;
	std::cout << "Does jp exist? Should be false " << manager.DoesLocaleExist(Locale("jp")) << std::endl;
	
	std::cout << "===============================" << std::endl << "ID checks: " << std::endl;
	std::cout << "Does first exist? Should be true " << manager.DoesStringIDExist(LocaleStringIdentifier("First")) << std::endl;
	std::cout << "Does second exist? Should be true " << manager.DoesStringIDExist(LocaleStringIdentifier("Second")) << std::endl;
	std::cout << "Does penis exist? Should be false " << manager.DoesStringIDExist(LocaleStringIdentifier("Penis")) << std::endl;

	std::cout << "===============================" << std::endl << "All Locales: " << std::endl;
	auto allLocales = manager.GetAllLocales();
	for (Locale l : allLocales)
	{
		std::cout << l.GetName() << std::endl;
	}

	std::cout << "===============================" << std::endl << "All IDs: " << std::endl;
	auto allIDs = manager.GetAllIDs();
	for (LocaleStringIdentifier id : allIDs)
	{
		std::cout << id.GetName() << std::endl;
	}

	std::cout << "===============================" << std::endl;
	std::cout << "Do all strings exist in all locales? " << manager.IsEverythingOK() << std::endl;

	std::cout << "===============================" << std::endl;
	std::cout << "First string in english: " << manager.GetStringForID("First").GetValue() << std::endl;
	std::cout << "Second string in english: " << manager.GetStringForID("Second").GetValue() << std::endl;
	
	manager.ChangeLocale("is");
	std::cout << "First string in icelandic: " << manager.GetStringForID("First").GetValue() << std::endl;
	std::cout << "Second string in icelandic: " << manager.GetStringForID("Second").GetValue() << std::endl;

}
