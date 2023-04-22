# ESP32-MQTT-Conexión
### Código para establecer una conexión entre HiveMQ y ESP32
Este es mi código, basado en [este código](https://community.hivemq.com/t/hivemq-using-esp32-and-nodered/1291) proveniente del foro de HiveMQ.

- Conexión con MQTT
- Lectura de un valor analógico con una fotoresistencia
- Escritura de un valor digital con un led que enciende y apaga

## Características

- Conecta el ESP32 a tu red de WiFi
- Conecta el ESP32 a un servidor MQTT
- Envía los valores de una señal analógica de manera constante después de recibir un 0 (cero) en ese canal
- Apaga un led enviando un 0(cero) el canal del control
- Enciende un led enviando un 1(uno) el canal del control

## Librerías
```
#include <WiFi.h>
#include <PubSubClient.h>
#include <WiFiClientSecure.h>
```
En esta tabla encontrarás el origen de las librerías empleadas
| Librería | Origen |
| ------ | ------ |
| PubSubClient.h | [Pagina oficial](https://pubsubclient.knolleary.net/) |
| Wifi.h y WifiClientSecure.h | [Sitio de guithub](https://github.com/arduino-libraries/Arduino_ESP32_OTA) |

## Variables a modificar
Las primeras variables a modificar son las de coneccion a wifi
```
const char* ssid = "nombre-de-red";
const char* password = "contraseña";
```
Esta información es proporcionada por HiveMQ y es generada por el usuario.
```
const char* mqtt_server = "xxxxxxxxxxxxxxxxxxxxxxxx";
const int mqtt_port = 8883;
const char* mqtt_username = "user";
const char* mqtt_password = "Qwerty123";
```
Los canales son para la manipulación de los componentes
```
const char* CONTROL_LED_TOPIC = "control-led";
const char* VALOR_ANALOGICO_TOPIC = "valor-analogico";
```
Pines de entrada (el fotoresistor) y salida (el led)
```
const int ledPin = 26;
const int inputPin = 36;
```
