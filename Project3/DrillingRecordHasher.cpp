#include "DrillingRecordHasher.h"
#include <string>

unsigned long DrillingRecordHasher :: hash(const DrillingRecord& item) const
{
	std::string tempString = item.getString(1);
	int keyVal = 0;
	
	// Returns the ascii value of the time
	for (unsigned int i = 0; i < tempString.length(); i++) {
		keyVal += tempString[i];
	}

	return keyVal;
}
