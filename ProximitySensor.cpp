#include "ProximitySensor.h"
#include <Arduino.h>

ProximitySensor::ProximitySensor() {}

bool ProximitySensor::begin() {
    if (!sensor.begin()) {
        Serial.println("Echec de démarrage du Capteur VL53L0X");
        return false;
    }
    return true;
}

void ProximitySensor::update() {
    VL53L0X_RangingMeasurementData_t measure;
    sensor.rangingTest(&measure, false);

    if (measure.RangeStatus != 4) {
        distance = measure.RangeMilliMeter;
    }
}

int ProximitySensor::getDistance() {
    return distance;
}

bool ProximitySensor::isEnemyDetected(int thresholdMM) {
    return (distance > 0 && distance < thresholdMM);
}
