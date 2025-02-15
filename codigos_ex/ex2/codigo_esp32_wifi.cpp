#include <Arduino.h>
#include <WiFi.h>

int ledPin;
int brilho;
String ssid;
String senha;

void setup() {
    ledPin = 2;
    ssid = "MinhaRedeWiFi";
    senha = "MinhaSenhaWiFi";
    pinMode(ledPin, OUTPUT);
    ledcSetup(0, 5000, 8);
    ledcAttachPin(ledPin, 0);
    WiFi.begin(ssid, senha);
}

void loop() {
    brilho = 128;
    analogWrite(ledPin, brilho);
    delay(1000);
    brilho = 0;
    analogWrite(ledPin, brilho);
    delay(1000);
}
