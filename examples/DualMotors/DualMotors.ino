/*
Author: Divyank Shah
Date: 30 August 2021
Library Source: https://github.com/shahdivyank/Arduino_L298N_Library

The following program shows an implementation of multiple motors in use. Using 2 motors, users can simultaneously run both motors. Additional motors may be used, but ensure additional L298N motor drivers are plugged in.

Motor A spins forward, while Motor B spins backwards for 3 seconds, after which they switch directions.
*/

//Include Library, refer to README.md for more instructions
#include <L298N.h>

/*
Ensure that enable pin is a PWM (~) capable port
forward and backward may be PWM (~) or digital ports 
*/
const unsigned int enable_A = 9;
const unsigned int forward_A = 10;
const unsigned int backward_A = 11;

const unsigned int enable_B = 5;
const unsigned int forward_B = 6;
const unsigned int backward_B = 7;

//Create 2 motor instances
L298N motor_1(enable_A, forward_A, backward_A);
L298N motor_2(enable_B, forward_B, backward_B);

void setup(){
    //Setup serial monitor for debugging purposes
    Serial.begin(9600);
}

void loop(){
    //Spinning motor_1 forward
    motor_1.spin("FORWARD", 255, "PWM");

    //Spinning motor_2 backward simultaneously
    motor_2.spin("REVERSE", 255, "PWM");

    delay(3000);

    //Reversing motor directions
    motor_1.setDirection("REVERSE");
    motor_2.setDirection("FORWARD");

    delay(3000);
}