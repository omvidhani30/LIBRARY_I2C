#include "Communication.h"
#define slaveAddr 1

I2C slave(2,false,slaveAddr);

void setup() {
Serial.begin(115200);
Wire.onReceive(receive);
}

void loop() {
  
}

void receive(int n){

int val = slave.SlaveReceive();
  Serial.println(val);

}
