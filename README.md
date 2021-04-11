# Arduino L298N Library
<img src = "https://user-images.githubusercontent.com/36285610/114322331-7749c680-9ad4-11eb-8f53-99ef95148401.jpg" width = "250px">

Note: Image is from [Smart Prototyping](https://www.smart-prototyping.com/image/cache/data/9_Modules/101861%20LN298N%20dual%20H-bridge%20driver%20motor/1-750x750.jpg).
A beginner friendly and acessible library to use with the L298N motor drivers alongside Arduino. 

# Library Installation

To install, download as a .zip file and proceed to the Arduino IDE. On the IDE, head to Sketch -> Include Library -> Include ZIP Library. Finder/File Explorer will open and you have to select the .zip file recently downloaded. 

# Library Import
Method 1: Sketch -> Include Library -> L298N <br>Method 2: Write `#include "L298N.h"` at the top of your sketch

# Object Instantiation 
Write the following code to create an object of the class to use:
```
C++
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

| Function  | Parameters | Returns |  Description |
| ------------- | ------------- | ------------- | ------------- |
| attachMotor()  | void  |  void | setups the pin congfiguration as OUTPUT |
| stopMotor()  | void  | void  | stops the motor |
| defineSpeed()  | byte velocity, String velocityUnits  | void  | set the motor speed |
| getSpeed()  | void  | byte velocity  | retrieve the current motor speed |
| getDirection()  | void  | bool direction  | retrieve the current motor direction |
| setVelocity()  | String directionType, byte velocity, String velocityUnits  | void  | set the motor speed to either a value from 0 to 255 (PWM) or 0 to 100 (PCT)| | spin()  | void  | void  | spin the motor |
| spin()  | String directionType, byte velocity, String velocityUnits  | void  | spin the motor with a specified direction and speed in percentage or PWM |
| rotateFor()  | unsigned int delayTime, String directionType, byte velocity, String velocityUnits  | void  | spin the motor with a specified direction and speed in percentage or PWM for a set amount of time using delay |
| spinForward()  | void  | void  | spin in the forward direction |
| spinForward()  | byte velocity, String velocityUnits  | void  | spin in the forward direction at a given speed in PWM or percentage |
| spinBackward()  | void  | void  | spin in the backward direction |
| spinBackward()  | byte velocity, String velocityUnits  | void  | spin in the forward direction at a given speed in PWM or percentage |
