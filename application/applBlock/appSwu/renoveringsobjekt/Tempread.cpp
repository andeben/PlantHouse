#include "../renoveringsobjekt/Tempread.h"

/*
 * Tempread.cpp
 *
 *  Created on: 5 maj 2016
 *      Author: kirk
 */
#include <fcntl.h>
#include <stdint.h>
#include "unistd.h"
#include <iostream>

#include "../renoveringsobjekt/I2CHandler.c"
void  Tempread::setUpDevice()
{


//  // Open a connection to the I2C userspace control file.
//  if ((m_i2c_file = open(I2C_FILE_NAME, O_RDWR)) < 0) {
//    perror("Unable to open i2c control file");
//    exit(1);
//  }
//
//  if (ioctl(m_i2c_file,I2C_SLAVE,0x48) < 0)
//    exit(2);
//  int32_t value;
//  if(get_i2c_register(m_i2c_file, 0x48, 0x00, &value) != 0) {
//    printf("Unable to get register!\n");
//  }
//  else {
//    printf("Register %d: %d (%x)\n", 0x01, value, value);
//  }


}

void Tempread::setConfigRegister()
{
//  if(set_i2c_register(m_i2c_file, 0x48, 0x01, 0x83C4) != 0) {
//     printf("Unable to get register!\n");
//   }
//   else {
//     printf("Set Register %d: %d (%x)\n", 0x01, 0x83C4, 0x83C4);
//   }
}

int Tempread::readTemperature()
{

//  int32_t value;
//  if(get_i2c_register(m_i2c_file, 0x48, 0x00, &value) != 0) {
//    printf("Unable to get register!\n");
//    return -1;
//  }
//  else {
//    printf("Register %d: %d (%x)\n", 0x01, value, value);
//  }
//  float voltValue;
//  voltValue = value/32768 *3.3;
//  printf("Voltage value: %f \n", voltValue);
//  float temperature;
//  temperature =(27/2.5)* voltValue;
//  printf("Temperature value: %f \n", temperature);
//  return temperature;
return 1;
}

void Tempread::closeConnection()
{
// close(m_i2c_file);
}

