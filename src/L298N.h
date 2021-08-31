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
    L298N(byte enable, byte forward, byte backward);

    void setEnablePin(byte enable);
    byte getEnablePin();

    void setForwardPin(byte forward);
    byte getForwardPin();

    void setBackwardPin(byte backward);
    byte getBackwardPin();

    void setSpeed(byte speed, String units);
    byte getSpeed();

    void setDirection(String direction);
    String getDirection();

    void stop();

    void spin();
    void spin(String direction);
    void spin(String direction, byte speed, String units);

    void rotateFor(unsigned int time);
    void rotateFor(unsigned int time, String direction);
    void rotateFor(unsigned int time, String direction, byte speed, String units);

};

#endif