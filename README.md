# Autonomous-Sumo-Robot--ESP32-
Autonomous sumo-fighting robot built on ESP32, using dual-core FreeRTOS tasks  for real-time sensor fusion and decision-making.

## Features
- **State machine AI**: SEARCH → ATTACK → LOST_CONTACT → AVOID_EDGE
- **8× IR edge sensors** with EMA (exponential moving average) filtering to avoid false positives
- **VL53L0X ToF sensor** for opponent detection
- **Dual-core task architecture**: sensor polling and control logic run on separate ESP32 cores for responsiveness
- Custom motor driver class supporting forward/backward/turn/spin maneuvers

## Hardware
- ESP32 dev board
- 2× DC motors + driver (2-pin PWM control per motor)
- 8× IR reflectance sensors (edge/line detection)
- 1× VL53L0X Time-of-Flight distance sensor

## Architecture

| Module            | Responsibility                          |
|--------------------|------------------------------------------|
| `MotorSumo`         | Low-level motor control (speed, direction) |
| `IrSumo`            | Edge detection via 8 IR sensors + EMA filtering |
| `ProximitySensor`   | Opponent detection via ToF sensor        |
| `SumoAI`            | State machine + FreeRTOS task orchestration |

## How it works
Two FreeRTOS tasks run in parallel:
- **TaskSensors** (core 0): continuously polls IR and proximity sensors
- **TaskControl** (core 1): runs the decision state machine every 20ms

## Status
Prototype (disassembled after the competition — parts reused for other projects)

## Possible improvements
- PID-based motion control
- Sensor calibration routine
- Wireless telemetry for debugging
