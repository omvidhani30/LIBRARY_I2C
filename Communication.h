#ifndef COMMUNICATION_H
#define COMMUNICATION_H
#include <Arduino.h>
#include <Wire.h>


class I2C{
 
 private:
  uint8_t slave_addr;
  TwoWire* i2c;

  public:

  I2C(uint8_t bus, bool is_master, uint8_t slave_addr);
  void MasterSend(int array[], int size);
  void SlaveReceive(int data[], int size);
  void I2C::MasterReceive(int array[], int size);
  void I2C::SlaveSend(int array[], int size);

};

class UART{

 public:
 
 void init(int rx, int tx, unsigned long baudRate );
 void send(int value);
 int receive();

};


#endif
