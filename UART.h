/*
 * UART.h
 *
 *  Created on: Apr 8, 2016
 *      Author: chris
 */

#ifndef UART_H_
#define UART_H_

#include <stdint.h>
#include <string>

#define bufferSize 128

class SerialCom {
private:
	std::string device;
	int fd;
	char buff[bufferSize];
public:
	SerialCom(std::string,unsigned long);
	std::string readData(void);
	size_t writeCommand(std::string);
};

#endif /* UART_H_ */
