#include "MotorSumo.h"

MotorSumo::MotorSumo(uint8_t gpioLeft, uint8_t gpioRight, uint8_t pwmLeft, uint8_t pwmRight)
    : _gpioLeft(gpioLeft), _gpioRight(gpioRight), _pwmLeft(pwmLeft), _pwmRight(pwmRight) {

  pinMode(_gpioLeft, OUTPUT);
  pinMode(_gpioRight, OUTPUT);

  analogWrite(_pwmLeft, 0);
  analogWrite(_pwmRight, 0);
}

// -------- Déplacements simples compatibles avec 2 pins / moteur --------

void MotorSumo::forward(uint8_t speed) {
  digitalWrite(_gpioLeft, HIGH);     // sens avant gauche
  digitalWrite(_gpioRight, HIGH);    // sens avant droit
  analogWrite(_pwmLeft, speed);      
  analogWrite(_pwmRight, speed);     
}

void MotorSumo::backward(uint8_t speed) {
  digitalWrite(_gpioLeft, LOW);      // sens arrière gauche
  digitalWrite(_gpioRight, LOW);     // sens arrière droit
  analogWrite(_pwmLeft, speed);
  analogWrite(_pwmRight, speed);
}

void MotorSumo::stop() {
  analogWrite(_pwmLeft, 0);
  analogWrite(_pwmRight, 0);
}

// -------- Virages compatibles avec ton câblage --------

// Virage à droite = moteur gauche plus rapide
void MotorSumo::right(uint8_t speed) {
  digitalWrite(_gpioLeft, HIGH);
  digitalWrite(_gpioRight, HIGH);
  analogWrite(_pwmLeft, speed);           // gauche vitesse normale
  analogWrite(_pwmRight, 0);      // droite ralenti
}

// Virage à gauche = moteur droit plus rapide
void MotorSumo::left(uint8_t speed) {
  digitalWrite(_gpioLeft, HIGH);
  digitalWrite(_gpioRight, HIGH);
  analogWrite(_pwmLeft, 0);       // gauche ralenti
  analogWrite(_pwmRight, speed);          // droite vitesse normale
}

void MotorSumo::spinLeft(uint8_t speed) {
  digitalWrite(_gpioLeft, HIGH);
  digitalWrite(_gpioRight, LOW);

  analogWrite(_pwmLeft, speed);     // gauche fort
  analogWrite(_pwmRight, speed); // droite très faible
}

void MotorSumo::spinRight(uint8_t speed) {
  digitalWrite(_gpioLeft, LOW);
  digitalWrite(_gpioRight, HIGH);

  analogWrite(_pwmLeft, speed);  // gauche très faible
  analogWrite(_pwmRight, speed);     // droite fort
}
