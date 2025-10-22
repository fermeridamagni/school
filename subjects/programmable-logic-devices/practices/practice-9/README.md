# Practice 9 - Traffic Light Controller

## Overview

This practice simulates a traffic light control system using two sets of traffic lights. The system coordinates the lights to alternate between two directions, implementing realistic traffic light sequences including yellow (caution) transitions.

## Objectives

- Implement state machine logic for traffic control
- Learn to use enums for state management
- Control multiple synchronized outputs
- Practice timing and sequencing in embedded systems

## Hardware Components

- Arduino board
- First traffic light set:
  - Red LED on pin 2
  - Yellow LED on pin 3
  - Green LED on pin 4
- Second traffic light set:
  - Red LED on pin 5
  - Yellow LED on pin 6
  - Green LED on pin 7
- Current-limiting resistors for all LEDs
- Breadboard and jumper wires

## Functionality

The system cycles through four states:

### State 1: FIRST (1 second)
- First light: GREEN
- Second light: RED

### State 2: CHANGING_FIRST (1 second)
- First light: YELLOW (transition)
- Second light: RED

### State 3: SECOND (1 second)
- First light: RED
- Second light: GREEN

### State 4: CHANGING_SECOND (1 second)
- First light: RED
- Second light: YELLOW (transition)

Then the cycle repeats from State 1.

## Key Features

- **State Machine Implementation**: Uses enum for clear state definitions
- **Synchronized Control**: Two traffic lights operate in coordination
- **Realistic Transitions**: Includes yellow caution lights between changes
- **Array-Based LED Management**: Efficient handling of multiple LEDs
- **Continuous Operation**: Runs indefinitely with proper timing

## Usage

1. Upload the sketch to your Arduino board
2. Open Serial Monitor at 9600 baud (optional)
3. Observe the traffic light sequence
4. Note the coordinated operation ensuring only one direction has green at a time

## Circuit Connections

| Component               | Arduino Pin |
|------------------------|-------------|
| First Light - Red      | 2           |
| First Light - Yellow   | 3           |
| First Light - Green    | 4           |
| Second Light - Red     | 5           |
| Second Light - Yellow  | 6           |
| Second Light - Green   | 7           |

**Note**: Use appropriate current-limiting resistors (typically 220Ω-330Ω) for each LED.

## Teaching Concepts

- **State Machine Design**: Using enums and switch statements
- **Synchronization**: Coordinating multiple outputs
- **Array Usage**: Organizing related pins in arrays
- **Safety Logic**: Ensuring safe traffic light operation
- **Timing Control**: Managing state transitions with delays

## Real-World Application

This project simulates real traffic light controllers, which are essential for:
- Urban traffic management
- Intersection safety
- Pedestrian crossing control
- Emergency vehicle priority systems
