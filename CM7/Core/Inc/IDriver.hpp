/*
 * MCP4716X.h
 *
 *  Created on: Dec 8, 2022
 *      Author: uetia
 */

#ifndef __IDriver_HPP
#define __IDriver_HPP
#include "stm32h7xx_hal.h"
#include "bsp.hpp"

#ifdef __cplusplus
extern "C"{
#endif

class IDriver {
public:
    uint8_t data_buffer[MAX_BUFFER_LEN]="HELLO\n\r";

	/* This function uses to initialize the i2c
	 * protocol
	 * */
	 virtual void Init()=0;            // invoked in inherit  class
	  /*
      * This function writes the data of dac using i2c
	  * */
	 virtual uint16_t Write()=0;
     /*
      * This function reads the data of the DAC using
      * i2c protocol*/
	 virtual uint16_t Read(void)=0;
	  /*This function ends the working of the i2c and close the
	            * operation*/
	 virtual uint16_t DeInit()=0;
	  /*
	   * Brief: This function writes the i2c data on the Terminal
	   */
	 virtual uint16_t SerialData()=0;
};
	#ifdef __cplusplus
	}
	#endif

#endif
