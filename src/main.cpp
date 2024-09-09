#include <Arduino.h>

int flagPressed = 0;
const int SW1 = 13;
const int SW2 = 12;
const int SW3 = 9;

const int red = 11;
const int yellow = 10;
const int green = 8;

// Vars to store button press counts
int sw1Count = 0;
int sw2Count = 0;
int sw3Count = 0;

// Vars to store the last button states
int lastSW1State = 1;
int lastSW2State = 1;
int lastSW3State = 1;

// Vars to store the time when each button is pressed
unsigned long sw1PressTime = 0;
unsigned long sw2PressTime = 0;
unsigned long sw3PressTime = 0;

void setup()
{
  pinMode(SW1, INPUT_PULLUP);
  pinMode(SW2, INPUT_PULLUP);
  pinMode(SW3, INPUT_PULLUP);

  pinMode(red, 0);
  pinMode(yellow, 0);
  pinMode(green, 0);
}

void loop()
{
  // Read the current state of the buttons
  int currentSW1State = digitalRead(SW1);
  int currentSW2State = digitalRead(SW2);
  int currentSW3State = digitalRead(SW3);

  if (lastSW1State == 1 && currentSW1State == 0)
  {
    delay(50);
    if (digitalRead(SW1) == 0)
    {
      sw1Count++;
      Serial.print("SW1 Press Count: ");
      Serial.println(sw1Count);
      sw1PressTime = millis();
    }
  }
  else if (lastSW1State == 0 && currentSW1State == 1)
  {
    unsigned long sw1ReleaseTime = millis();
    unsigned long sw1HeldTime = sw1ReleaseTime - sw1PressTime;
    Serial.print("SW1 Held Time (ms): ");
    Serial.println(sw1HeldTime);
  }

  if (lastSW2State == HIGH && currentSW2State == LOW)
  {
    delay(50);
    if (digitalRead(SW2) == LOW)
    {
      sw2Count++;
      Serial.print("SW2 Press Count: ");
      Serial.println(sw2Count);
      sw2PressTime = millis();
    }
  }
  else if (lastSW2State == LOW && currentSW2State == HIGH)
  {
    unsigned long sw2ReleaseTime = millis();
    unsigned long sw2HeldTime = sw2ReleaseTime - sw2PressTime;
    Serial.print("SW2 Held Time (ms): ");
    Serial.println(sw2HeldTime);
  }

  if (lastSW3State == HIGH && currentSW3State == LOW)
  {
    delay(50);
    if (digitalRead(SW3) == LOW)
    {
      sw3Count++;
      Serial.print("SW3 Press Count: ");
      Serial.println(sw3Count);
      sw3PressTime = millis();
    }
  }
  else if (lastSW3State == LOW && currentSW3State == HIGH)
  {
    unsigned long sw3ReleaseTime = millis();
    unsigned long sw3HeldTime = sw3ReleaseTime - sw3PressTime;
    Serial.print("SW3 Held Time (ms): ");
    Serial.println(sw3HeldTime);
  }

  lastSW1State = currentSW1State;
  lastSW2State = currentSW2State;
  lastSW3State = currentSW3State;

  // Controling of the LEDs based on button presses
  digitalWrite(red, currentSW1State == LOW ? HIGH : LOW);
  digitalWrite(yellow, currentSW2State == LOW ? HIGH : LOW);
  digitalWrite(green, currentSW3State == LOW ? HIGH : LOW);
}