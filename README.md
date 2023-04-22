# ESP32-MQTT-Conexión
### Código para establecer una conexión entre Cayenne y ESP32
Este es mi código, basado en [este código](https://github.com/myDevicesIoT/Cayenne-MQTT-ESP/blob/master/examples/ESP32/ESP32.ino) proveniente de los ejemplos  de Cayenne.

- Conexión con MQTT
- Lectura de un valor analógico con una fotoresistencia
- Escritura de un valor digital con un led que enciende y apaga

## Características

- Conecta el ESP32 a tu red de WiFi
- Conecta el ESP32 a un servidor MQTT
- Envía los valores de una señal analógica de manera constante después de recibir un 0 (cero) en ese canal
- Apaga un led enviando un 0(cero) el canal del control
- Enciende un led enviando un 1(uno) el canal del control

## Librería
```
#include <CayenneMQTTESP32.h>
```
En esta tabla encontrarás el origen de las librería empleada
| Librería | Origen |
| ------ | ------ |
| Cayenne |[Sitio de guithub](https://github.com/myDevicesIoT/Cayenne-MQTT-ESP) |

## Variables a modificar
Las primeras variables a modificar son las de coneccion a wifi
```
const char* ssid = "nombre-de-red";
const char* password = "contraseña";
```
Esta información es proporcionada por Cayenne
```
const char* mqtt_server = "xxxxxxxxxxxxxxxxxxxxxxxx";
const char* mqtt_username = "user";
const char* mqtt_password = "Qwerty123";
const char* client_id = "xxxxxxxxxxxxxxxxxxxxxxxxxx"
```
Los canales son para la manipulación de los componentes
```
const int CONTROL_LED_TOPIC = 0;
const int VALOR_ANALOGICO_TOPIC = 1;
```
Pines de entrada (el fotoresistor) y salida (el led)
```
const int ledPin = 26;
const int inputPin = 36;
```
