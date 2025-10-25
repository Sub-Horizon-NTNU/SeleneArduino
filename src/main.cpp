#include <Arduino.h>
#include "Thruster.h"

int main() {
    init();
    Thruster thruster(2);
    thruster.begin();
    
    while(1) {
        thruster.set_power(10);
        delay(1000);
        thruster.stop();
        delay(5000);
        thruster.set_power(-10);
        delay(1000);
        thruster.stop();
        delay(5000);
    }
    return 0;
}
