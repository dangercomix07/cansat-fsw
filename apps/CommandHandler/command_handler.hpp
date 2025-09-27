#pragma once
#include <cstdint>

class CommandHandler {
    public:
        static void Run(void* args); //Rtos task entry point
};