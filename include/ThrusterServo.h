#ifndef THRUSTER_SERVO_H
#define THRUSTER_SERVO_H

#include <Arduino.h>
#include <Servo.h>

class ThrusterServo {
private:
    Servo servo;
    int pin;
    int current_angle;
    
    static const int MIN_PULSE = 500;
    static const int MAX_PULSE = 2500;
    static const int MIN_ANGLE = 0;
    static const int MAX_ANGLE = 360;

public:
    ThrusterServo(int pin) : pin(pin), current_angle(180) {}
    
    void begin() {
        servo.attach(pin, MIN_PULSE, MAX_PULSE);
        set_angle(90);
        delay(1000);
    }
    
    void set_angle(int angle) {
        angle = constrain(angle, MIN_ANGLE, MAX_ANGLE);
        current_angle = angle;
        servo.writeMicroseconds(map(angle, MIN_ANGLE, MAX_ANGLE, MIN_PULSE, MAX_PULSE));
    }
    
    int get_angle() const {
        return current_angle;
    }
    
    void set_microseconds(int us) {
        us = constrain(us, MIN_PULSE, MAX_PULSE);
        current_angle = map(us, MIN_PULSE, MAX_PULSE, MIN_ANGLE, MAX_ANGLE);
        servo.writeMicroseconds(us);
    }
    
    int get_microseconds() const {
        return map(current_angle, MIN_ANGLE, MAX_ANGLE, MIN_PULSE, MAX_PULSE);
    }
    
    void center() {
        set_angle(180);
    }
};

#endif