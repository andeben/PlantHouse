/*
 * PumpRelay.hpp
 *
 *  Created on: 5 Nov 2016
 *      Author: Anders
 */

#ifndef APPSWU_INC_PUMPRELAY_HPP_
#define APPSWU_INC_PUMPRELAY_HPP_
//Includes
#include <stdlib.h>
#include <string>
#include <fstream>



using namespace std;

class PumpRelay {
public:
  PumpRelay();
  ~PumpRelay();
  bool HeartBeat();
  bool OpenPumpForXSeconds(int time);
  bool OpenPump();
  bool closePump();
  bool switchRelay();
private:
  ofstream m_stateFile;
  ifstream m_readStateFile;
  bool CheckFile();
  bool CreateFile();
  bool WriteStateToFile(int state);
  bool isRelayClosed = false;
  string PUMPSTATE_FILE = "pumpState.dat";
  string relayState = "RELAY_STATE=";
};





#endif /* APPSWU_INC_PUMPRELAYSENSOR_HPP_ */
