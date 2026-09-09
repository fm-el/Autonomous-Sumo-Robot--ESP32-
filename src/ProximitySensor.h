#ifndef PROXIMITYSENSOR_H
#define PROXIMITYSENSOR_H

#include "Adafruit_VL53L0X.h"

class ProximitySensor {
private:
    Adafruit_VL53L0X sensor;
    int distance;

public:
  ProximitySensor();
  
    bool begin();           
    void update();
    int getDistance();
    bool isEnemyDetected(int thresholdMM = 100);
};

#endif
