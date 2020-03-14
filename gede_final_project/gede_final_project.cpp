#include <iostream>
#include "LocalizationManager.h"

int main()
{
	LocalizedString penismonkeys{ "cancer", "jp", "dildopants" };

    std::cout << penismonkeys.GetValue();
}
