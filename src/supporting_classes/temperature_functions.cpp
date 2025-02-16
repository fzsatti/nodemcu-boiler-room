#include "temperature_functions.h"

TemperatureFunctions::TemperatureFunctions(int ds18b20Pin, int dhtPin) : oneWire(ds18b20Pin), sensors(&oneWire), dht(dhtPin, DHTTYPE) {
  pinMode(dhtPin, INPUT);
}

void TemperatureFunctions::init() {
   sensors.begin();
   dht.begin();
}


float TemperatureFunctions::getWaterTemp() {
  sensors.requestTemperatures(); 
  return sensors.getTempCByIndex(0);
}

float TemperatureFunctions::getAirTemp() {
  return dht.readTemperature(); 
}

float TemperatureFunctions::getAirHumidity() {
  return dht.readHumidity(); 
}