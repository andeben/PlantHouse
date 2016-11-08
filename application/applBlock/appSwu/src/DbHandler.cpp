/*
 * DbHandler.cpp
 *
 *  Created on: 25 maj 2016
 *      Author: kirk
 */
#include <DbHandler.hpp>
#include <mysql.h>
#include <string>
#include <stdlib.h>


DbHandler::DbHandler()
{
}

DbHandler::~DbHandler()
{

}

bool DbHandler::connectToDb()
{


  mysql_init(&mysql);
  conn = mysql_real_connect(&mysql, server, user, password, database, 0, NULL, 0);

  if(conn==NULL)
  {
    return false;
  }




  return true;
}
bool DbHandler::disconnectFromDb()
{
  mysql_close(conn);
  return true;
}
bool DbHandler::writeMeasurementToDb(float temperature, float humidity)
{
  std::string measurement="INSERT INTO measurements (sampleId, date, temperature, humidity) VALUES (NULL, now(), '"+std::to_string(temperature)+"', '"+std::to_string(humidity)+"')";
  query_state=mysql_query(conn, measurement.c_str());
  res=mysql_store_result(conn);
  return true;
}

