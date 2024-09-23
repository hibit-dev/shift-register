// -------------------------------------------------
// Copyright (c) 2024 HiBit <https://www.hibit.dev>
// -------------------------------------------------

#define DATA_PIN 4
#define CLOCK_PIN 5
#define LOAD_PIN 6

byte buttonStates; // Variable to store the state indicating which buttons are currently on/off

void setup()
{
  // Begin serial communication with the host computer
  Serial.begin(115200);
  Serial.println();

  // Set pins mode
  pinMode(DATA_PIN, INPUT);
  pinMode(LOAD_PIN, OUTPUT);
  pinMode(CLOCK_PIN, OUTPUT);
}

void loop()
{
  buttonStates = readFromShiftRegister();

  // Print the button states in binary format
  Serial.println(buttonStates, BIN);

  delay(500); // Wait half a second before reading again
}

/**
  * This function reads a byte of data from the shift register
  */
byte readFromShiftRegister()
{
  digitalWrite(LOAD_PIN, LOW);
  delayMicroseconds(5);
  digitalWrite(LOAD_PIN, HIGH);

  byte buttonStates = shiftIn(DATA_PIN, CLOCK_PIN, MSBFIRST);
  
  return buttonStates;
}
