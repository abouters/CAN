#include <Arduino.h>
#include "CAN.h"
#include <Metro.h>

uint8_t receive_data[8] = {};
Metro dispTiming(10);
CanControl DriveCan(2);

void setup() {
  Serial.begin(115200);
  DriveCan.init(1e6);
}

void loop(){
  DriveCan.CANDataPull(0x201, receive_data);
  if(dispTiming.check()){
    Serial.println(DriveCan.check_is_contact(0x201));
    // Serial.println(receive_data[0] << 8 + receive_data[1]);
  }
}