#ifndef THRUSTER_H
#define THRUSTER_H

#include <Arduino.h>
#include <Servo.h>

class Thruster {
private:
    Servo esc;
    int pin;
    int current_power;
    
    static const int STOP_PULSE = 1500;
    static const int MAX_FORWARD = 1900;
    static const int MAX_REVERSE = 1100;

public:
    Thruster(int pin) : pin(pin), current_power(0) {}
    
    void begin() {
        esc.attach(pin);
        stop();
        delay(5000);
    }
    
    void set_power(int power) {
        power = constrain(power, -100, 100);
        current_power = power;
        
        int pwm = power_to_pwm(power);
        esc.writeMicroseconds(pwm);
    }
    
    int get_current_power() const {
        return current_power;
    }
    
    void stop() {
        current_power = 0;
        esc.writeMicroseconds(STOP_PULSE);
    }
    
    int power_to_pwm(int power) const {
        if (power == 0) {
            return STOP_PULSE;
        } else if (power > 0) {
            return map(power, 0, 100, STOP_PULSE, MAX_FORWARD);
        } else {
            return map(power, -100, 0, MAX_REVERSE, STOP_PULSE);
        }
    }
};

#endif