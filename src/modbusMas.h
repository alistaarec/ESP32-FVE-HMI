#ifndef MODBUSMAS_H
#define MODBUSMAS_H

#include "Arduino.h"
#include <ModbusRTUMaster.h>
#include <HardwareSerial.h>
#include "display.h"
#include "ui.h"

int relID = 10;

const uint8_t numCoils = 4;
bool coils[numCoils];



#define U2TX 17
#define U2RX 18

HardwareSerial uart2(2);
ModbusRTUMaster modbus(uart2);



void modbusSetup()
{
    uart2.begin(19200, SERIAL_8N1, U2RX, U2TX);
    modbus.begin(19200);
}

void toggleRelay(bool state, int addr) {
    coils[addr] = state;
  }

void mbtask(){
modbus.writeMultipleCoils(10, 0, coils, numCoils);
}


#endif