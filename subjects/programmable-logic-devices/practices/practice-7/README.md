# Practice 7 - LED Sequence with Buzzer

## Overview

This practice implements a simple LED sequence controller with audio feedback using a buzzer. It demonstrates basic Arduino programming concepts including digital output control, timing, and tone generation.

## Objectives

- Learn basic digital output control
- Implement sequential LED patterns
- Generate tones using the buzzer
- Practice timing with delay functions

## Hardware Components

- Arduino board
- Blue LED on pin 8
- Green LED on pin 7
- Yellow LED on pin 4
- Buzzer on pin 12
- Current-limiting resistors for LEDs
- Breadboard and jumper wires

## Functionality

The system continuously cycles through the following sequence:

1. **Blue LED**: Turns on for 1 second, then off for 1 second
2. **Green LED**: Turns on for 1 second, then off for 1 second
3. **Yellow LED**: Turns on for 1 second, then off for 1 second
4. **Buzzer**: Generates 1KHz tone for 1 second, then silent for 1 second
5. Repeat sequence

## Key Features

- **Sequential Output**: LEDs light up one at a time in order
- **Consistent Timing**: 1-second intervals for all outputs
- **Tone Generation**: Uses Arduino tone() function for buzzer
- **Simple Loop**: Easy to understand control flow
- **Visual and Audio**: Combines LED and sound feedback

## Usage

1. Upload the sketch to your Arduino board
2. Open Serial Monitor at 115200 baud (optional)
3. Observe the LED sequence: blue → green → yellow
4. Listen for the 1KHz tone after the yellow LED
5. Sequence repeats continuously

## Circuit Connections

| Component   | Arduino Pin |
|------------|-------------|
| Blue LED   | 8           |
| Green LED  | 7           |
| Yellow LED | 4           |
| Buzzer     | 12          |

**Note**: Remember to use appropriate current-limiting resistors (typically 220Ω-330Ω) for each LED.

## Teaching Concepts

- Digital I/O basics
- Sequential control
- Delay-based timing
- Tone generation
- Basic loop structure
