/*
Author: Divyank Shah
Date: 30 August 2021
Library Source: https://github.com/shahdivyank/Arduino_L298N_Library

The following program is to get familiar with the library and move a single motor forward and backward using different units (PWM signals and percentage).
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
    //Spin motor forward using PWM signal
    //Capitalization does not matter. FORWARD & forward and PWM & pwm are the same.
    motor.spin("forward", 255, "PWM");
    Serial.println("Spinning Forward...");

    //Wait 5 seconds (5000ms -> 5s)
    delay(5000);

    //Spin motor backwards using PWM signal
    //Capitalization does not matter. REVERSE & reverse are the same.
    motor.spin("reverse", 255, "pwm");
    Serial.println("Spinning Backwards...");


    delay(5000);

    //Spin motor forward using percentage 
    //Capitalization does not matter. FWD & fwd and PCT & pct are the same.
    motor.spin("fwd", 100, "PCT");
    Serial.println("Spinning Forward...");


    delay(5000);

    //Spin motor backwards using percentage
    //Capitalization does not matter. REV & rev are the same.
    motor.spin("rev", 100, "pct");
    Serial.println("Spinning Backwards...");

    delay(5000);
}