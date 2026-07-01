#include <Arduino.h>
// paulstoffregen/OneWire@2.3.8
// https://github.com/PaulStoffregen/OneWire
#include <OneWire.h>
// milesburton/DallasTemperature@4.0.6
// https://github.com/milesburton/Arduino-Temperature-Control-Library
#include <DallasTemperature.h>

#define ONE_WIRE_BUS 4 // GPIO4

OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

void setup() {
  Serial.begin(115200);
  sensors.begin();
}

void loop() {
  sensors.requestTemperatures();
  float tempC = sensors.getTempCByIndex(0);
  Serial.printf("温度: %.1f °C\n", tempC);
  delay(1000);
}
