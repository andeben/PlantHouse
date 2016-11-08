#include "../renoveringsobjekt/timerHandler.h"

#include "notificationIf.h"
#include "defines.h"
#include <thread>
#include "unistd.h"
#include <iostream>
timerHandler* timerHandler::pTimerHandler= nullptr;


timerHandler::timerHandler()
{
}

timerHandler* timerHandler::GetInstance()
{
  if (pTimerHandler== nullptr) {
    pTimerHandler = new timerHandler();
  }
  return pTimerHandler;
}

void timerHandler::createTimer(notificationIf* a_pParent, int a_type, int a_timeout)
{
//  timer* Timer = new timer(a_pParent, a_type, a_timeout);
//  m_timers.push_back(Timer);

}

void timerHandler::deleteTimer(notificationIf* a_pParent, int a_type)
{
  //Sök upp timerna i listan med namn som nyckel. kör konstruktorn på timern.
}

void timerHandler::timerFunc()
{
  sleep(10);
}


