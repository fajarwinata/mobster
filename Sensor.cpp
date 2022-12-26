#include "Sensors.h"
#include <Adafruit_VL53L0X.h>
#include <HX711.h>

Adafruit_VL53L0X lox = Adafruit_VL53L0X();
HX711 scale;

    Sensors::Sensors(){
        init();
    }

    void Sensors::init(){
        Serial.println("VL53L0X :: Sensor Jarak");
        if (!lox.begin()) {
          Serial.println(F("Gagal Akses Sensor VL53L0X"));
          while(1);
        }

        //SETUP SENSOR PRESSURE
        // scale.begin(D7, D8);

        // Serial.print("read: \t\t");
        // Serial.println(scale.read());
        // Serial.print("read average: \t\t");
        // Serial.println(scale.read_average(20));
        // Serial.print("get value: \t\t");
        // Serial.println(scale.get_value(5));                        // print the average of 5 readings from the ADC minus the tare weight (not set yet)
        // Serial.print("get units: \t\t");
        // Serial.println(scale.get_units(5), 1);   
        
        // // by the SCALE parameter (not set yet)
        // scale.set_scale(2280.f);                      // this value is obtained by calibrating the scale with known weights;
        // scale.tare();                                 // reset the scale to 0
        // Serial.println("After setting up the scale:");
        // Serial.print("read: \t\t");
        // Serial.println(scale.read());                 // print a raw reading from the ADC
        // Serial.print("read average: \t\t");
        // Serial.println(scale.read_average(20));       // print the average of 20 readings from the ADC
        // Serial.print("get value: \t\t");
        // Serial.println(scale.get_value(5));          // print the average of 5 readings from the ADC minus the tare weight, set with tare()
        // Serial.print("get units: \t\t");
        // Serial.println(scale.get_units(5), 1);        // print the average of 5 readings from the ADC minus tare weight, divided
    }

    int Sensors::jarak() //Jarak Kedalaman Air Maksimal 2 meter
    {
      VL53L0X_RangingMeasurementData_t measure;
      int jr = 0;
      Serial.print("Membaca Kedalaman... ");
      lox.rangingTest(&measure, false); // pass in 'true' to get debug data printout!

      if (measure.RangeStatus != 4) {  // phase failures have incorrect data
        Serial.print("Jarak (mm): "); Serial.println(measure.RangeMilliMeter);
        jr = measure.RangeMilliMeter;
        delay(10);
      } else {
        Serial.println(" Lebih dari 2 Meter ");
        jr = -1;
        delay(10);
      }

      return jr;
    }

    float Sensors::tekanan() //Tekanan Air
    {
      float unit = scale.get_units(); //mmHg
      float kPa  = unit*0.133322; //KiloPascal
      Serial.print("Pembacaan:\t");
      Serial.print(unit, 1);
      Serial.print("\t| Rata-rata:\t");
      Serial.println(scale.get_units(10), 1);
      scale.power_down();                                                  // put the ADC in sleep mode
      delay(500);
      scale.power_up();

      return kPa;
     
    }

    float Sensors::battery()
    {
      int sensorValue = analogRead(A0);
      float hasil = sensorValue*(3 / 1024.0)*10;

      return hasil;
    }