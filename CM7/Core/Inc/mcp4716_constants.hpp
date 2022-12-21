/*
 * mcp4716_constants.hpp
 * This files consist of all constant addresses and variables
 * that are uses in this driver program
 *  Created on: Dec 15, 2022
 *      Author: uetia
 */

#ifndef __MCP4716_CONSTANTS_HPP
#define __MCP4716_CONSTANTS_HPP
#include <cstdint>

constexpr uint8_t kAddress     = 0x63;
constexpr uint8_t kWriteAdress = (kAddress << 1);
constexpr uint8_t kReadAdress  = (kAddress <<1 | 0x01);
constexpr float  kVoltageReference = 1.25;

#endif /* INC_MCP4716_CONSTANTS_HPP_ */
