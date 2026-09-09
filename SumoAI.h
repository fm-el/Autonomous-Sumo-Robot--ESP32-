#ifndef SUMOAI_H
#define SUMOAI_H

#include <Arduino.h>
#include "MotorSumo.h"
#include "ProximitySensor.h"
#include "IrSumo.h"

class SumoAI {

public:

  SumoAI(MotorSumo &ms, ProximitySensor &prox, IrSumo &ir);
  void begin(); //Démarre les tasks

private:

  MotorSumo &_ms;
  ProximitySensor &_prox;
  IrSumo &_ir;

  void doAvoidEdge();
  void doSearch();
  void doAttack();
  void doLostContact();

  static void TaskSensors(void *pvParameters);
  static void TaskControl(void *pvParameters);

  void runSensors();
  void runControl();

  enum AIState {SEARCH,ATTACK,AVOID_EDGE,LOST_CONTACT};
  AIState _state = SEARCH;

  unsigned long lastEnemyLost = 0;
};

#endif