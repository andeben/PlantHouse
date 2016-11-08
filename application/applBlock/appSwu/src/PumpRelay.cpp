/*
 * SoilMoistSensor.cpp
 *
 *  Created on: 5 Nov 2016
 *      Author: Anders
 */

#include "PumpRelay.hpp"
#include <wiringPi.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <GPIO_Planthouse.hpp>
#include <stdio.h>




PumpRelay::PumpRelay()
{
  pinMode(PumpRelay_DHT, PUD_UP);
  pinMode(PumpRelay_DHT, OUTPUT);
  digitalWrite(PumpRelay_DHT, LOW);
  printf( "PumpRelay: Contructor\n" );
}

PumpRelay::~PumpRelay()
{
}

bool PumpRelay::OpenPumpForXSeconds(int time)
{

}

bool PumpRelay::OpenPump()
{

}

bool PumpRelay::closePump()
{

}

bool PumpRelay::switchRelay()
{

  isRelayClosed = !isRelayClosed;
  if(isRelayClosed)
  {
    digitalWrite(PumpRelay_DHT, HIGH);
    printf( "PumpRelay: Open\n" );

  }
  else
  {
    digitalWrite(PumpRelay_DHT, LOW);
    printf( "PumpRelay: Close\n" );
  }
}

