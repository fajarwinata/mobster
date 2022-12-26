#include "H_engine.h"

    H_engine::H_engine(byte pin1, byte pin2){
        this->pin1 = pin1;
        this->pin2 = pin2;
        init();
    }

    void H_engine::init(){
      pinMode(pin1, OUTPUT);
      pinMode(pin2, OUTPUT);

      stop();
    }

    void H_engine::mundur() // Mundur Linear Horizontal
    {
      analogWrite(pin1, 0);

      for(int b = 0; b <= 1023; b++){
        analogWrite(pin2, b);
      }

    }

    void H_engine::maju() //Maju Linear Horizontal
    {
      analogWrite(pin2, 0);

      for(int a = 0; a <= 1023; a++){
        analogWrite(pin1, a);
      }

    }

    void H_engine::stop() //Matikan mesin
    {
      analogWrite(pin1, 0);
      analogWrite(pin2, 0);
      delay (200);
    }