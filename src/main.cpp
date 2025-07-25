#include "WiFi.h"
#include "Arduino.h"

#include "display.h"
#include "ui.h"
#include "wificonn.h"
#include "ntp_synch.h"
#include "modbusMas.h"

unsigned long lastTime;
unsigned long lastTimeMod;
int ntpDelay = 1000;
int modDelay = 10;

void setup()
{
  Serial1.begin(9600);
  wifiConfig();
  setup_display();
  ui_init();
  lv_scr_load(ui_Screen1);
  lv_timer_handler();

  setupNtp();

  modbusSetup();


}

void loop()
{
  if(millis() > lastTime + ntpDelay) {
    updateTimeDisp();
    lastTime = millis();
  }
  mbtask();
  loop_display();


}
