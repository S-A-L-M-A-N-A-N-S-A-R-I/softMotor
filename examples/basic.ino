#include <softMotor.h>
#include <elapsedMillis.h>

// Define your pins and settings
const int motorPin = 9; //Must be PWM pin
const byte maxSpeed = 255;
const byte offSpeed = 0;
const int acceleration = 10;

// Create an instance of softMotor
softMotor pumpMotor(motorPin, maxSpeed, offSpeed, acceleration);

void setup() {
    pumpMotor.on(); // Start the motor
}

void loop() {
    // Update motor state
    pumpMotor.alive();
    
    // Example: Turn motor on and off every 5 seconds
    static elapsedMillis timer;
    if (timer > 5000) {
        if (pumpMotor.currentspeed() > 0) {
            pumpMotor.off();
        } else {
            pumpMotor.on();
        }
        timer = 0;
    }
}
