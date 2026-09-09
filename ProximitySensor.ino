#include "ProximitySensor.h"

ProximitySensor prox;

void setup() {
  Serial.begin(115200);

  Serial.println("Initialisation du VL53...");
  while (!prox.begin()) {
    Serial.println("Echec, nouvelle tentative...");
    delay(100);
  }
}

void loop() {
  prox.update();

  Serial.print("Distance : ");
  Serial.println(prox.getDistance());

  if (prox.isEnemyDetected(100)) {
    Serial.println("ENNEMI !");
  }

  delay(100);
}
