#pragma once
#include <cstdint>

namespace msg {
    struct imu { 
        float ax, ay, az;
        float gx, gy, gz; 
        uint32_t ms; 
    };

    struct cmd { 
        enum Type{ NOP, ARM, TX_ON, TX_OFF } type; 
        int32_t arg; 
        uint32_t ms; };
}

//   struct mag { float mx, my, mz; uint32_t ms; };
//   struct gnss{ double lat, lon; float alt; uint8_t sats; bool fix; uint32_t ms; };
//   struct est { float roll, pitch, yaw, climb, baro_alt; uint32_t ms; };