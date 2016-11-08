#include "../renoveringsobjekt/Monitor.h"

#include "defines.h"
#include <iostream>

#include "../renoveringsobjekt/timerHandler.h"
Monitor::Monitor()
{
}

Monitor::~Monitor()
{
}

void Monitor::init(){
timerHandler::GetInstance()->createTimer(this, TIMERS::TIMER_HEARTBEAT, TIMERS_TIMOUTS::TIMER_HEARTBEAT_TIMEOUT);
cout << "init(): ";
}


void Monitor::handleNotification(int a_type){
  cout << "handleNotification() type: " << a_type;
   if(a_type == TIMER_HEARTBEAT)
   {
     cout << "handleNotification(): Inside " << m_u;
     m_u++;
   }
    }
