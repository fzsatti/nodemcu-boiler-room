#ifndef TEMP_FUNCTIONS_H
#define TEMP_FUNCTIONS_H
#include <OneWire.h>
#include <DallasTemperature.h>
#include<Arduino.h>
#include<Wire.h>
#include <ESP8266WiFi.h>
#include <DHT.h>

#define DHTTYPE DHT22

class TemperatureFunctions {
  private:
    OneWire oneWire;
    // Pass our oneWire reference to Dallas Temperature.
    DallasTemperature sensors;
    DHT dht;
  public:
    TemperatureFunctions(int ds18b20Pin, int dhtPin);
    void init();
    float getWaterTemp();
    float getAirTemp();
    float getAirHumidity();
};

#endif