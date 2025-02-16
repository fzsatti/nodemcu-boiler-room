#include <Arduino.h>

#include "supporting_classes/time_functions.h"
#include "supporting_classes/temperature_functions.h"
#include "supporting_classes/display_functions.h"
#include "supporting_classes/supabase_functions.h"

#include "env.h"

// Data wire is plugged into port D2 on the ESP8266
#define ONE_WIRE_BUS D2
#define DHT_BUS D6

#define DSIPLAY_TIME_DELAY 1000 // 1 second
#define SEND_DATA_TIME_DELAY 30 * 1000 // 30 seconds


TimeFunctions timeFunctions;
TemperatureFunctions temperatureFunctions(ONE_WIRE_BUS, DHT_BUS);
DisplayFunctions displayFunctions;
SupabaseFunctions supabaseFunctions;

unsigned long displayTimerTime = 0;
unsigned long sendDataTimerTime = 0;

float waterTemp = 0.0;
float airTemp = 0.0;
float humidity = 0.0;

void setup()
{
  Serial.begin(115200);

  displayFunctions.init();

  WiFi.begin(WIFI_NAME, WIFI_PWD);
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    displayFunctions.displayConnectingScreen();
  }

  timeFunctions.init();
  temperatureFunctions.init();
  supabaseFunctions.init();

  waterTemp = temperatureFunctions.getWaterTemp();
  airTemp = temperatureFunctions.getAirTemp();
  humidity = temperatureFunctions.getAirHumidity();
}

void loop()
{
  unsigned long currentTime = millis();

  if ( currentTime - displayTimerTime >= DSIPLAY_TIME_DELAY ) {
    String time = timeFunctions.getFormattedTime();
    displayFunctions.displayMainScreen(time, waterTemp, airTemp, humidity);
    displayTimerTime = currentTime;
  }
  
  if ( currentTime - sendDataTimerTime >= SEND_DATA_TIME_DELAY ) {
    sendDataTimerTime = currentTime;
    waterTemp = temperatureFunctions.getWaterTemp();
    airTemp = temperatureFunctions.getAirTemp();
    humidity = temperatureFunctions.getAirHumidity();
    supabaseFunctions.sendData(waterTemp, airTemp, humidity);
  }

 
}