#include "Locale.h"
#include <assert.h>

Locale::Locale() : _name("N/A")
{
}

Locale::Locale(std::string name) : _name(name)
{
	assert(!_name.empty());
}

std::string Locale::GetName()
{
	return _name;
}
