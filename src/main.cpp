#include "WiFi.h"
#include "Arduino.h"

#include "display.h"
#include "ui.h"
#include "wificonn.h"
#include "ntp_synch.h"
#include "modbusMas.h"
#include "settings.h"

unsigned long lastTime;
unsigned long lastTimeMod;
int ntpDelay = 1000;
int modDelay = 10;

void setup()
{
  Serial.begin(115200);
  wifiConfig();
  delay(50);
  setup_display();
  delay(50);
  ui_init();
  lv_scr_load(ui_Screen1);
  delay(50);
  setupNtp();
  eeprom_init();
  delay(50);
  modbusSetup();
  delay(50);
  updateTimeDisp();
  delay(50);
}

void loop()
{
  if(millis() > lastTime + ntpDelay) {
    updateTimeDisp();
    lastTime = millis();
  }
  mbtask();
  loop_display();
  poolTiming();
  delay(10);


}
