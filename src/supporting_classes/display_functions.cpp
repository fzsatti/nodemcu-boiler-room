#include "display_functions.h"

DisplayFunctions::DisplayFunctions()
  : u8g2(U8G2_R0, /* clock=*/12, /* data=*/14, /* reset=*/U8X8_PIN_NONE) {
}

void DisplayFunctions::init() {
  u8g2.begin();
  u8g2.clearBuffer();
  u8g2.setFont(u8g2_font_7x14B_tr);
}

void DisplayFunctions::displayConnectingScreen() {
  u8g2.drawStr(0, 10, "WiFi ...");
  u8g2.sendBuffer();
}

void DisplayFunctions::displayMainScreen(String time, float tempWater, float tempAir, float humidity) {
  u8g2.clearBuffer();
  u8g2.setFont(u8g2_font_6x13_mr);

  String time_str = time;
  u8g2.drawStr(0, 12, time_str.c_str());

  u8g2.setFont(u8g2_font_6x13_mr);
  char buffer[20];
  sprintf(buffer, "%.1f", tempWater);
  String temp_water_msg = "W: " + String(buffer) + " ^C";
  u8g2.drawStr(0, 25, temp_water_msg.c_str());

  sprintf(buffer, "%.1f", tempAir);
  String temp_air_msg = "A: " + String(buffer) + " ^C";
  u8g2.drawStr(0, 40, temp_air_msg.c_str());

  sprintf(buffer, "%.1f", humidity);
  String humidity_msg = "H: " + String(buffer) + " %";
  u8g2.drawStr(0, 55, humidity_msg.c_str());

  u8g2.sendBuffer();
}