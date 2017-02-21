# FreeRTOS-ATMega328P
Port of FreeRTOS to the Atmel ATMega328P

## Directory Structure
Atmel Studio 7.0 Solution 'BlinkDemo'
- BlinkDemo Project
- FreeRTOS Library Project

## Tested
- Preemptive Task Scheduling
- vTaskDelayUntil

## Untested
- Queues
- Semaphores
- Software timers
- Coroutines

## Demo
A demo project is included which toggles PB4 and PB5 at 1 and 2 Hz respectively. On an Arduino (Duemilanove, Uno, etc.) This corresponds to pins 12 and 13.

### Programming
The release configuration for the project is configured with a post-build event to program an Arduino on port COM3 with avrdude.
