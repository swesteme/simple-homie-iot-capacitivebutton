# Simple Homie IOT Esp8266 Infrared
[![Build Status](https://travis-ci.org/swesteme/simple-homie-iot-capacitivebutton.svg?branch=develop)](https://travis-ci.org/swesteme/simple-homie-iot-capacitivebutton)
[![License](https://img.shields.io/badge/license-MIT-blue.svg)](https://raw.githubusercontent.com/swesteme/simple-homie-iot-capacitivebutton/develop/LICENSE)
[![PRs Welcome](https://img.shields.io/badge/PRs-welcome-brightgreen.svg?style=flat-square)](http://makeapullrequest.com)
__________

This small library is just a distilled part of code from my use of the great Homie IOT Esp8266 library by Marvin Roger and Ian Hubbertz. To get sensor data from a circuit's capacitive button, the "CapacitiveSensor" library by Paul Stoffregen is used.

You may use it if you have ESPs switching things on and off using a capacitive button.

**Note:** this is only one of the libraries. If you use other sensors and transmitters as well you might be interested in the following libraries: [simple-homie-iot-rc433](https://github.com/swesteme/simple-homie-iot-rc433) or [simple-homie-iot-ir](https://github.com/swesteme/simple-homie-iot-ir).

## Basics
Please refer to the description in the [base library](https://github.com/swesteme/simple-homie-iot) for details about how switches, senders and receivers work, and how this connects to MQTT topics.

## Example
A simple example containing the `killconfig` Homie node from the parent library. It can be signalled via MQTT to erase the Homie configuration on device and reboot into AccessPoint mode.

The following lines declare a capacitive button object "between" pins `D1` and `D2`.

```
#include <Arduino.h>
#include <KillConfigNode.h>
#include <CapacitiveButton.h>

// Homie node receiving the signal to kill the Homie configuration and reboot.
KillConfigNode killConfigNode;

// Capacitive sensor as MQTT button
CapacitiveButton button(D1, D2);

void setup() {
  Serial.begin(115200);
  Serial << endl << "Start setup..." << endl;

  // inititalise Homie library
  Homie_setFirmware("livingroom", "1.0.0");
  Homie.setup();

  Serial << "Finished setup." << endl;
}

void loop() {
  // run homie loop
  Homie.loop();
}
```

## Installation
Install the library by adding it to your project's platformio.ini:

```
lib_deps =
    simple-homie-iot-capacitivebutton
```

## Communication
- If you **have found a bug**, open an issue.
- If you **have a feature request**, open an issue.
- If you **want to contribute**, submit a pull request.

## License
The library is available under the MIT license. See the LICENSE file for more info.

Copyright (c) 2020 Sebastian Westemeyer
