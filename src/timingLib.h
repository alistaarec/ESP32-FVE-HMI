#ifndef TIMINGLIB_H
#define TIMINGLIB_H

#include <Arduino.h>
#include "modbusMas.h"
#include "display.h"

unsigned long relayStartTime = 0;
bool relayOn = false;
unsigned long RELAY_DURATION = 10000; //2UL * 60 * 60 * 1000;  // 2 hours in ms

void setRelayTime(int index) {
    switch (index) {
        case 0:
        RELAY_DURATION = 10000;
        break;
        case 1:
        RELAY_DURATION = 20000;
        break;
        case 2:
        RELAY_DURATION = 30000;
        break;
        case 3:
        RELAY_DURATION = 40000;
        break;
        case 4:
        RELAY_DURATION = 50000;
        break;
    }
}

void togglePool(bool turnOn) {
    if (turnOn) {
      relayStartTime = millis();
      relayOn = true;
      toggleRelay(true, 0);
      lv_obj_set_state(ui_Switch1, LV_STATE_CHECKED, 1);
      lv_bar_set_range(ui_timeBar1, 0, RELAY_DURATION);
    } else {
      relayStartTime = 0;
      relayOn = false;
      toggleRelay(false, 0);
      lv_obj_set_state(ui_Switch1, LV_STATE_CHECKED, 0);
      lv_bar_set_value(ui_timeBar1, 0, false);
    }
  }
void poolTiming() {
    if (relayOn) {
        lv_bar_set_value(ui_timeBar1, (millis() - relayStartTime), false);
        if (millis() - relayStartTime >= RELAY_DURATION) {
          togglePool(false);  // time expired, turn off
        }
    }
}

#endif