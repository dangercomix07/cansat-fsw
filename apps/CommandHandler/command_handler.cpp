#include "apps/CommandHandler/command_handler.hpp"
#include "queues/queues.hpp"
#include "os/rtos.hpp"

#include <iostream>

static bool g_armed = false;
static bool g_tx_on = false;

void CommandHandler::Run(void*) {
    std::cout << "CommandHandler ready (NOP | ARM | TX_ON | TX_OFF)\n";
    msg::cmd c{};

    while(true) {
        
        // Wait forever for a command
        if (!CmdQueue.receive(c, Rtos::MAX_TIMEOUT)) continue;

        switch (c.type) {
            case msg::cmd::NOP:
                std::cout << "CMD: NOP\n";
                break;

            case msg::cmd::ARM:
                g_armed = true;
                std::cout << "CMD: ARM -> armed=1\n";
                break;

            case msg::cmd::TX_ON:
                if (g_armed) {
                    g_tx_on = true;
                    std::cout << "CMD: TX_ON -> tx=1\n";
                } else {
                    std::cout << "WARN: TX_ON ignored (not armed)\n";
                }
                break;

            case msg::cmd::TX_OFF:
                g_tx_on = false;
                std::cout << "CMD: TX_OFF -> tx=0\n";
                break;
        }
        
        Rtos::SleepMs(1);
    }
}