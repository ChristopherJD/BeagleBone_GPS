/*
 * GPS.h
 *
 *  Created on: Apr 8, 2016
 *      Author: chris
 */

#ifndef GPS_H_
#define GPS_H_

#include <string>
#include <vector>

#define PMTK_SET_NMEA_UPDATE_100_MILLIHERTZ		"$PMTK220,10000*2F\r\n"
#define PMTK_SET_NMEA_UPDATE_200_MILLIHERTZ		"$PMTK220,5000*1B\r\n"
#define PMTK_SET_NMEA_UPDATE_1HZ				"$PMTK220,1000*1F\r\n"
#define PMTK_SET_NMEA_UPDATE_5HZ				"$PMTK220,200*2C\r\n"
#define PMTK_SET_NMEA_UPDATE_10HZ				"$PMTK220,100*2F\r\n"

#define PMTK_API_SET_FIX_CTL_100_MILLIHERTZ		"$PMTK300,10000,0,0,0,0*2C\r\n"
#define PMTK_API_SET_FIX_CTL_200_MILLIHERTZ		"$PMTK300,5000,0,0,0,0*18\r\n"
#define PMTK_API_SET_FIX_CTL_1HZ				"$PMTK300,1000,0,0,0,0*1C\r\n"
#define PMTK_API_SET_FIX_CTL_5HZ				"$PMTK300,200,0,0,0,0*2F\r\n"

#define PMTK_SET_BAUD_57600						"$PMTK251,57600*2C\r\n"
#define PMTK_SET_BAUD_9600						"$PMTK251,9600*17\r\n"

#define RMCONLY 	"$PMTK314,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0*29\r\n"
#define RMCGGA		"$PMTK314,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0*28\r\n"
#define ALLDATA		"$PMTK314,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0*28\r\n"
#define OUTPUT_OFF	"$PMTK314,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0*28\r\n"

namespace stdGPS {
/*Interface*/
class Igps {
public:
	virtual const std::string read(void) = 0;
	virtual size_t write(std::string) = 0;
	virtual ~Igps() {
	}
};

class GPS: public Igps {
public:
	const std::string read(void);
	size_t write(std::string);
	GPS(){}
	GPS(std::string);
	~GPS() {
	}
};

class GPS_Test: public Igps {
public:
	const std::string read(void);
	size_t write(std::string){return 0;}
	~GPS_Test() {
	}
};
}

#endif /* GPS_H_ */
