#include "timer.h"
#include <unistd.h>
#include <time.h>







timer::timer(notificationIf* a_pParent, int a_type, int timeout){
  m_parents.push_back(a_pParent);
  m_type = a_type;
  m_timeout = timeout;
  m_run = false;
}

void timer::addParent(notificationIf* a_pParent){
  m_parents.push_back(a_pParent);
}

void timer::run(){
  m_run=true;
//  m_beginTime=clock();
//  while(m_run){
//    if(timerElapsed())
//    {
//      notify();
//      m_elapsedTime = 0;
//      m_beginTime=clock();
//    }
//  }
}

void timer::stop(){
  m_run = false;

}

bool timer::timerElapsed(){
  m_elapsedTime = (clock()-m_beginTime)/CLOCKS_PER_SEC;
  if (m_elapsedTime > m_timeout)
  {
    return true;
  }
  return false;
}

void timer::notify() {

  list<notificationIf*>::iterator iter;
  for (iter = m_parents.begin(); iter != m_parents.end(); iter++)
  {
     (*iter)->handleNotification(m_type);
  }
}
