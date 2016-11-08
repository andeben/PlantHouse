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


using namespace std;

class PumpRelay {
public:
  PumpRelay();
  ~PumpRelay();
  bool OpenPumpForXSeconds(int time);
  bool OpenPump();
  bool closePump();
  bool switchRelay();
private:
  bool isRelayClosed = false;
};





#endif /* APPSWU_INC_PUMPRELAYSENSOR_HPP_ */
