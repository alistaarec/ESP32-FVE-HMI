#ifndef WIFICONN_H
#define WIFICONN_H

#include "Arduino.h"
#include "WiFi.h"
#include "WiFiUdp.h"

char ssid[]     = "Galaxy S23 0FEB";
char pass[]     = "10203040";

void wifiConfig() {
    WiFi.begin(ssid, pass);
    while (WiFi.status() != WL_CONNECTED) {
        Serial.println("Connecting...");
        delay(250);
    }
    Serial.println("Connected");
}

#endif