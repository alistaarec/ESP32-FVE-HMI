#ifndef NTPSYNCH_H
#define NTPSYNCH_H

#include "NTP.h"
#include "WiFiUdp.h"
#include "display.h"
#include "ui.h"
#include "Arduino.h"


WiFiUDP wifiUdp;
NTP ntp(wifiUdp);

void setupNtp() {

    ntp.ruleDST("CEST", Last, Sun, Mar, 2, 120); // last sunday in march 2:00, timetone +120min (+1 GMT + 1h summertime offset)
    ntp.ruleSTD("CET", Last, Sun, Oct, 3, 60); // last sunday in october 3:00, timezone +60min (+1 GMT)
    ntp.begin();
    Serial.println("start NTP");
    
}

void updateTimeDisp() {
    Serial.println(ntp.formattedTime("%A %T")); // Www hh:mm:ss
    lv_label_set_text(ui_ntpTime, ntp.formattedTime("%T"));
    lv_label_set_text(ui_ntpTime2, ntp.formattedTime("%T"));
}

#endif