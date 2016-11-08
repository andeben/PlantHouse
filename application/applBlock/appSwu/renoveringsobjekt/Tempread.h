/*
 * Tempread.h
 *
 *  Created on: 5 maj 2016
 *      Author: kirk
 */

#ifndef APPSWU_INC_TEMPREAD_H_
#define APPSWU_INC_TEMPREAD_H_

#include <unistd.h>       //Needed for I2C port
#include <fcntl.h>        //Needed for I2C port
#include <sys/ioctl.h>      //Needed for I2C port
#include <linux/i2c-dev.h>    //Needed for I2C port

#include <list>

using namespace std;

class Tempread {
public:
  int readTempFromDevice();
  void setConfigRegister();
  int readTemperature();
  void setUpDevice();
  void closeConnection();

private:
  int m_i2c_file;
};






#endif /* APPSWU_INC_TEMPREAD_H_ */
