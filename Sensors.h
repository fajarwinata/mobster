/*
  KELAS SENSOR
  1. Sensor Jarak
      KODE : VL53L0x
  2. Sensor Tekanan (Next)
  3. Sensor Battery
      11k Ohm -> A0
*/

#ifndef SENSORS_H
#define SENSORS_H
#include <Arduino.h>

class Sensors{
  private:
    byte pin1, pin2;

  public:
    Sensors();
    void init();
    int jarak();
    float tekanan();
    float battery();
};
#endif