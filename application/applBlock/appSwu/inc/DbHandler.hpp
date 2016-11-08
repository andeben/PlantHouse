/*
 * DbHandler.hpp
 *
 *  Created on: 25 maj 2016
 *      Author: kirk
 */

#ifndef APPSWU_INC_DBHANDLER_HPP_
#define APPSWU_INC_DBHANDLER_HPP_

#include "mysql.h"

#define DB_USERNAME planthouse
#define DB_PASSWORD myPlantSql
#define DB_ADDRESS 192.168.10.182

class DbHandler {
public:
  DbHandler();
  ~DbHandler();

  bool connectToDb();
  bool disconnectFromDb();
  bool writeMeasurementToDb(float temperature, float humidity);
  bool readMeasurementFromDb(){return true;};
private:
  const char *server="localhost";
  const char *user="Planthouse";
  const char *password="myPlantSql";
  const char *database="Planthouse";

  MYSQL *conn, mysql;
  MYSQL_RES *res;
  MYSQL_ROW row;
  int query_state;
};



#endif /* APPSWU_INC_DBHANDLER_HPP_ */
