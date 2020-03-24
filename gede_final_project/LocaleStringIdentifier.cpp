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

bool operator<(const LocaleStringIdentifier& l, const LocaleStringIdentifier& r)
{
	return l._id < r._id;
}

//template<typename T>
//struct IdentifierCompare
//{
//	bool operator() (const LocaleStringIdentifier<T>& a, const LocaleStringIdentifier<T>& b)
//	{
//		return a._id < b._id;
//	}
//};