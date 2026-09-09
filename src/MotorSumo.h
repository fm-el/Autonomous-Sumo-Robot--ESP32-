#ifndef MOTORSUMO_H 
#define MOTORSUMO_H 
#include <stdint.h> 
#include <Arduino.h> 
class MotorSumo { 
  public: MotorSumo(uint8_t gpioLeft, uint8_t gpioRight, uint8_t pwmLeft, uint8_t pwmRight); 
    void forward(uint8_t speed); 
    void backward(uint8_t speed); 
    void left(uint8_t speed); 
    void right(uint8_t speed); 
    void stop(); 
    void spinLeft(uint8_t speed); 
    void spinRight(uint8_t speed); 
  
  private: 
    uint8_t _gpioLeft, _gpioRight; 
    uint8_t _pwmLeft, _pwmRight; 
    }; 
#endif
