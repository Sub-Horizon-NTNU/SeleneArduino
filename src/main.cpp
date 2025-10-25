#include <Arduino.h>
#include "BallastPump.h"

int main() {
    init();
    Serial.begin(9600);
    delay(5000);

    // If your driver inverts the signal, set second arg to true
    BallastPump pump(2);
    pump.begin();

    while(1) {
        Serial.println("pump START");
        pump.start();
        delay(5000);
        Serial.println("pump STOP");
        pump.stop();
        delay(5000);
    }
    return 0;
}
