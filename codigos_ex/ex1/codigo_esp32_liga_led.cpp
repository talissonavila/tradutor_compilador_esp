#include <Arduino.h>
#include <WiFi.h>

int ledPin;

void setup() {
    ledPin = 2;
    pinMode(ledPin, OUTPUT);
}

void loop() {
    digitalWrite(ledPin, HIGH);
    delay(1000);
    digitalWrite(ledPin, LOW);
    delay(1000);
}
