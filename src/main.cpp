#include <Arduino.h>
#include "ThrusterServo.h"

int main() {
    init();
    
    ThrusterServo azimuth(3);
    azimuth.begin();
    
    while(1) {
        azimuth.set_angle(0);      // Turn full left
        delay(2000);
        
        azimuth.set_angle(360);    // Turn full right
        delay(2000);
        
        azimuth.center();          // Return to center
        delay(2000);
      
    }
    return 0;
}
