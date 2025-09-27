#pragma once
#include "os/rtos.hpp"
#include "msg/messages.hpp"

extern Rtos::Queue<msg::imu, 10> ImuQueue;
extern Rtos::Queue<msg::cmd, 10> CmdQueue;