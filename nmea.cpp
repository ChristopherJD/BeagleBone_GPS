/*
 * nmea.cpp
 *
 *  Created on: Apr 8, 2016
 *      Author: chris
 */

#include <sstream>
#include "nmea.h"

bool NMEA::validateChecksum(std::string sentence) {
	int checksum { 0 };
	unsigned int nmeaChecksumLength { 2 };

	for (char x : sentence) {
		if ((x != '*') && (x != '$')) {
			checksum ^= static_cast<int>(x);
		}
		if (x == '*')
			goto endOfChecksum;
	}

	endOfChecksum: std::string temp = sentence.substr(
			static_cast<unsigned int>(sentence.size() - nmeaChecksumLength - 1), //-1 due to '\n' at end of message
			nmeaChecksumLength);
	std::stringstream ss { };
	ss << temp;
	int nmeaChecksum { };
	ss >> std::hex >> nmeaChecksum;

	if (nmeaChecksum == checksum) {
		return true;
	} else {
		return false;
	}
}

std::vector<std::string> NMEA::parseData(std::string sentence, char delimeter) {
	std::vector<std::string>::size_type pos { 0 };
	std::vector<std::string> temp { };

	while ((pos = sentence.find(delimeter)) != std::string::npos) {
		temp.push_back(sentence.substr(0, pos));
		sentence.erase(0, pos + sizeof(delimeter));
	}

	return temp;
}

