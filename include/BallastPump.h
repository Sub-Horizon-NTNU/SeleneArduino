#ifndef BALLAST_PUMP_H
#define BALLAST_PUMP_H

#include <Arduino.h>

class BallastPump {
private:
    int pin;
    
public:
    BallastPump(int pin) : pin(pin) {}
    
    void begin() {
        pinMode(pin, OUTPUT);
        stop();
    }
    
    void start() {
        digitalWrite(pin, HIGH);
    }
    
    void stop() {
        digitalWrite(pin, LOW);
    }
};

#endif // BALLAST_PUMP_H