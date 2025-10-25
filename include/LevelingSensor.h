#ifndef LEVELING_SENSOR_H
#define LEVELING_SENSOR_H

#include <Arduino.h>

class LevelingSensor {
public:
    static const int error_distance = -1;

    LevelingSensor(HardwareSerial& serial, Stream* debug = nullptr)
        : serial_(serial), debug_(debug), last_distance_(error_distance),
          buffer_idx_(0) {}

    void begin(unsigned long baud = 9600) {
        serial_.begin(baud);
    }

    // Call frequently in loop() to update buffer
    void update() {
        while (serial_.available()) {
            uint8_t byte = serial_.read();

            // Detect packet header
            if (buffer_idx_ == 0 && byte != header_byte) {
                continue; // skip until we find header
            }

            buffer_[buffer_idx_++] = byte;

            // If buffer full (4 bytes), validate packet
            if (buffer_idx_ == 4) {
                uint8_t checksum = buffer_[0] + buffer_[1] + buffer_[2];
                if (checksum == buffer_[3]) {
                    uint16_t distance = (uint16_t)((buffer_[1] << 8) | buffer_[2]);
                    last_distance_ = distance;
                } else if (debug_) {
                    debug_->println("LevelingSensor: checksum error");
                }
                buffer_idx_ = 0; // reset for next packet
            }
        }
    }

    // Return the last valid distance instantly
    int get_distance() const {
        return last_distance_;
    }

private:
    HardwareSerial& serial_;
    Stream* debug_ = nullptr;

    uint8_t buffer_[4];
    uint8_t buffer_idx_;
    int last_distance_;

    static const uint8_t header_byte = 0xFF;
};

#endif
