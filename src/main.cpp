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

// Constants for defining short and long press
const unsigned long SHORT_PRESS_MAX = 2000; // 2 seconds

void setup()
{
  // //TASK1
  // pinMode(13, OUTPUT);

  pinMode(SW1, INPUT_PULLUP);
  pinMode(SW2, INPUT_PULLUP);
  pinMode(SW3, INPUT_PULLUP);

  pinMode(red, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(green, OUTPUT);

  // Initialize serial communication for debugging
  Serial.begin(9600);
}

void loop()
{
  // TASK1
  //  turn the LED on
  //  digitalWrite(13, 1); // turn the LED on
  //  delay(1000);            // wait for a second
  //  digitalWrite(13, 0);  // turn the LED off
  //  delay(1000);

  //  Read the current state of the buttons
  int currentSW1State = digitalRead(SW1);
  int currentSW2State = digitalRead(SW2);
  int currentSW3State = digitalRead(SW3);

  // TASK 2,3
  //  Handling SW1 button press and release
  if (lastSW1State == HIGH && currentSW1State == LOW)
  {
    delay(50); // Debouncing
    if (digitalRead(SW1) == LOW)
    {
      sw1Count++;
      Serial.print("SW1 Press Count: ");
      Serial.println(sw1Count);
      sw1PressTime = millis(); // Capture the time when button is pressed
    }
  }
  else if (lastSW1State == LOW && currentSW1State == HIGH)
  {
    unsigned long sw1ReleaseTime = millis();
    unsigned long sw1HeldTime = sw1ReleaseTime - sw1PressTime;
    Serial.print("SW1 Held Time (ms): ");
    Serial.println(sw1HeldTime);

    // TASK4
    //  Check if the press is short or long
    if (sw1HeldTime <= SHORT_PRESS_MAX)
    {
      Serial.println("SW1 Short Press");
    }
    else if (sw1HeldTime > SHORT_PRESS_MAX)
    {
      Serial.println("SW1 Long Press");
    }
  }

  // TASK 2,3
  //  Handling SW2 button press and release
  if (lastSW2State == HIGH && currentSW2State == LOW)
  {
    delay(50); // Debouncing
    if (digitalRead(SW2) == LOW)
    {
      sw2Count++;
      Serial.print("SW2 Press Count: ");
      Serial.println(sw2Count);
      sw2PressTime = millis(); // Capture the time when button is pressed
    }
  }
  else if (lastSW2State == LOW && currentSW2State == HIGH)
  {
    unsigned long sw2ReleaseTime = millis();
    unsigned long sw2HeldTime = sw2ReleaseTime - sw2PressTime;
    Serial.print("SW2 Held Time (ms): ");
    Serial.println(sw2HeldTime);

    // TASK4
    //  Check if the press is short or long
    if (sw2HeldTime <= SHORT_PRESS_MAX)
    {
      Serial.println("SW2 Short Press");
    }
    else if (sw2HeldTime > SHORT_PRESS_MAX)
    {
      Serial.println("SW2 Long Press");
    }
  }
  // TASK 2,3
  //  Handling SW3 button press and release
  if (lastSW3State == HIGH && currentSW3State == LOW)
  {
    delay(50); // Debouncing
    if (digitalRead(SW3) == LOW)
    {
      sw3Count++;
      Serial.print("SW3 Press Count: ");
      Serial.println(sw3Count);
      sw3PressTime = millis(); // Capture the time when button is pressed
    }
  }
  else if (lastSW3State == LOW && currentSW3State == HIGH)
  {
    unsigned long sw3ReleaseTime = millis();
    unsigned long sw3HeldTime = sw3ReleaseTime - sw3PressTime;
    Serial.print("SW3 Held Time (ms): ");
    Serial.println(sw3HeldTime);

    // TASK4
    //  Check if the press is short or long
    if (sw3HeldTime <= SHORT_PRESS_MAX)
    {
      Serial.println("SW3 Short Press");
    }
    else if (sw3HeldTime > SHORT_PRESS_MAX)
    {
      Serial.println("SW3 Long Press");
    }
  }

  // Update the last button states
  lastSW1State = currentSW1State;
  lastSW2State = currentSW2State;
  lastSW3State = currentSW3State;

  // Control the LEDs based on button presses
  digitalWrite(red, currentSW1State == LOW ? HIGH : LOW);
  digitalWrite(yellow, currentSW2State == LOW ? HIGH : LOW);
  digitalWrite(green, currentSW3State == LOW ? HIGH : LOW);
}
