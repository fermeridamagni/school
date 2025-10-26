# Practice 5 - Intelligent Security System (ESP32)

## Overview

This practice implements an intelligent security system using an ESP32 microcontroller. The system monitors a door sensor (reed switch) and a sound sensor to detect potential security breaches, triggering a pre-alarm sequence followed by a full alarm if not deactivated.

## Objectives

- Learn to interface with reed switches and sound sensors
- Implement state machine logic for alarm systems
- Use timing functions for pre-alarm and alarm states
- Control multiple outputs (LEDs, buzzer, relay)
- Practice ESP32 programming

## Hardware Components

- ESP32 development board
- Reed switch (magnetic door sensor) on pin 34
- Sound sensor on pin 35 (ADC1_CH6)
- Buzzer (active or PWM capable) on pin 23
- Relay on pin 27
- LED 1 on pin 19
- LED 2 on pin 5
- LED 3 on pin 17
- Breadboard and jumper wires

## Functionality

The system operates in two states:

### Normal State
- Monitors door sensor and sound sensor
- When triggered by door opening or loud sound:
  - Enters pre-alarm state
  - Starts 20-second countdown

### Pre-alarm State (20 seconds)
- Displays LED sequence animation
- Checks if door is closed (reed switch deactivated)
- If door closes: cancels alarm, returns to normal state
- If 20 seconds elapse without deactivation:
  - Activates full alarm
  - Turns on buzzer
  - Activates relay (can control external devices)

## Key Features

- **Dual Trigger Detection**: Reed switch and sound sensor
- **Pre-alarm Grace Period**: 20 seconds to deactivate before full alarm
- **Visual Feedback**: Sequential LED animation during pre-alarm
- **Audio Alert**: Buzzer activation in full alarm state
- **Relay Control**: Can trigger external security devices
- **Adjustable Threshold**: Sound sensitivity can be tuned

## Usage

1. Upload the sketch to your ESP32 board
2. Open Serial Monitor at 115200 baud
3. Test by opening the door (activating reed switch)
4. Observe LED sequence during pre-alarm
5. Close door within 20 seconds to cancel, or wait for full alarm
6. Test sound trigger by making loud noise near sensor

## Circuit Connections

| Component     | ESP32 Pin |
|--------------|-----------|
| Reed Switch  | 34        |
| Sound Sensor | 35        |
| Buzzer       | 23        |
| Relay        | 27        |
| LED 1        | 19        |
| LED 2        | 5         |
| LED 3        | 17        |

## Configuration

Adjust the sound detection threshold by modifying the value in the code:

```cpp
return (soundLevel > 2000); // Adjust threshold as needed
```

## Teaching Concepts

- State machine implementation
- Timing and delays in embedded systems
- Digital and analog sensor reading
- Pull-up resistor configuration
- Relay control for external devices
