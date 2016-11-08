/*
 * TempMoistSensor.cpp
 *
 *  Created on: 25 maj 2016
 *      Author: kirk
 */

#include "TempMoistSensor.hpp"
#include <wiringPi.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "GPIO_Planthouse.hpp"
//Defines
#define MAXTIMINGS  85

//Vars
int dht11_dat[5] = { 0, 0, 0, 0, 0 };




TempMoistSensor::TempMoistSensor()
{
}

TempMoistSensor::~TempMoistSensor()
{
}

bool TempMoistSensor::getMeasurementsFromSensor(sensorMeasurements &a_sensorMeasurement){

  uint8_t laststate = HIGH;
  uint8_t counter   = 0;
  uint8_t j   = 0, i;
  float f; /* fahrenheit */

  dht11_dat[0] = dht11_dat[1] = dht11_dat[2] = dht11_dat[3] = dht11_dat[4] = 0;

  /* pull pin down for 18 milliseconds */
  pinMode( TempMoistSensor1_DHT, OUTPUT );
  digitalWrite( TempMoistSensor1_DHT, LOW );
  delay( 18 );
  /* then pull it up for 40 microseconds */
  digitalWrite( TempMoistSensor1_DHT, HIGH );
  delayMicroseconds( 40 );
  /* prepare to read the pin */
  pinMode( TempMoistSensor1_DHT, INPUT );

  /* detect change and read data */
  for ( i = 0; i < MAXTIMINGS; i++ )
  {
    counter = 0;
    while ( digitalRead( TempMoistSensor1_DHT ) == laststate )
    {
      counter++;
      delayMicroseconds( 1 );
      if ( counter == 255 )
      {
        break;
      }
    }
    laststate = digitalRead( TempMoistSensor1_DHT );

    if ( counter == 255 )
      break;

    /* ignore first 3 transitions */
    if ( (i >= 4) && (i % 2 == 0) )
    {
      /* shove each bit into the storage bytes */
      dht11_dat[j / 8] <<= 1;
      if ( counter > 16 )
        dht11_dat[j / 8] |= 1;
      j++;
    }
  }

  /*
   * check we read 40 bits (8bit x 5 ) + verify checksum in the last byte
   * print it out if data is good
   */
  if ( (j >= 40) &&
       (dht11_dat[4] == ( (dht11_dat[0] + dht11_dat[1] + dht11_dat[2] + dht11_dat[3]) & 0xFF) ) )
  {
    f = dht11_dat[2] * 9. / 5. + 32;
//    printf( "Humidity = %d.%d %% Temperature = %d.%d *C (%.1f *F)\n",
//      dht11_dat[0], dht11_dat[1], dht11_dat[2], dht11_dat[3], f );
    a_sensorMeasurement.MoistMeasurement = (double)dht11_dat[0]+ (double(dht11_dat[1])/100);
    a_sensorMeasurement.TempMeasurement = (double)dht11_dat[2] + (double(dht11_dat[3])/100);
//    a_sensorMeasurements.MoistMeasurement= dht11_dat[0];
//    a_sensorMeasurements.TempMeasurement= dht11_dat[2];
    return true;
  }else  {
    printf( "Data not good, skip\n" );
    return false;
  }
  return true;
}



