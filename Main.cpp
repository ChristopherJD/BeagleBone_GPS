/*
 * Main.cpp
 *
 *  Created on: Apr 8, 2016
 *      Author: chris
 */

#include <iostream>

#include "UART.h"
#include "GPS.h"
#include "nmea.h"

int main(){

	stdGPS::GPS_Test gpsFake;
	stdGPS::GPS gpsReal;
	std::vector<std::string> gpsData;

	NMEA message;
	gpsData = message.parseData(gpsFake.read(),',');

	if(gpsData[0] == "$GPRMC"){
		std::cout << "Everything is OK chris" << std::endl;
	}
	else{
		std::cout << "Get on the phone with logan" << std::endl;
	}
}


