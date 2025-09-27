#include "queues/queues.hpp"

Rtos::Queue<msg::imu, 10> ImuQueue;
Rtos::Queue<msg::cmd, 10> CmdQueue;