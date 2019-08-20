/*
  Windchest Pad Sensor
  Hook up each DDR pad sensor to a 5V line, and the other side to an analog input
  Around a pound or so of force will trigger the switch on right in the middle

  Built for an Arduino Mega, but that's just because we need so many analog ports to skip
  additional hardware for debouncing noise on the switch

  Use Touchdesigner to read the serial port
*/

static const uint8_t analog_pins[] = {A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14};
size_t number_pins = sizeof(analog_pins)/sizeof(analog_pins[0]);

void setup() {
  for (int pin = 0; pin < number_pins; pin++) {
    pinMode(analog_pins[pin], INPUT_PULLUP);
  }

  // initialize serial communications at 57600 bps
  Serial.begin(57600);
}

void loop() {
  for (int pin = 0; pin < number_pins; pin++) {
    if (digitalRead(analog_pins[pin])) {
     Serial.print("1,");
    } else {
      Serial.print("0,");
    }
  }
  Serial.println("");
}
