/*
  KELAS MESIN HORISONTAL
  GERAK LURUS HORISONAL
  KODE : H.ENGINE-2DC5V-S
*/
#ifndef H_ENGINE_H
#define H_ENGINE_H
#include <Arduino.h>

class H_engine{
  private:
    byte pin1, pin2;

  public:
    H_engine(byte pin1, byte pin2);
    void init();
    void maju();
    void mundur();
    void stop();
};
#endif