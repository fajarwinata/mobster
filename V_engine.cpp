#include "V_engine.h"

    V_engine::V_engine(byte pin1, byte pin2){
        this->pin1 = pin1;
        this->pin2 = pin2;
        init();
    }

    void V_engine::init(){
      pinMode(pin1, OUTPUT);
      pinMode(pin2, OUTPUT);

      stop();
    }

    void V_engine::naik() //V.ENGINE-1DC5V-D002 --> ON
    {
      digitalWrite(pin1, LOW);
      digitalWrite(pin2, HIGH);
      delay(10);
    }

    void V_engine::turun() //V.ENGINE-1DC5V-D001 --> ON
    {
      digitalWrite(pin1, HIGH);
      digitalWrite(pin2, LOW);
      delay(10);
    }

    void V_engine::stop() //Matikan mesin
    {
      digitalWrite(pin1, HIGH);
      digitalWrite(pin2, HIGH);
      delay(200);
    }