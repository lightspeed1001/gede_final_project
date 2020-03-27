# Multi-Language Support for Game Engines

This is my final project for Game Engine Architecture at Reykjavik University. The intent is to add multi-language support to existing game engines, by making an easy to use library that handles a lot of the hassle for you.

# How to Run
Build and run with the latest Visual Studio (2019) and C++17. 

## Tests
In the main file, there are a few tests, showing functionality.

# How to Use

+ Initialize the `LocalizationManager`
+ Create some `LocalizedString`(s). The constructor takes in `(std::string id, std::string locale, std::string value)` or `(LocaleStringIdentifier id, Locale locale, std::string value)`
+ Add your string(s) to the manager with `manager.AddString(yourString)`. It will create any new locales that pop up.
+ Change the locale of the manager to the locale you wish to use with `manager.ChangeLocale(someLocale)`. It returns true if it managed to change, false otherwise. It fails to change if the locale doesn't exist.
+ You can now request any string you've added by calling `manager.GetStringForID(someID)`

## Future Work
Since this project was halted halfway through, there's a lot that needs to be done.

+ Easy support for loading from file (CSV from Google Doc, for example)
+ Check for missing strings
+ A better tech demo!
