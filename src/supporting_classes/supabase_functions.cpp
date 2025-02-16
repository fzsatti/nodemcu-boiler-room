#include "supabase_functions.h"
#include "env.h"

SupabaseFunctions::SupabaseFunctions()
  : supabase() {
}

void SupabaseFunctions::init() {
  supabase.begin(SUPABASE_URL, SUPABASE_KEY);
}

void SupabaseFunctions::sendData(float waterTemp, float airTemp, float humididty) {
  // Add the table name here
  String tableName = "boiler_room_temp";
  // change the correct columns names you create in your table
  String jsonData = "{\"temp_water\": "+String(waterTemp)+", \"humidity\": "+String(humididty)+", \"temp_air_ext\": "+String(airTemp)+"}";

  // sending data to supabase
  int response = supabase.insert(tableName, jsonData, false);
  if (response == 200 || response == 201) {
    Serial.println("Data inserted successfully!");
  } else {
    Serial.print("Failed to insert data. HTTP response: ");
    Serial.println(response);
  }
}