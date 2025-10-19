#include <Arduino.h>
#include <Ultrasonic.h>

Ultrasonic ultrasonic(10, 11);

const int buzzerPin = 8;
const int led1 = 6;
const int led2 = 7;

int objectCount = 0;
int distance = 0;
bool objectPreviouslyDetected = false;

void setup() {
  Serial.begin(9600);

  pinMode(buzzerPin, OUTPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
}

void loop() {

  distance = ultrasonic.read();

  if (distance <= 12) {
    if (objectPreviouslyDetected == false) {
      objectCount++; // increment the counter ONLY ONCE
      objectPreviouslyDetected = true;

      digitalWrite(led1, LOW); // turn off alert led
      digitalWrite(led2, HIGH); // turn on alert led (showing an object has detected)
      digitalWrite(buzzerPin, HIGH); // turn on buzzer
    }

    // If objectPreviouslyDetected is already true, we do nothing.
    // The object is just sitting there, and we've already counted it.                                                                                                                                    
  } else {
    // Reset the flag so we are ready to detect the NEXT object.
    objectPreviouslyDetected = false;

    digitalWrite(led2, LOW); // turn of alert led
    digitalWrite(led1, HIGH); // turn on alert led
    digitalWrite(buzzerPin, LOW); // turn off buzzer
  }

  Serial.println("--------------");
  Serial.print("Distance (cm): ");
  Serial.print(distance);
  Serial.println();

  Serial.print("Object count: ");
  Serial.print(objectCount);
  Serial.println();

  delay(100); // A small delay to prevent rapid, unstable readings
}