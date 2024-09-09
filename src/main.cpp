#include <Arduino.h>

int flagPressed = 0;
const int SW1 = 13; // Button for Red LED
const int SW2 = 12; // Button for Yellow LED
const int SW3 = 9;  // Button for Green LED

const int redLED = 11;    // Pin for Red LED
const int yellowLED = 10; // Pin for Yellow LED
const int greenLED = 8;   // Pin for Green LED

// Variables to store button press counts
int sw1Count = 0;
int sw2Count = 0;
int sw3Count = 0;

// Variables to store the last button states
int lastSW1State = 1;
int lastSW2State = 1;
int lastSW3State = 1;

// Variables to store the time when each button is pressed
unsigned long sw1PressTime = 0;
unsigned long sw2PressTime = 0;
unsigned long sw3PressTime = 0;

void setup()
{
  // Configure button pins as input with pull-up resistors
  pinMode(SW1, INPUT_PULLUP);
  pinMode(SW2, INPUT_PULLUP);
  pinMode(SW3, INPUT_PULLUP);

  // Configure LED pins as output
  pinMode(redLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
  pinMode(greenLED, OUTPUT);

  // Initialize serial communication for debugging
  Serial.begin(9600);
}

void loop()
{
  // Read the current state of the buttons
  int currentSW1State = digitalRead(SW1);
  int currentSW2State = digitalRead(SW2);
  int currentSW3State = digitalRead(SW3);

  // Debouncing and time computation for SW1
  if (lastSW1State == 1 && currentSW1State == 0)
  {            // Button pressed
    delay(50); // Debounce delay for SW1
    if (digitalRead(SW1) == 0)
    {
      sw1Count++;
      Serial.print("SW1 Press Count: ");
      Serial.println(sw1Count);
      sw1PressTime = millis(); // Record the time when SW1 was pressed
    }
  }
  else if (lastSW1State == 0 && currentSW1State == 1)
  {                                                            // Button released
    unsigned long sw1ReleaseTime = millis();                   // Record the time when SW1 was released
    unsigned long sw1HeldTime = sw1ReleaseTime - sw1PressTime; // Calculate the time the button was held
    Serial.print("SW1 Held Time (ms): ");
    Serial.println(sw1HeldTime);
  }

  // Debouncing and time computation for SW2
  if (lastSW2State == HIGH && currentSW2State == LOW)
  {            // Button pressed
    delay(50); // Debounce delay for SW2
    if (digitalRead(SW2) == LOW)
    {
      sw2Count++;
      Serial.print("SW2 Press Count: ");
      Serial.println(sw2Count);
      sw2PressTime = millis(); // Record the time when SW2 was pressed
    }
  }
  else if (lastSW2State == LOW && currentSW2State == HIGH)
  {                                                            // Button released
    unsigned long sw2ReleaseTime = millis();                   // Record the time when SW2 was released
    unsigned long sw2HeldTime = sw2ReleaseTime - sw2PressTime; // Calculate the time the button was held
    Serial.print("SW2 Held Time (ms): ");
    Serial.println(sw2HeldTime);
  }

  // Debouncing and time computation for SW3
  if (lastSW3State == HIGH && currentSW3State == LOW)
  {            // Button pressed
    delay(50); // Debounce delay for SW3
    if (digitalRead(SW3) == LOW)
    {
      sw3Count++;
      Serial.print("SW3 Press Count: ");
      Serial.println(sw3Count);
      sw3PressTime = millis(); // Record the time when SW3 was pressed
    }
  }
  else if (lastSW3State == LOW && currentSW3State == HIGH)
  {
    unsigned long sw3ReleaseTime = millis();
    unsigned long sw3HeldTime = sw3ReleaseTime - sw3PressTime;
    Serial.print("SW3 Held Time (ms): ");
    Serial.println(sw3HeldTime);
  }

  // Save the current states for comparison in the next loop iteration
  lastSW1State = currentSW1State;
  lastSW2State = currentSW2State;
  lastSW3State = currentSW3State;

  // Control the LEDs based on button presses (same as before)
  digitalWrite(redLED, currentSW1State == LOW ? HIGH : LOW);
  digitalWrite(yellowLED, currentSW2State == LOW ? HIGH : LOW);
  digitalWrite(greenLED, currentSW3State == LOW ? HIGH : LOW);
}