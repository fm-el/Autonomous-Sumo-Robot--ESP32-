#include "IrSumo.h"

IrSumo::IrSumo(const int pins[], float alpha)
: _alpha(alpha), rawData(0), filteredData(0)
{
    for (int i = 0; i < NB_SENSORS; i++) {
        pin_Sensors[i] = pins[i];
        pinMode(pin_Sensors[i], INPUT);
        filteredValues[i] = 0.0;
    }
}

uint8_t IrSumo::getData() {
    rawData = 0;
    for (int i = 0; i < NB_SENSORS; i++) {
        int val = digitalRead(pin_Sensors[i]);
        rawData |= (val << i);
    }
    return rawData;
}

void IrSumo::filterIR(uint8_t raw)  {
    filteredData = 0;
    for (int i = 0; i < NB_SENSORS; i++) {
        uint8_t bit = (raw >> i) & 0x01;
        filteredValues[i] = _alpha * bit + (1.0 - _alpha) * filteredValues[i];

        if (filteredValues[i] >= 0.5)
            filteredData |= (1 << i);
    }
}

void IrSumo::updateEMA()    {
    uint8_t raw = getData();
    filterIR(raw);
}

uint8_t IrSumo::getFilteredData()   {
    return filteredData;
}

bool IrSumo::isLineDetected()   {
    updateEMA();
    return (filteredData != 0);
}
