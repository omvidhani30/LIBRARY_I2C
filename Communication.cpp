#include "Communication.h"

I2C::I2C(uint8_t bus, bool is_master, uint8_t slave_addr) {

  this->slave_addr = slave_addr;

#ifdef ESP32

  if (is_master && bus == 1) {
    i2c = &Wire;
    i2c->begin(21, 22);
  }

  else if (is_master && bus == 2) {
    i2c = &Wire1;
    i2c->begin(25, 26);
  }

  else if (!is_master && bus == 1) {
    i2c = &Wire;
    i2c->begin(slave_addr);
  }

  else if (!is_master && bus == 2) {
    i2c = &Wire1;
    i2c->begin(slave_addr);
  }

#elif defined(ARDUINO_TEENSY41)

  if (is_master && bus == 1) {
    i2c = &Wire;
    i2c->begin();
  }

  else if (is_master && bus == 2) {
    i2c = &Wire1;
    i2c->begin();
  }

  else if (is_master && bus == 3) {
    i2c = &Wire2;
    i2c->begin();
  }

  
  else if (!is_master && bus == 1) {
    i2c = &Wire;
    i2c->begin(slave_addr);
  }

  else if (!is_master && bus == 2) {
    i2c = &Wire1;
    i2c->begin(slave_addr);

  }

  else if (!is_master && bus == 3) {
    i2c = &Wire2;
    i2c->begin(slave_addr);

  }

#elif defined(ARDUINO_AVR_UNO) || defined(ARDUINO_AVR_NANO) || defined(ARDUINO_AVR_MEGA2560)

  if (is_master) {
    i2c = &Wire;
    Wire.begin();

  }

  else {
    i2c = &Wire;
    Wire.begin(slave_addr);
  }

#endif
}

void I2C::MasterSend(int array[], int size) {

  // uint16_t x = map(value, -32767, 32768, 0, 65535);
  // uint16_t high = highByte(x);
  // uint16_t low = lowByte(x);
  // i2c->beginTransmission(slave_addr);
  // i2c->write(high);
  // i2c->write(low);
  // i2c->endTransmission();

  i2c->beginTransmission(slave_addr);
  i2c->write((byte*)array, size*sizeof(int));
  i2c->endTransmission();
}

void I2C::SlaveReceive(int array[], int size) {

  // if (i2c->available() >= 2) {
  //   uint16_t high = i2c->read();
  //   uint16_t low = i2c->read();
  //   uint16_t result = (high << 8) | low;
  //   int z = map(result, 0, 65535, -32767, 32768);

  //   if (z >= 0) {

  //     z = z + 1;
  //   }

  //   return z;
  // }

i2c->readBytes((byte*)array, sizeof(int)*size); 

}


void I2C::MasterReceive(int array[], int size) {

  // i2c->requestFrom(slave_addr, 2);

  // if (i2c->available() >= 2) {

  //   uint16_t high = i2c->read();
  //   uint16_t low = i2c->read();
  //   uint16_t result = (high << 8) | low;
  //   int z = map(result, 0, 65535, -32767, 32768);

  //   if (z >= 0) {

  //     z = z + 1;
  //   }

  //   return z;
  // }

  i2c->requestFrom(slave_addr, size*sizeof(int));

  if (i2c->available() >= size*sizeof(int)) {
  i2c->readBytes((byte*)array, sizeof(int)*size); 
}

}

void I2C::SlaveSend(int array[], int size) {

 /*uint16_t x = map(value, -32767, 32768, 0, 65535);
  uint16_t high = highByte(x);
  uint16_t low = lowByte(x);
  i2c->write(high);
  i2c->write(low);*/


  i2c->write((byte*)array, sizeof(int)*size);


}

/*void UART::init(int rx, int tx, unsigned long baudRate ){

SoftwareSerial myserial(rx, tx);
myserial.begin(baudRate);

}+*/

/*void UART::send(int value){

  uint16_t x = map(value, -32767, 32768, 0, 65535);
  uint16_t high = highByte(x);
  uint16_t low = lowByte(x);
  myserial.write(high);
  myserial.write(low);

}*/


/*int UART::receive(){

if(mySerial.available() >=2){

 uint16_t high = mySerial.read();
 uint16_t low = mySerial.read();

 int z = map(result, 0, 65535, -32767, 32768);

    if (z >= 0) {

      z = z + 1;
    }

    return z;
  
}*/
