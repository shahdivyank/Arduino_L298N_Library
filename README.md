# Arduino L298N/L293D Library
A beginner friendly and acessible library to use with the L298N/L293D motor drivers alongside Arduino. 

# Library Installation

To install, download this repository as a .zip file and proceed to the Arduino IDE. On the IDE, head to Sketch -> Include Library -> Include ZIP Library. Finder/File Explorer will open and you have to select the .zip file recently downloaded. 

# Library Import
Method 1: Sketch -> Include Library -> L298N <br>Method 2: Write `#include "L298N.h"` at the top of your sketch

# Object Instantiation 
Write the following code to create an object of the class to use:
```
#include "L298N.h"

L298N motor(enablePinA, forwardPin_1, backwardPin_1);
```
To use two motors, create another object as such:
```
#include "L298N.h"

L298N motor_1(enablePinA, forwardPin_1, backwardPin_1);
L298N motor_2(enablePinB, forwardPin_2, backwardPin_2);
```
Note: `enablePinA/enablePinB` must be PWM (signified by ~) capable ports. `forwardPin_1/forwardPin_2` and `backwardPin_1/backwardPin_2` can be any variant of a digital I/O port.

# Library Functions

Reference the examples folder for complete working examples implementing this library.

| Methods  | Parameters | Returns |  Description |
| ------------- | ------------- | ------------- | ------------- |
| ```setEnablePin()```  | byte enable  |  void | configures enable pin |
| ```getEnablePin()```  | void  | byte enable  | returns enable pin number |
| ```setForwardPin()```  | byte forward  | void | configures forward pin |
| ```getForwardPin()```  | void  | byte forward | returns forward pin number |
| ```setBackwardPin()```  | byte backward  | void | configures backward pin |
| ```getBackwardPin()```  | void  | byte backward  | returns backward pin number| 
| ```setSpeed()```  | byte speed, String units  | void  | set the motor speed as PWM or PCT |
| ```getSpeed()```  | void | byte speed  | return the current speed of motor |
| ```setDirection()```  | String direction  | void  | set direction to FWD or REV |
| ```getDirection()```  | void  | String direction  | return current direction |
| ```stop()```  | void  | void  | stop all motor movement |
| ```spin()```  | void  | void  | spin given prior direction, speed, and units |
| ```spin()```  | String direction  | void  | spin given prior speed, and units |
| ```spin()```  | String direction, byte speed, String units  | void  | spin given direction, speed, and units |
| ```rotateFor()```  | unsigned int time  | void  | spin for given time (in milliseconds) |
| ```rotateFor()```  | unsigned int time, String direction  | void  | spin for given time (in milliseconds) in specified direction |
| ```rotateFor()```  | unsigned int time, String direction, byte speed, String units  | void  | spin for given time (in milliseconds) in given direction at given speed |
