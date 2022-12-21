/*
 * MCP4716X.cpp
 *
 *  Created on: Dec 8, 2022
 *      Author: uetia
 */
#include "mcp4716_constants.hpp"
#include "bsp.hpp"
#include "IDriver.hpp"
#include "Mcp4716Dac.hpp"
#include "stm32h7xx_hal.h"

/*brief: This function initialize the I2C Protocol
 *
 */
void Mcp4716Dac::Init() {        // virtual functions invoked here
	HAL_I2C_Init(MCP4716_DAC_INTERFACE);  // check later
}
// invoked in inherit  class
uint16_t Mcp4716Dac::Write() {
    return HAL_I2C_Master_Transmit(MCP4716_DAC_INTERFACE, kWriteAdress, data_buffer, MAX_BUFFER_LEN,TIMEOUT_I2C);
}
/**
 *
 */
uint16_t Mcp4716Dac::Read() {
	return HAL_I2C_Master_Receive(MCP4716_DAC_INTERFACE, kReadAdress, data_buffer, MAX_BUFFER_LEN, TIMEOUT_I2C);
}

uint16_t Mcp4716Dac::SerialData() {
    return HAL_UART_Transmit(MCP4716_DAC_SERIAL_INTERFACE,data_buffer,MAX_BUFFER_LEN,TIMEOUT_I2C);
}

/*brief: this function uses for closing or stopping the i2c protocol
 *
 *
 */
uint16_t Mcp4716Dac::DeInit() {
    return HAL_I2C_DeInit(MCP4716_DAC_INTERFACE);
}
/*
 * Brief: Generating Analog voltage
 */
void Mcp4716Dac::GenerateVoltage(uint16_t dacvalue){
    Init();
    Write();

	m_voltage=(kVoltageReference*dacvalue)/1024;
}
void Mcp4716Dac::toggleLed() {
	HAL_GPIO_WritePin(GPIOE,GPIO_PIN_1,GPIO_PIN_SET);
	HAL_Delay(500);
	HAL_GPIO_WritePin(GPIOE,GPIO_PIN_1,GPIO_PIN_RESET);
	HAL_Delay(500);
}




























//void Mcp4716Dac::SetValue() {
//  int i=2000;
//  while(i<4000){
//  HAL_DAC_SetValue(MCP4716_DAC,CHANNEL,ALIGNMENT_DAC,i);
//  HAL_Delay(10);
//  i +=4;
//  }
//  while(i>2000)
//  {
//      HAL_DAC_SetValue(MCP4716_DAC,CHANNEL,ALIGNMENT_DAC,i);
//      HAL_Delay(10);
//      i -=4;
//  }
//  //HAL_DAC_SetValue(MCP4716,CHANNEL,DAC_ALIGN_12B_R,m_data);
//    }

//
//uint16_t Mcp4716Dac::Write(uint16_t *data_buffer,uint16_t Length) {
//    //uint16_t ret=BSP_ERROR_BUS_FAILURE;
//    if(HAL_I2C_Master_Transmit(MCP4716_DAC_INTERFACE, kWriteAdress, data_buffer, MAX_BUFFER_LEN,TIMEOUT_I2C) == HAL_OK) {
//        return MAX_BUFFER_LEN;
//    }
//    else {
//    return Error_Handler();
//    }
//}



