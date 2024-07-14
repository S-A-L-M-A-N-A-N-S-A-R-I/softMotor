#include "softMotor.h"

softMotor::softMotor(int pinNum, byte speedMax, byte offspeed, int speedIncrement)
{
    pin = pinNum;
    pinMode(pin, OUTPUT);
    analogWrite(pin, 0);
    timeToIncrement = 0;
    incrementSpeed = speedIncrement;
    currentSpeed = 0;
    motorState = LOW;
    maxSpeed = speedMax;
    offSpeed = offspeed;
}

void softMotor::alive()
{
    if (timeToIncrement >= incrementSpeed)
    {
        timeToIncrement = 0;

        if (motorState == HIGH && currentSpeed < maxSpeed)
        {
            currentSpeed = (currentSpeed + 1);
            analogWrite(pin, currentSpeed);
        }
        if (motorState == LOW && currentSpeed > offSpeed)
        {
            currentSpeed = (currentSpeed - 1);
            analogWrite(pin, currentSpeed);
        }
    }
}

void softMotor::on()
{
    motorState = HIGH;
}

void softMotor::on(int startFrom)
{
    currentSpeed = startFrom;
    analogWrite(pin, currentSpeed);
    motorState = HIGH;
}

void softMotor::off()
{
    motorState = LOW;
}

void softMotor::quickOff()
{
    motorState = LOW;
    currentSpeed = offSpeed;
    analogWrite(pin, currentSpeed);
}

void softMotor::fullShut()
{
    motorState = LOW;
    currentSpeed = 0;
    analogWrite(pin, 0);
}

void softMotor::setOffSpeed(byte s)
{
    offSpeed = s;
}

void softMotor::setMaxSpeed(byte s)
{
    maxSpeed = s;
}

void softMotor::setCurrentSpeed(byte s)
{
    currentSpeed = s;
    analogWrite(pin, s);
}

byte softMotor::currentspeed(void)
{
    return (currentSpeed);
}
