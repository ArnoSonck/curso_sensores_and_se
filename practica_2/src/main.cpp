#include <Arduino.h>
#include <OneWire.h>
#include <DallasTemperature.h>

static const int ONE_WIRE_BUS = 4;

OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

void setup() {
  Serial.begin(115200);
  delay(200);
  Serial.println("ESP32 + DS18B20: temperatura real");

  sensors.begin();
}

void loop() {
  sensors.requestTemperatures();
  float tempC = sensors.getTempCByIndex(0);

  if (tempC == DEVICE_DISCONNECTED_C) {
    Serial.println("ERROR: DS18B20 desconectado");
  } else {
    Serial.printf("temp=%.2fC\n", tempC);
  }

  delay(500);
}