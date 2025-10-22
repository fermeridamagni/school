# Practice 1.1 - Water Level Monitor

## Overview

This practice implements a water level monitoring system using an ultrasonic sensor. The system measures the water level in a tank and displays it using LEDs, with a buzzer alert when the tank is near full capacity.

## Objectives

- Apply ultrasonic sensor for distance measurement
- Implement level indication using multiple LEDs
- Create threshold-based alerts
- Calculate derived values (water level from distance)

## Hardware Components

- Arduino board
- Ultrasonic sensor (HC-SR04) connected to pins 10 (trigger) and 11 (echo)
- Buzzer on pin 8
- LED 1 on pin 5 (low level indicator)
- LED 2 on pin 6 (medium level indicator)
- LED 3 on pin 7 (high level indicator)
- Breadboard and jumper wires

## Functionality

The system operates as follows:

1. Measures distance from sensor to water surface
2. Calculates water level: `waterLevel = tankHeight - distance`
3. Calculates remaining space: `remainingLevel = tankHeight - waterLevel`
4. Controls LEDs based on water level thresholds:
   - **LED 1**: ON when water level ≥ 1cm
   - **LED 2**: ON when water level ≥ half tank height (6.5cm)
   - **LED 3**: ON when water level ≥ 10cm
5. Activates buzzer when tank is near full (≥ 10cm)
6. Displays readings via Serial Monitor

## Key Features

- **Tank Height**: Configured for 13cm tank
- **Progressive Indicators**: LEDs light up sequentially as water level rises
- **High Level Alert**: Buzzer activates when tank is nearly full
- **Real-time Monitoring**: Serial output shows all measurements
- **Remaining Capacity**: Calculates and displays space remaining in tank

## Usage

1. Upload the sketch to your Arduino board
2. Open Serial Monitor at 9600 baud
3. Position the ultrasonic sensor at the top of the tank
4. Add water to the tank and observe LED progression
5. Monitor tank height, water level, and remaining height in Serial Monitor

## Circuit Connections

| Component        | Arduino Pin |
|-----------------|-------------|
| Ultrasonic Trig | 10          |
| Ultrasonic Echo | 11          |
| Buzzer          | 8           |
| LED 1 (Low)     | 5           |
| LED 2 (Medium)  | 6           |
| LED 3 (High)    | 7           |

## Configuration

The tank height is set to 13cm in the code. To adjust for different tank sizes, modify the `tankHeight` variable:

```cpp
int tankHeight = 13;  // Change this value for your tank height (cm)
```
