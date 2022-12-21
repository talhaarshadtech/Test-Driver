/*
 * bsp.h
 *board support package file
 *  Created on: December 8, 2022
 */

#ifndef __BSP_HPP
#define __BSP_HPP

#ifdef __cplusplus
extern "C"{
#endif

#include "main.h"

extern I2C_HandleTypeDef hi2c1;
extern UART_HandleTypeDef huart3;

#define MCP4716_DAC_INTERFACE           &hi2c1          // Changes will done here

#define MCP4716_DAC_SERIAL_INTERFACE           &huart3          // Changes will done here

#define MAX_BUFFER_LEN                   10
/*
 * Size of Data of I2C in Polling Mode
 */
#define TIMEOUT_I2C                      50


#ifdef __cplusplus
}
#endif /* end of #ifdef __cplusplus */

#endif /*_bsp_HPP */




/*
// Write modes
#define MCP47x6_NORMAL_MODE                 0
#define MCP47x6_START_FAST_MODE             1
#define MCP47x6_END_FAST_MODE               2
#define MCP47x6_FAST_MODE                   3


#define DAC_10bit                           10


// First LSB in first byte encodes the byte position in the received data from 1 to 4
// First 3 MSB in the first byte encodes how many times to shift the returned bit(s)
// Second byte is the mask for the bit(s)
#define MCP4716_VOL_RDY_BIT                 0b1110000110000000 // shift >> 7x
#define MCP4716_VOL_POR_BIT                 0b1100000101000000 // shift >> 6x
#define MCP4716_VOL_VREF_BITS               0b0110000100011000 // shift >> 3x
#define MCP4716_VOL_PD_BITS                 0b0010000100000110 // shift >> 1
#define MCP4716_VOL_GAIN_BIT                0b0000000100000001 // shift >> 0
#define MCP4716_VOL_DAC_VALUE               0b0000001011111111 // shift >> 0

#define MCP4716_NV_RDY_BIT                  0b1110001110000000 // shift >> 7x
#define MCP4716_NV_POR_BIT                  0b1100001101000000 // shift >> 6x
#define MCP4716_NV_VREF_BITS                0b0110001100011000 // shift >> 3x
#define MCP4716_NV_PD_BITS                  0b0010001100000110 // shift >> 1
#define MCP4716_NV_GAIN_BIT                 0b0000001100000001 // shift >> 0
#define MCP4716_NV_DAC_VALUE                0b0000010011111111 // shift >> 0

// Voltage Reference (VRL) Selection bits VREF1:VREF0
#define MCP4716_VREF_VDD                    0x00 // 0x = VDD (Unbuffered)
#define MCP4716_VREF_PIN_UNBUFF             0x02 // 10 = VREF pin (Unbuffered)
#define MCP4716_VREF_PIN_BUFF               0x03 // 11 = VREF pin (Buffered)

// Power down bits PD1:PD0
#define MCP4716_PD_NORMAL_MODE              0x00 // 00 = Not Powered Down (Normal operation)
#define MCP4716_PD_1K_TO_GND                0x01 // 01 = Powered Down – VOUT is loaded with 1 k resistor to ground
#define MCP4716_PD_125K_TO_GND              0x02 // 10 = Powered Down – VOUT is loaded with 100 k resistor to ground
#define MCP4716_PD_640K_TO_GND              0x03 // 11 = Powered Down – VOUT is loaded with 500 k resistor to ground

// Gain selection bit
#define MCP4716_GAIN_1x                     0x00 // 0 = 1x (gain of 1)
#define MCP4716_GAIN_2x                     0x01 // 1 = 2x (gain of 2). Not applicable when VDD is used as VRL (VREF)
//
//// General Call
//#define MCP4716_GENERAL_CALL_RESET          0x06
//#define MCP4716_GENERAL_CALL_WAKEUP         0x09
//
//// Command bits C2:C0
//#define MCP4716_COM_WRITE_VOL_DAC           0x00 // 00000000    00x
//#define MCP4716_COM_WRITE_VOL_MEMORY        0x40 // 01000000    010 shifted left by 5
//#define MCP4716_COM_WRITE_ALL_MEMORY        0x60 // 01100000    011 shifted left by 5
//#define MCP4716_COM_WRITE_VOL_CONF          0x80 // 10000000    100 shifted left by 5

// global variables


//static uint8_t MCP4716_DACAddress = 0xC6; // 0b11000110 - 10-bit format. Can be changed using MCP4716_SelectDAC()
//static uint8_t MCP4716_DACResolution = 10;

// * MCP4716 DAC Device Address for I2C
// */
//// DAC PARAMETERS

//
//#define DAC_VOL_MEM                      010
//
//#define DAC_ALL_MEM                      011



/*
uint8_t MCP47x6_WriteVolatileDAC(uint16_t dac_value, uint8_t power_bits, uint8_t write_mode){
    // 3rd byte:    b7 b6 b5 b4 b3 b2 b1 b0 (8 data bits)
        uint8_t bytes_data;

        // In fast mode, send the start bit and SLA+W only once and then repeat 2th and 3th bytes
        if((write_mode == MCP47x6_NORMAL_MODE) || (write_mode == MCP47x6_START_FAST_MODE)){
            HAL_I2C_Master_Transmit(MCP4716_DAC_INTERFACE, kWriteAdress, data_buffer, sizeof(data_buffer),TIMEOUT_I2C);  // pass here init function
        }

        // 2nd byte
        bytes_data = ((dac_value >> 8) & 0x0F) | (power_bits << 4);
        HAL_I2C_Master_Transmit(MCP4716_DAC_INTERFACE, kWriteAdress,bytes_data, sizeof(bytes_data),TIMEOUT_I2C);

        // 3rd byte
        bytes_data = dac_value;
        HAL_I2C_Master_Transmit(MCP4716_DAC_INTERFACE, kWriteAdress,bytes_data, sizeof(bytes_data),TIMEOUT_I2C);


        if((write_mode == MCP47x6_NORMAL_MODE) || (write_mode == MCP47x6_END_FAST_MODE)){
            TWI_StopTransmission();  //  pass here deinit function
        }

        if(TWI_ERROR_FLAG) return 0;
        return 1;
    }
*/

