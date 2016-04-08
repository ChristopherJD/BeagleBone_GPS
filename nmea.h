/*
 * nmea.h
 *
 *  Created on: Apr 8, 2016
 *      Author: chris
 */

#ifndef NMEA_H_
#define NMEA_H_

#include <string>
#include <vector>

/*Interface*/
class Inmea {
public:
	virtual void setData(std::vector<std::string>) = 0;
	virtual std::vector<std::string> parseData(std::string, char) = 0;
	virtual bool validateChecksum(std::string) = 0;
	virtual ~Inmea() {
	}
};

class NMEA: public Inmea {
protected:
	std::string Message_ID; /* RMC Protocol header */
	std::string UTC_Time; /* hhmmss.sss */
	std::string Latitude; /* ddmm.mmmm */
	std::string N_S_Indicator; /* N = North, S = South */
	std::string Longitude; /* dddmm.mmmm */
	std::string E_W_Indicator; /* E = East, W = West */
	std::string Checksum; /* checksum value that starts with '*' */
public:
	void setData(std::vector<std::string>) {
	}
	std::vector<std::string> parseData(std::string, char);
	bool validateChecksum(std::string);
	~NMEA() {
	}
};

class RMC: public NMEA{
private:
	std::string Status; /* A = data valid, V = data NOT valid */
	std::string Speed_Over_Ground; /* In Knots */
	std::string Course_Over_Ground; /* Degrees */
	std::string Date; /* ddmmyy */
	std::string Mode; /* A = autonomous mode, D = Differential mode, E = Estimated mode */
public:
	void setData(std::vector<std::string>);
};

#endif /* NMEA_H_ */
