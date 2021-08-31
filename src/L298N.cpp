#include "Arduino.h"
#include "L298N.h"

L298N::L298N(byte enable, byte forward, byte backward) {
    _enable = enable;
    _forward = forward;
    _backward = backward;

    pinMode(_enable, OUTPUT);
    pinMode(_forward, OUTPUT);
    pinMode(_backward, OUTPUT);
}

void L298N::setEnablePin(byte enable){
    _enable = enable;
    pinMode(_enable, OUTPUT);
}

byte L298N::getEnablePin(){
    return _enable;
}

void L298N::setForwardPin(byte forward){
    _forward = forward;
    pinMode(_forward, OUTPUT);
}

byte L298N::getForwardPin(){
    return _forward;
}

void L298N::setBackwardPin(byte backward){
    _backward = backward;
    pinMode(_backward, OUTPUT);
}

byte L298N::getBackwardPin(){
    return _backward;
}

void L298N::setSpeed(byte speed, String units){
    String parsedUnits = units.trim().toUpperCase();
    if(parsedUnits == "PCT" || parsedUnits == "PERCENTAGE")
        _speed = map(speed, 0, 255, 0, 100);
    if(parsedUnits == "PWM")
        _speed = units;
}

byte L298N::getSpeed(){
    return _speed;
}

void L298N::setDirection(String direction){
    String parsedDirection = direction.trim().toUpperCase();
    if(parsedDirection == "FWD" || parsedDirection == "FORWARD")
        _direction = true;
    if(parsedDirection == "REV" || parsedDirection == "BACKWARD")
        _direction = false;

    if (_direction){
        digitalWrite(_forward, HIGH);
        digitalWrite(_backward, LOW);
    }
    if(!_direction){
        digitalWrite(_forward, LOW);
        digitalWrite(_backward, HIGH);
    }
}

String L298N::getDirection(){
    if(_direction)
        return "Forward";
    if(!_direction)
        return "Backward";
}

void L298N::stop(){
    analogWrite(_enable, 0);
}

void L298N::spin(){
    analogWrite(_enable, _speed);
}

void L298N::spin(String direction){
    String parsedDirection = direction.trim().toUpperCase();
    if(parsedDirection == "FWD" || parsedDirection == "FORWARD")
        _direction = true;
    if(parsedDirection == "REV" || parsedDirection == "BACKWARD")
        _direction = false;

    if (_direction){
        analogWrite(_enable, _speed);
        digitalWrite(_forward, HIGH);
        digitalWrite(_backward, LOW);
    }
    if(!_direction){
        analogWrite(_enable, _speed);
        digitalWrite(_forward, LOW);
        digitalWrite(_backward, HIGH);
    }
}

void L298N::spin(String diretion, byte speed, String units){
    String parsedDirection = direction.trim().toUpperCase();
    if(parsedDirection == "FWD" || parsedDirection == "FORWARD")
        _direction = true;
    if(parsedDirection == "REV" || parsedDirection == "BACKWARD")
        _direction = false;

    String parsedUnits = units.trim().toUpperCase();
    if(parsedUnits == "PCT" || parsedUnits == "PERCENTAGE")
        _speed = map(speed, 0, 255, 0, 100);
    if(parsedUnits == "PWM")
        _speed = units;

    if (_direction){
        analogWrite(_enable, _speed);
        digitalWrite(_forward, HIGH);
        digitalWrite(_backward, LOW);
    }
    if(!_direction){
        analogWrite(_enable, _speed);
        digitalWrite(_forward, LOW);
        digitalWrite(_backward, HIGH);
    }
}

void L298N::rotateFor(unsigned int time){
    analogWrite(_enable, _speed);
    delay(time);
    stop();
}

void L298N::rotateFor(unsigned int time, String direction){
    String parsedDirection = direction.trim().toUpperCase();
    if(parsedDirection == "FWD" || parsedDirection == "FORWARD")
        _direction = true;
    if(parsedDirection == "REV" || parsedDirection == "BACKWARD")
        _direction = false;

    if (_direction){
        analogWrite(_enable, _speed);
        digitalWrite(_forward, HIGH);
        digitalWrite(_backward, LOW);
    }
    if(!_direction){
        analogWrite(_enable, _speed);
        digitalWrite(_forward, LOW);
        digitalWrite(_backward, HIGH);
    }

    delay(time);
    stop();
}

void L298N::rotateFor(unsigned int time, String direction, byte speed, String units){
    String parsedDirection = direction.trim().toUpperCase();
    if(parsedDirection == "FWD" || parsedDirection == "FORWARD")
        _direction = true;
    if(parsedDirection == "REV" || parsedDirection == "BACKWARD")
        _direction = false;

    String parsedUnits = units.trim().toUpperCase();
    if(parsedUnits == "PCT" || parsedUnits == "PERCENTAGE")
        _speed = map(speed, 0, 255, 0, 100);
    if(parsedUnits == "PWM")
        _speed = units;

    if (_direction){
        analogWrite(_enable, _speed);
        digitalWrite(_forward, HIGH);
        digitalWrite(_backward, LOW);
    }
    if(!_direction){
        analogWrite(_enable, _speed);
        digitalWrite(_forward, LOW);
        digitalWrite(_backward, HIGH);
    }

    delay(time);
    stop();
}