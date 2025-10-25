#ifndef BALLAST_VALVE_H
#define BALLAST_VALVE_H

#include <Arduino.h>
#include <Servo.h>

class BallastValve {
private:
    Servo servo_;
    int pin_;
    int closed_angle_;
    int open_angle_;

public:
    BallastValve(int pin, int closed_angle, int open_angle)
        : pin_(pin), closed_angle_(closed_angle), open_angle_(open_angle) {}

    void begin() {
        servo_.attach(pin_);
        close();
        delay(200);
    }

    void open() {
        servo_.write(open_angle_);
    }

    void close() {
        servo_.write(closed_angle_);
    }
};

#endif // BALLAST_VALVE_H
