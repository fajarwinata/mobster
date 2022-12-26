// Assignmen global variabel token string
#define h_engine_1_pin D7
#define h_engine_2_pin D8
#define v_engine_1_pin D5
#define v_engine_2_pin D6

int websocketMillis = 50;

// nomor portal web 80
ESP8266WebServer server(80);
WebSocketsServer webSocket = WebSocketsServer(88);
H_engine he(h_engine_1_pin, h_engine_2_pin);
V_engine ve(v_engine_1_pin, v_engine_2_pin);

//SENSOR
Sensors dtSensor;



// Status Mesin
int h_engine = 0;
int v_engine = 0;
int distance = 0;
String website, JSONtxt, kedalaman;
unsigned long webSocketCount = 0, wait = 0;