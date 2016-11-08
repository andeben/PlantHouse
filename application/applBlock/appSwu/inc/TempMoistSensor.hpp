/*
 * TempMoistSensor.hpp
 *
 *  Created on: 25 maj 2016
 *      Author: kirk
 */

#ifndef APPSWU_INC_TEMPMOISTSENSOR_HPP_
#define APPSWU_INC_TEMPMOISTSENSOR_HPP_
//Includes
#include <stdlib.h>
#include <string>

//Defines
#define MAX_NUMBER_OF_MEASUREMENTS 5

struct sensorMeasurements{
  double TempMeasurement;
  double MoistMeasurement;
};

using namespace std;

class TempMoistSensor {
public:
  TempMoistSensor();
  ~TempMoistSensor();
  bool getMeasurementsFromSensor(sensorMeasurements &a_sensorMeasurement);

private:
};





#endif /* APPSWU_INC_TEMPMOISTSENSOR_HPP_ */
