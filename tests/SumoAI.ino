#include "MotorSumo.h"
#include "ProximitySensor.h"
#include "IrSumo.h"
#include "SumoAI.h"

MotorSumo ms(18, 32, 4, 26);
ProximitySensor prox;
int pin_Sensors[NB_SENSORS] = {34,35,16,23,17,25,27,19}; //Pins du capteur (8)
IrSumo ir(pin_Sensors,0.3);

SumoAI ai(ms, prox, ir);

void setup() {
  ai.begin();
}

void loop() {}
