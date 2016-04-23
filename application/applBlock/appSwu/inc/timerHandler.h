#include <list>
#include "timer.h"
#include "defines.h"

using namespace std;

class timerHandler {
public:
   static timerHandler* GetInstance();
private:
   timerHandler();
   static timerHandler* pTimerHandler;    // singleton instance
  list<timer*> m_timers;

public:
  static timerHandler& getInstance();
  void createTimer(notificationIf* a_pParent, int a_type, int a_timeout);
  void deleteTimer(notificationIf* a_pParent, int a_type);
  void timerFunc();
};


