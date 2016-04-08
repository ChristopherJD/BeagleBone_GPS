/*
 * GPS.cpp
 *
 *  Created on: Apr 8, 2016
 *      Author: chris
 */

#include "GPS.h"
#include "UART.h"

#define ttyO1 "/dev/ttyO1"
#define baud	9600

SerialCom serial(ttyO1,baud);

stdGPS::GPS::GPS(std::string command) {
	serial.writeCommand(command);
	serial.writeCommand(PMTK_SET_NMEA_UPDATE_1HZ);
	serial.writeCommand(PMTK_API_SET_FIX_CTL_1HZ);
}

const std::string stdGPS::GPS_Test::read(void) {
	return "$GPRMC,081836,A,3751.65,S,14507.36,E,000.0,360.0,130998,011.3,E*62";
}

const std::string stdGPS::GPS::read(void) {
	std::string RxData;

	while ((RxData = serial.readData()) == std::string()) {
		//Wait for GPS data to be read
	}

	return RxData;
}

size_t stdGPS::GPS::write(std::string data){
	serial.writeCommand(data);
	return data.length();
}

