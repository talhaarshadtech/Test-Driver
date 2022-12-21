/*
 * MCP4716.hpp
 *
 *  Created on: Dec 9, 2022
 *      Author: uetia
 */
#ifndef __DDriver_HPP
#define __DDriver_HPP
#include "stm32h7xx_hal.h"
#include "IDriver.hpp"
#ifdef __cplusplus
extern "C"{
#endif

class Mcp4716Dac: public IDriver {
public:
    float m_voltage;
    void Init()override;
    uint16_t Write()override;
    uint16_t Read(void)override;
    uint16_t SerialData()override;
    uint16_t DeInit()override;
    /*
    * getting Analog voltage from dac
    */
    uint16_t GenerateVoltage(uint16_t dacvalue);
    /*
     * Brief :  This is a Test function to test the program
     */
    void toggleLed();
};
#ifdef __cplusplus
}
#endif
#endif /* INC_MCP4716_HPP_ */

