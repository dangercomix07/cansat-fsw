# cansat-fsw

```bash
\apps
    \CommandHandler: Responsible for parsing command from RX and routing it's implementation
    # More applications will be added here
\queues: Define all queues here
\msg: Define all message structs here

\os
    rtos.hpp: RTOS wrapper (Reference for all RTOS functions)
    \linux
        posix_rtos.cpp: POSIX implementation of RTOS wrapper
    \stm32
        freertos_rtos.cpp: FreeRTOS implementation of RTOS wrapper
\cmake
    linux_toolchain.cmake
\test: test functions for unit testing
```

