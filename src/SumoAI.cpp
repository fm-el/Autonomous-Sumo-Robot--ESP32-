#include "SumoAI.h"

SumoAI :: SumoAI(MotorSumo &ms, ProximitySensor &prox, IrSumo &ir) : _ms(ms), _prox(prox), _ir(ir) {}

void SumoAI::TaskSensors(void *pvParameters) {
    SumoAI *ai = static_cast<SumoAI*>(pvParameters);
    ai->runSensors();
}

void SumoAI::TaskControl(void *pvParameters) {
    SumoAI *ai = static_cast<SumoAI*>(pvParameters);
    ai->runControl();
}

void SumoAI::runSensors() {
    while (1) {
        _prox.update();
        _ir.getData();
        vTaskDelay(10 / portTICK_PERIOD_MS);
    }
}

void SumoAI::runControl() {
    vTaskDelay(500);
    while (1) {
      if (_ir.isLineDetected) {
        _state = AVOID_EDGE;
        doAvoidEdge();
        }
      else if (_prox.isEnemyDetected()) {
        _state = ATTACK;
        doAttack();
        }
      else {
        if (_state == ATTACK) {
          _state = LOST_CONTACT;
          lastEnemyLost = millis();
          doLostContact();
          }
        if (_state == LOST_CONTACT &&
          millis() - lastEnemyLost > 600) {
          _state = SEARCH;
          }
        if (_state == SEARCH) {
          doSearch();
          }
        }
        vTaskDelay(20 / portTICK_PERIOD_MS);
    }
}

void SumoAI::begin() {
 xTaskCreatePinnedToCore(TaskSensors, "Sensors", 2048, this, 1, NULL, 0);
 xTaskCreatePinnedToCore(TaskControl, "Control", 2048, this, 1, NULL, 1);
}

void SumoAI::doSearch(){
    _ms.spinLeft(150);
     vTaskDelay(5000 / portTICK_PERIOD_MS);
    _ms.forward(100);
     vTaskDelay(1000 / portTICK_PERIOD_MS);
    _ms.spinRight(150);
    vTaskDelay(5000 / portTICK_PERIOD_MS);
    _ms.stop();

}

void SumoAI::doAttack(){
  _ms.forward(255);
}

void SumoAI::doAvoidEdge(){
  _ms.backward(200);
  vTaskDelay(200 / portTICK_PERIOD_MS);
  _ms.right(200);
  vTaskDelay(300 / portTICK_PERIOD_MS);
 
}

void SumoAI::doLostContact(){
  _ms.stop();
   vTaskDelay(80 / portTICK_PERIOD_MS);
  _ms.left(200);
   vTaskDelay(300 / portTICK_PERIOD_MS);
