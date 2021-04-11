 #include "Arduino.h"
 #ifndef L298N_h
 #define L298N_h

 class L298N {
    private:
      byte enablePin;
      byte forwardPin;
      byte backwardPin;
      byte motorSpeed;
      bool motorDirection;
      
    public:
      L298N(byte enable, byte forward, byte backward);
      void attachMotor();
      void stopMotor();
      void defineSpeed(byte velocity);
      void getSpeed();
      void getDirection();
      void setVelocity(String directionType, byte velocity, String velocityUnits);
      void spin();
      void spin(String directionType, byte velocity, String velocityUnits);
      void rotateFor(unsigned int delayTime, String directionType, byte velocity, String velocityUnits);
      void spinForward();
      void spinForward(byte velocity, String velocityUnits);
      void spinBackward();
      void spinBackward(byte velocity, String velocityUnits);
      
 };

 #endif
