void webpage(){
  server.send(200, "text/html", controlPage);
}

void webSocketEvent(uint8_t num, WStype_t type, uint8_t * payload, size_t welength){
  String payloadString = (const char *)payload;
  Serial.print("payloadString= ");
  Serial.println(payloadString);

  if(type == WStype_TEXT){ //Menerima Text melalui client
    byte separator = payloadString.indexOf('=');
    String var = payloadString.substring(0, separator);
    Serial.print("var = ");
    Serial.println(var);
    String val = payloadString.substring(separator+1);
    Serial.print("value = ");
    Serial.println(val);
    Serial.println(" ");
    
    //Horizontal Engine
    if(var == "h_engine"){
      h_engine = 0;
      v_engine = 0;
      ve.stop();

      if(val == "MA") {
        h_engine = 1;
        he.maju();
      }
      else if(val == "MU"){
        h_engine = 2;
        he.mundur();
      } 
      else{
        h_engine = 0;
        he.stop();
      }        
    }  
       
    // Vertical Engine
    else if(var == "v_engine"){
      v_engine = 0;
      h_engine = 0;
      he.stop();
      if(val == "NA"){
        v_engine = 1;
         ve.naik();
      } 
      else if(val == "TU"){
        v_engine = 2;
         ve.turun();
      } 
      else{
        v_engine = 0;
        ve.stop();
      }
    }

    //STOP ALL
    else if(var == "stop_all"){
      v_engine = 0;
      h_engine = 0;
      ve.stop();
      he.stop();
    }
    

  }

}

void engine_time(int h_engine, int v_engine){
  if(millis() > wait){
    webSocketCount++;
    String he_switch = "OFF";
    String ve_switch = "OFF";

    //status Mesin Horisontal
    if(h_engine == 1) he_switch = "MA";
    else if(h_engine == 2) he_switch = "MU";
    
    //status Mesin Vertical
    if(v_engine == 1) ve_switch = "NA";
    else if(v_engine == 2) ve_switch = "TU";

    //Sensor Jarak

    JSONtxt = "{\"h_engine\":\""+he_switch+"\",\"v_engine\":\""+ve_switch+"\",\"jarak\":\""+dtSensor.jarak()+"\",\"battery\":\""+dtSensor.battery()+"\"}";
    webSocket.broadcastTXT(JSONtxt);
    wait = millis();

  }
}