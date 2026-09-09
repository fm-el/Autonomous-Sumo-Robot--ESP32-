#ifndef IRSUMO_H
#define IRSUMO_H

#include <Arduino.h>

#define NB_SENSORS 8

class IrSumo {
public:
    IrSumo(const int pins[], float alpha);

    uint8_t getData();
    void updateEMA();
    uint8_t getFilteredData();
    bool isLineDetected();

private:
    void filterIR(uint8_t raw);

    int pin_Sensors[NB_SENSORS];
    float filteredValues[NB_SENSORS];

    float _alpha;

    uint8_t rawData;
    uint8_t filteredData;
};

#endif
