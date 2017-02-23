/*-----------------------------------------------------------------------------  
  Sketch: Blynk App (WiFi) controlling RGB Led strip via Led Strip driver v1.0
  =============================================================================
  Tested on NodeMCU V3 and WeMos D1
  2017-02-22 Anders Wilhelmsson

  Getting Started Guide -> http://www.blynk.cc/getting-started
  Documentation -> http://docs.blynk.cc/
  Latest Blynk library -> https://github.com/blynkkk/blynk-library/releases/download/v0.4.4/Blynk_Release_v0.4.4.zip
  Latest Blynk server -> https://github.com/blynkkk/blynk-server/releases/download/v0.22.3/server-0.22.3.jar

  http://www.blynk.cc
  twitter.com/blynk_app
  www.facebook.com/blynkapp
  
  LED Driver: (Available @ AliExpress)
  Full-Color-RGB-LED-Strip-Driver-Module-Shield-for-Arduino-STM32-AVR-V1-0
  
  This program is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.
*/  
//-----------------------------------------------------------------------------

#define BLYNK_PRINT Serial        // Comment this out to disable prints and save space
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include "RGBdriver.h"

// LED Driver connected via two wire
#define CLK D4
#define DIO D3
int red, green, blue;
RGBdriver Driver(CLK,DIO);        // Initiate driver

// WiFi credentials
const char* ssid = "xxx";
const char* password = "xxxx";

// Blynk athorization token
// Get this key from "Andriod app, proj settings, auth tokens, Email all" 
char auth[] = "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx";  

//-----------------------------------------------------------------------------

void setup() {
  
  Serial.begin(115200);
  Blynk.begin(auth, ssid, password);
}
//-----------------------------------------------------------------------------
BLYNK_WRITE(0) {
  BLYNK_LOG("Got a value: %s", param.asStr());
  red = param.asInt();
}

BLYNK_WRITE(1) {
  BLYNK_LOG("Got a value: %s", param.asStr());
  green = param.asInt();
}

BLYNK_WRITE(2) {
  BLYNK_LOG("Got a value: %s", param.asStr());
  blue = param.asInt();
}
//-----------------------------------------------------------------------------
void loop() {

  Blynk.run();
 
  Driver.begin();
  Driver.SetColor(red,green,blue); 
  Driver.end();
  
}

