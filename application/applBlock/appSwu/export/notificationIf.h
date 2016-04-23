
#ifndef INC_NOTIFICATION_IF_H_
#define INC_NOTIFICATION_IF_H_
#include <string>
#include "defines.h"
using namespace std;



class notificationIf{
public:
  virtual ~notificationIf(){};
  virtual void handleNotification(int a_type) = 0;
};



#endif /* INC_NOTIFICATION_IF_H_ */
