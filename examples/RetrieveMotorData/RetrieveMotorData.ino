/*
Author: Divyank Shah
Date: 30 August 2021
Library Source: https://github.com/shahdivyank/Arduino_L298N_Library

The following program will spin a motor and print out various data concerning pin locations, current speed, and current direction.
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
    motor.spin("forward", 255, "PWM");
    Serial.println("Spinning Forward......\t");

    //Retrieve the port the Enable is hooked up to and print the data
    byte enablePin =  getEnablePin();
    Serial.print("Enable is hooked up to...\t");
    Serial.println(enablePin);

    //Retrieve the port the Forward is hooked up to and print the data
    byte forwardPin =  getForwardPin();
    Serial.print("Forward is hooked up to...\t");
    Serial.println(forwardPin);

    //Retrieve the port the Backward is hooked up to and print the data
    byte backwardPin =  getBackwardPin();
    Serial.print("Backward is hooked up to...\t");
    Serial.println(backwardPin);

    //Retrieve the current speed and print data
    byte speed =  getSpeed();
    Serial.print("Current speed is...\t");
    Serial.println(speed);
    
    //Retrieve the current direction and print data
    String direction =  getDirection();
    Serial.print("Current direction is...\t");
    Serial.println(direction);

    delay(1000);
}