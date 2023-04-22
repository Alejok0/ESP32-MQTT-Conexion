//#define CAYENNE_DEBUG
#define CAYENNE_PRINT Serial
#include <CayenneMQTTESP32.h>

// WiFi network info.
const char* ssid = "red";
const char* password = "contraseña-red";

// Cayenne authentication info. This should be obtained from the Cayenne Dashboard.
const char* mqtt_server = "xxxxxxxxxxxxxxxxxxxxxxxxxxxxx";
const char* mqtt_username = "user";
const char* mqtt_password = "pass";
const char* client_id = "xxxxxxxxxxxxxxxxxxxxxx"

// Definición de los canales a utilizar
const int CONTROL_LED_TOPIC = 0;
const int VALOR_ANALOGICO_TOPIC = 1;

const int ledPin = 26;
const int inputPin = 36;


void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(inputPin, ANALOG);  
  Serial.begin(9600);
  Cayenne.begin(mqtt_username, mqtt_password, client_id, ssid, password);
}

void loop() {
  Cayenne.loop();
}

// Default function for sending sensor data at intervals to Cayenne.
// You can also use functions for specific channels, e.g CAYENNE_OUT(1) for sending channel 1 data.
CAYENNE_OUT_DEFAULT() {
  int valor_analogico = analogRead(inputPin);
  Serial.println(valor_analogico);
  Cayenne.virtualWrite(VALOR_ANALOGICO_TOPIC, valor_analogico);
}

// Default function for processing actuator commands from the Cayenne Dashboard.
// You can also use functions for specific channels, e.g CAYENNE_IN(1) for channel 1 commands.
CAYENNE_IN(0) {  // Esta función se ejecuta cuando se recibe un mensaje en el canal 0
  int value = getValue.asInt();
  digitalWrite(ledPin, value);
  CAYENNE_LOG("Channel %u, value %s", request.channel, getValue.asString());
}

CAYENNE_IN_DEFAULT() {
  CAYENNE_LOG("Default: Channel %u, value %s", request.channel, getValue.asString());
  //Process message here. If there is an error set an error message using getValue.setError(), e.g getValue.setError("Error message");
}
