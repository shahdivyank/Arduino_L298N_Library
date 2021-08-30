#ifndef L298N_h
#define L298N_h

#include "Arduino.h"

class L298N {
   private:
     byte _enable;
     byte _forward;
     byte _backward;
     byte _speed;
     bool _direction;
     bool _isMoving;

   public:
     L298N();
     L298N(byte enable, byte forward, byte backward);

     void setEnable(byte enable);
     byte getEnable();

     void setForward(byte forward);
     byte getForward();

     void setBackward(byte backward);
     byte getBackward();

     void setSpeed(byte speed, String units);
     byte getSpeed();

     void setDirection(String direction);
     string getDirection();

     void stop();

     void spin();
     void spin(String direction);
     void spin(String direction, byte speed, String units);

     void rotateFor(unsigned int time);
     void rotateFor(unsigned int time, String direction);
     void rotateFor(unsigned int time, String direction, byte speed, String units);

};

#endif
