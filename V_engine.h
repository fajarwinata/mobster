/*
  KELAS MESIN VERTIKAL
  GERAK LURUS VERTIKAL
  ----------------------- ENGINE PULL ----------------
  KODE : V.ENGINE-1DC5V-D001
  SPEK : PULLING DOWN 100 cc water
  ----------------------------------------------------
  ----------------------- ENGINE PUSH ----------------
  KODE : V.ENGINE-1DC5V-D002
  SPEK : PUSHING UP 100 cc water
  ----------------------------------------------------
*/
#ifndef V_ENGINE_H
#define V_ENGINE_H
#include <Arduino.h>

class V_engine{
  private:
    byte pin1, pin2;

  public:
    V_engine(byte pin1, byte pin2);
    void init();
    void naik();
    void turun();
    void stop();
};

#endif