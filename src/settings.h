#ifndef SETTINGS_H
#define SETTINGS_H

#include <Arduino.h>
#include <EEPROM.h>
#include "display.h"
#include "modbusMas.h"
#include "timingLib.h"

#define EEPROM_SIZE 1

void eeprom_init(){
    EEPROM.begin(EEPROM_SIZE);
    delay(5);
    setRelayTime(EEPROM.read(0));
    lv_dropdown_set_selected(ui_Dropdown1, EEPROM.read(0));
}

void saveSettingsEeprom(unsigned char index) {

        EEPROM.write(0, index);

        EEPROM.commit();
}

#endif