#ifndef SOFT_MOTOR_H
#define SOFT_MOTOR_H

#include <Arduino.h>
#include <elapsedMillis.h>

class softMotor
{
    int incrementSpeed, pin;
    byte currentSpeed, maxSpeed, offSpeed;
    bool motorState;

  public:
    elapsedMillis timeToIncrement;

    softMotor(int pinNum, byte speedMax, byte offspeed, int speedIncrement);
    void alive();
    void on();
    void on(int startFrom);
    void off();
    void quickOff();
    void fullShut();
    void setOffSpeed(byte s);
    void setMaxSpeed(byte s);
    void setCurrentSpeed(byte s);
    byte currentspeed();
};

#endif // SOFT_MOTOR_H
