#include <Arduino.h>

void setup() {
  Serial.begin(115200);
  delay(200);
  Serial.println("Hola PlatformIO + ESP32");
}

void loop() {
  static uint32_t k = 0;
  Serial.printf("tick=%lu\n", (unsigned long)k++);
  delay(500);
}