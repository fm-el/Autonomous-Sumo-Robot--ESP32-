#include <Arduino.h>
#include "MotorSumo.h"

// Définis tes pins (exemple : gpioLeft, gpioRight, pwmLeft, pwmRight)
MotorSumo ms(18, 32, 4, 26);

void setup() {
Serial.begin(115200);
Serial.println("Test moteurs MotorSumo ESP32");
}

void loop() {
ms.backward(200);

}
