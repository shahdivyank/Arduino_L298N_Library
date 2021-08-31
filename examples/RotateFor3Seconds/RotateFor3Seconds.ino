/*
Author: Divyank Shah
Date: 30 August 2021
Library Source: https://github.com/shahdivyank/Arduino_L298N_Library

The following program spins the motor for a set amount of time and stops the motor. delay() statements have been added to show the difference between different implementations of the method. Different implementations allow users to be able to customize what methods to use and when to use them.
*/

//Include Library, refer to README.md for more instructions
#include <L298N.h>

/*
Ensure that enable pin is a PWM (~) capable port
forward and backward may be PWM (~) or digital ports 
*/
const unsigned int enable = 9;
const unsigned int forward = 10;
const unsigned int backward = 11;

//Create motor instance
L298N motor(enable, forward, backward);

void setup(){
    //Setup serial monitor for debugging purposes
    Serial.begin(9600);
}

void loop(){

    //METHOD 1
    //Set the speed and direction
    motor.setSpeed(100, "PCT");
    motor.setDirection("FORWARD");
    //Call rotateFor() and pass in time (in ms). 3000ms -> 3s
    motor.rotateFor(3000);

    delay(1000);

    //METHOD 2
    //Set the speed
    motor.setSpeed(255, "PWM");
    //Call rotateFor() and pass in time and direction
    motor.rotateFor(4000, "FORWARD");

    delay(1000);

    //METHOD 3
    //Call rotateFor() and pass in time, direction, and speed
    motor.rotateFor(5000, "FORWARD", 255, "PWM");

    delay(1000);
}