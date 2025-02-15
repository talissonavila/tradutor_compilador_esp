#include <Arduino.h>
#include <WiFi.h>

int ledPinVerde;
int ledPinAmarelo;
int ledPinVermelho;

void setup() {
    ledPinVerde = 2;
    ledPinAmarelo = 4;
    ledPinVermelho = 5;
    pinMode(ledPinVerde, OUTPUT);
    pinMode(ledPinAmarelo, OUTPUT);
    pinMode(ledPinVermelho, OUTPUT);
}

void loop() {
    digitalWrite(ledPinVerde, HIGH);
    delay(3000);
    digitalWrite(ledPinVerde, LOW);
    digitalWrite(ledPinAmarelo, HIGH);
    delay(1000);
    digitalWrite(ledPinAmarelo, LOW);
    digitalWrite(ledPinVermelho, HIGH);
    delay(3000);
    digitalWrite(ledPinVermelho, LOW);
}
