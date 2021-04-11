#include "Arduino.h"
#include "L298N.h"

L298N::L298N(byte enable, byte forward, byte backward){
  enablePin = enable;
  forwardPin = forward;
  backwardPin = backward;
}

void L298N::attachMotor(){
  pinMode(enablePin, OUTPUT);
  pinMode(forwardPin, OUTPUT);
  pinMode(backwardPin, OUTPUT);
}

void L298N::stopMotor(){
  digitalWrite(enable, LOW);
  digitalWrite(forwardPin, LOW);
  digitalWrite(backwardPin, LOW);
}

void defineSpeed(byte velocity){
  motorSpeed = velocity;
}

byte getSpeed(){
  return motorSpeed;
}

bool getDirection(){
  return motorDirection;
}

void L298N::setVelocity(String directionType, byte velocity, String velocityUnits){
  directionType.trim();
  directionType.toUpperCase();
  if(directionType == "FWD" || directionType == "FORWARD"){
    digitalWrite(enable, LOW);
    digitalWrite(forwardPin, HIGH);
    digitalWrite(backwardPin, LOW);
    motorDirection = true;
  } else if(directionType == "REV" || directionType == "REVERSE"){
    digitalWrite(enable, LOW);
    digitalWrite(forwardPin, LOW);
    digitalWrite(backwardPin, HIGH);
    motorDirection = false;
  }
  
  velocityUnits.trim();
  velocityUnits.toUpperCase();
  if(velocityUnits == "PCT" ||velocityUnits == "percentage")
    motorSpeed = map(velocity, 0, 255, 0, 100);
  else if(velocityUnits == "PWM" || velocityUnits  == "ANALOG")
    motorSpeed = velocity;
}

void L298N::spin(){
  analogWrite(enable, motorSpeed);
}

void L298N::spin(String directionType, byte velocity, String velocityUnits){
  velocityUnits.trim();
  velocityUnits.toUpperCase();
  if(velocityUnits == "PCT" ||velocityUnits == "percentage")
    motorSpeed = map(velocity, 0, 100, 0, 255);
  else if(velocityUnits == "PWM" || velocityUnits  == "ANALOG")
    motorSpeed = velocity;
  
  directionType.trim();
  directionType.toUpperCase();
  if(directionType == "FWD" || directionType == "FORWARD"){
    analogWrite(enable, motorSpeed);
    digitalWrite(forwardPin, HIGH);
    digitalWrite(backwardPin, LOW);
    motorDirection = true;
  } else if(directionType == "REV" || directionType == "REVERSE"){
    analogWrite(enable, motorSpeed);
    digitalWrite(forwardPin, LOW);
    digitalWrite(backwardPin, HIGH);
    motorDirection = False;
  }
}
void L298N::rotateFor(unsigned int delayTime, String directionType, byte velocity, String velocityUnits){
  spin(directionType, velocity, velocityUnits);
  delay(delayTime);
  stopMotor();
}

void L298N::spinForward(){
  analogWrite(enable, motorSpeed);
  digitalWrite(forwardPin, HIGH);
  digitalWrite(backwardPin, LOW);
  motorDirection = true;
}

void L298N::spinForward(byte velocity, String velocityUnits){
  velocityUnits.trim();
  velocityUnits.toUpperCase();
  if(velocityUnits == "PCT" ||velocityUnits == "percentage")
    motorSpeed = map(velocity, 0, 100, 0, 255);
  else if(velocityUnits == "PWM" || velocityUnits  == "ANALOG")
    motorSpeed = velocity;

  spinForward();
}


void L298N::spinBackward(){
  analogWrite(enable, motorSpeed);
  digitalWrite(forwardPin, LOW);
  digitalWrite(backwardPin, HIGH);
  motorDirection = false;
}

void L298N::spinBackward(byte velocity, String velocityUnits){
  velocityUnits.trim();
  velocityUnits.toUpperCase();
  if(velocityUnits == "PCT" ||velocityUnits == "percentage")
    motorSpeed = map(velocity, 0, 100, 0, 255);
  else if(velocityUnits == "PWM" || velocityUnits  == "ANALOG")
    motorSpeed = velocity;

  spinBackward();
}
