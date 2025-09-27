#include "apps/StateMachine/state_machine.hpp"
#include "apps/CommandHandler/command_handler.hpp"
#include "apps/TelemetryManager/telemetry_manager.hpp"
#include "apps/Estimator/estimator.hpp"
#include <iostream>
#include "os/rtos.hpp"
#include "queues/queues.hpp"

// Demo producer task
void ProducerDemo_Run(void*) {
    msg::cmd c{};
    c.type = msg::cmd::TX_ON; CmdQueue.send(c,100); Rtos::SleepMs(200);
    c.type = msg::cmd::ARM;   CmdQueue.send(c,100); Rtos::SleepMs(200);
    c.type = msg::cmd::TX_ON; CmdQueue.send(c,100); Rtos::SleepMs(200);
    c.type = msg::cmd::TX_OFF;CmdQueue.send(c,100);
}
Rtos::Task ProducerTask;

// Rtos::Task StateMachineTask;
Rtos::Task CommandHandlerTask;
// Rtos::Task TelemetryManagerTask;
// Rtos::Task EstimatorTask;

int main(){
    // Create tasks
    // StateMachineTask.Create("StateMachine", StateMachine::Run, nullptr);
    CommandHandlerTask.Create("CommandHandler", CommandHandler::Run, nullptr);
    // TelemetryManagerTask.Create("TelemetryManager", TelemetryManager::Run, nullptr);
    // EstimatorTask.Create("Estimator", Estimator::Run, nullptr);

    ProducerTask.Create("ProducerDemo", ProducerDemo_Run, nullptr);
    
    Rtos::SleepMs(1000);
    std::cout<<"HELLO WORLD"<<std::endl;
    return 0;
}