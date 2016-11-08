#include <wiringPi.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <TempMoistSensor.hpp>
#include <DbHandler.hpp>
#include <PumpRelay.hpp>
int main()
{
  if ( wiringPiSetup() == -1 )
    exit( 1 );
  TempMoistSensor* m_tempMoistSensor = new TempMoistSensor();
  DbHandler* m_pDbHandler = new DbHandler();
  sensorMeasurements sensMeasurement;
  PumpRelay* m_pumpRelay = new PumpRelay();
printf( "Kastellgatan XV Klimatstation\n" );

  m_pDbHandler->connectToDb();
  while ( 1 )
  {

    if (m_tempMoistSensor->getMeasurementsFromSensor(sensMeasurement))
    {
      printf( "Humidity = %f %% Temperature = %f *C \n", sensMeasurement.MoistMeasurement, sensMeasurement.TempMeasurement);
      m_pDbHandler->writeMeasurementToDb(sensMeasurement.TempMeasurement, sensMeasurement.MoistMeasurement);
      //delay(1800000);
      m_pumpRelay->switchRelay();
      delay(10000);
    }

   delay( 1000 ); /* wait 1sec to refresh */
  }
  delete m_tempMoistSensor;
  delete m_pumpRelay;
  m_pDbHandler->disconnectFromDb();
  delete m_pDbHandler;
  return 0;
}
