#include "Communication.h"
#define slaveAddr 1

I2C master(1,true,slaveAddr);

void setup() {
 Serial.begin(115200);
}

void loop() {
  
master.MasterSend(400);

}



