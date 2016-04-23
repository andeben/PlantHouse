#ifndef MONITOR_H
#define MONITOR_H
#include "notificationIf.h"
#include<string>

using namespace std;

class Monitor : public notificationIf
{
public:
	Monitor();
  ~Monitor();
  void init();
	void handleNotification(int a_type);
private:
int m_u=0;
};


#endif
