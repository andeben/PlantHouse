/*
 * timer.h
 *
 *  Created on: 16 maj 2015
 *      Author: kirk
 */

#ifndef INC_TIMER_H_
#define INC_TIMER_H_

#include "notificationIf.h"
#include <string>
#include <list>
#include "defines.h"
#include "time.h"
using namespace std;

class timer {
private:
list<notificationIf*> m_parents;
int  m_type;
bool m_run;
int m_timeout;

public:
  timer(notificationIf* a_pParent, int a_type, int timeout);
  ~timer(){};
  void addParent(notificationIf* a_pParent);
  void run();
  void stop();
  int getName(){return m_type;};
private:
  int m_beginTime=0;
  int m_elapsedTime=0;
  void notify();
  bool timerElapsed();
};




#endif /* INC_TIMER_H_ */
