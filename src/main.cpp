#include <Arduino.h>
#include <DMXSerial.h>

#define relayPin 4
#define switchTime 2000

void setup() {
  DMXSerial.init(DMXReceiver);
  
  pinMode(relayPin, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  unsigned long lastPacket = DMXSerial.noDataSince();

  digitalWrite(relayPin, lastPacket < switchTime);
  digitalWrite(LED_BUILTIN, lastPacket < switchTime);
}