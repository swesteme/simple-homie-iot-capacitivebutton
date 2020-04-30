#pragma once

#include <Homie.h>
#include <CapacitiveSensor.h>

class CapacitiveButton : public HomieNode {
  public:
    CapacitiveButton(uint8_t sendPin, uint8_t receivePin);

  protected:
    virtual void loop();
    
  private:
    CapacitiveSensor sensor;

    // keep last time the button was touched
    unsigned long previousMillis;

    uint8_t receivePin;
};

