#include "CapacitiveButton.h"

#define SENSOR_THRESHOLD 50
#define SENSOR_DELAY 100

#define SW_CAPACITIVE_NAME "Touch-Sensor"
#define SW_CAPACITIVE_ID "capacitive"
#define SW_CAPACITIVE_TOPIC "switch"

CapacitiveButton::CapacitiveButton(uint8_t sendPin, uint8_t receivePin)
    : HomieNode(SW_CAPACITIVE_ID, SW_CAPACITIVE_ID, SW_CAPACITIVE_TOPIC),
      sensor(sendPin, receivePin),
      receivePin(receivePin) {
  // set up topic
  advertise(SW_CAPACITIVE_TOPIC);
}

void CapacitiveButton::loop() {
  // measure capacitive sensor
  long measurement = sensor.capacitiveSensor(20);
  // check the capacitive sensor
  if (previousMillis == 0 && measurement > SENSOR_THRESHOLD) {
    // keep milliseconds
    previousMillis = millis();

    char cstr[16];
    itoa(measurement, cstr, 10);

    // toggle switch
    setProperty(SW_CAPACITIVE_TOPIC).send(cstr);
  }

  // check whether to reset after delay
  if (previousMillis > 0 && millis() - previousMillis > SENSOR_DELAY) {
    digitalWrite(receivePin, LOW);
    previousMillis = 0;
  }
}
