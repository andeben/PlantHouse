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
#include <fstream>
#include <iostream>



PumpRelay::PumpRelay()
{
  pinMode(PumpRelay_DHT, PUD_UP);
  pinMode(PumpRelay_DHT, OUTPUT);
  digitalWrite(PumpRelay_DHT, LOW);
  CreateFile();

  printf( "PumpRelay: Contructor\n" );
}

PumpRelay::~PumpRelay()
{
}

bool PumpRelay::OpenPumpForXSeconds(int time)
{
  digitalWrite(PumpRelay_DHT, HIGH);
  printf( "PumpRelay: Open for %u seconds\n", time );
  delay(1500);
  digitalWrite(PumpRelay_DHT, LOW);
  CreateFile();
}
bool PumpRelay::HeartBeat()
{
printf( "PumpRelay::HeartBeat()\n" );
CheckFile();
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

bool PumpRelay::CheckFile()
{
  printf( "PumpRelay::CheckFile()\n" );

  char data[100];
  m_readStateFile.open("/tmp/pumpState.dat");
  m_readStateFile >> data;
  m_readStateFile.close();

  std::string dataStr(data);
  char stateFromFile = dataStr.at(dataStr.find(relayState)+relayState.size());
  if(stateFromFile == '0' && isRelayClosed)
  {
    printf( "stateFromFile == '0' and isRelayClosed == false\n" );

  }else if(stateFromFile == '1' && !isRelayClosed)
  {
    printf( "stateFromFile == '1' and isRelayClosed == true\n" );
    OpenPumpForXSeconds(2);
  }
}

bool PumpRelay::CreateFile()
{
  m_stateFile.open("/tmp/pumpState.dat");
  m_stateFile << ""+relayState+"0" << std::endl;
  m_stateFile.close();
}
