#include <Arduino.h>

static const int ADC_PIN = 34;     // ADC1, buena práctica
static const int N = 60;           // ventana promedio
static const int PERIOD_MS = 1000;  // muestreo

int readAvgADC() {
  long acc = 0;
  for (int i = 0; i < N; i++) {
    acc += analogRead(ADC_PIN);
    delay(2);
  }
  return (int)(acc / N);
}

void setup() {
  Serial.begin(115200);
  delay(200);
  Serial.println("ADC + Promedio: lectura en tiempo real");
}

void loop() {
  int adc = readAvgADC();

  // Escalamiento didáctico a 0–50 C
  float tempSim = (adc / 4095.0f) * 50.0f;

  Serial.printf("adc=%d,tempSim=%.2fC\n", adc, tempSim);
  delay(PERIOD_MS);
}