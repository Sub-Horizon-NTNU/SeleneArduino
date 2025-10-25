#include <Arduino.h>
#include "BallastValve.h"

int main() {
    init();

    BallastValve valve(4, 0, 90);
    valve.begin();

    while (1) {
        valve.open();
        delay(1000);
        valve.close();
        delay(1000);
    }
    return 0;
}
