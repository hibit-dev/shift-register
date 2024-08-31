// -------------------------------------------------
// Copyright (c) 2024 HiBit <https://www.hibit.dev>
// -------------------------------------------------

#define DATA_PIN 4
#define LATCH_PIN 5
#define CLOCK_PIN 6

byte leds; // Variable to store the pattern indicating which LEDs are currently on/off

void setup()
{
  // Set pins mode
  pinMode(DATA_PIN, OUTPUT);
  pinMode(LATCH_PIN, OUTPUT);
  pinMode(CLOCK_PIN, OUTPUT);
}

void loop()
{
  leds = 0; // Initially turns off all the LEDs

  sendToShiftRegister(leds);
  delay(500);

  // Iterate LEDs one by one
  for (int i = 0; i < 8; i++) {
    // Set HIGH the current LED in the leds variable
    bitSet(leds, i);  

    sendToShiftRegister(leds);
    delay(500);
  }
}

/**
  * This function sends a byte of data to the shift register
  */
void sendToShiftRegister(byte data)
{
  digitalWrite(LATCH_PIN, LOW);
  shiftOut(DATA_PIN, CLOCK_PIN, LSBFIRST, data);
  digitalWrite(LATCH_PIN, HIGH);
}
