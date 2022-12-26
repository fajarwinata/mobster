#include <ESP8266WiFi.h>
#include <DNSServer.h>
#include <ESP8266WebServer.h>
#include <WiFiManager.h>
#include <WebSocketsServer.h>
#include "H_engine.h"
#include "V_engine.h"
#include "Sensors.h"
#include "controlPage.h"
#include "config.h"

void setup() {
  Serial.begin(115200);
  // WiFiManager
  WiFiManager wifiManager;
  //wifiManager.resetSettings();
  
  // custom ip for portal
  //wifiManager.setAPConfig(IPAddress(10,0,1,1), IPAddress(10,0,1,1), IPAddress(255,255,255,0));

  wifiManager.autoConnect("SUBMRANIE GROUP-1");
  //wifiManager.autoConnect();
  
  // Pengecekan Serial
  Serial.println("Terhubung Ke Kapal Selam.");
  
  //Memulai Layanan
  server.on("/", webpage);
  server.begin();
  webSocket.begin();
  webSocket.onEvent(webSocketEvent);
}

void loop(){
  webSocket.loop();
  server.handleClient();
  engine_time(h_engine, v_engine);
  delay(50);
}