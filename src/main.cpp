#include <Arduino.h>
#include "LevelingSensor.h"

int main() {
    init();
    Serial.begin(9600);
    while (!Serial);

    LevelingSensor sensor(Serial3, &Serial);
    sensor.begin(9600);

    Serial.println("LevelingSensor hardware serial test starting...");

    while (1) {
        int distance = sensor.get_distance();
        if (distance != LevelingSensor::error_distance) {
            Serial.print("Distance: ");
            Serial.print(distance);
            Serial.println(" mm");
        } else {
            Serial.println("Sensor read error");
        }

        delay(100);
    }

    return 0;
}