#include "LocaleStringIdentifier.h"

LocaleStringIdentifier::LocaleStringIdentifier() : _id("N/A")
{

}

LocaleStringIdentifier::LocaleStringIdentifier(std::string id) : _id(id)
{
	assert(!_id.empty());
}

bool LocaleStringIdentifier::IsValid()
{
	if (_id == "N/A")
		return false;
	return !_id.empty();
}
