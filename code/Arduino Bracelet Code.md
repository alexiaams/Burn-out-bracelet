#include <OneWire.h>
#include <DallasTemperature.h>

// Pin configuration
const int ledPin     = 10;
const int buttonPin  = 2;
const int buzzerPin  = 9;
const int oneWireBus = 4; // DS18B20 data pin

// OneWire + DallasTemperature setup
OneWire oneWire(oneWireBus);
DallasTemperature sensors(&oneWire);

// Button debouncing
int buttonState        = LOW;
int lastButtonState    = LOW;
unsigned long lastDebounceTime = 0;
unsigned long debounceDelay    = 50;

int brightness;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  digitalWrite(buzzerPin, LOW);

  Serial.begin(9600);
  sensors.begin(); // Start DS18B20
}

void loop() {
  // Read temperature
  sensors.requestTemperatures();
  float temperature = sensors.getTempCByIndex(0);
  Serial.print("Temperature: ");
  Serial.println(temperature);

  // Gentle pulsing buzzer if temperature is high
  if (temperature > 34.13) {
    tone(buzzerPin, 400); // soft tone
    delay(300);
    noTone(buzzerPin);
    delay(700);
  } else {
    noTone(buzzerPin);
  }

  // Button debounce + trigger breathing exercise
  int reading = digitalRead(buttonPin);
  if (reading != lastButtonState) {
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > debounceDelay) {
    if (reading != buttonState) {
      buttonState = reading;
      if (buttonState == HIGH) {
        breathingExercise();
      }
    }
  }

  lastButtonState = reading;
}

void breathingExercise() {
  // 4-7-8 breathing cycle, repeated 3 times
  for (int cycle = 0; cycle < 3; cycle++) {
    // Inhale (4s): fade in
    for (brightness = 0; brightness <= 85; brightness++) {
      analogWrite(ledPin, brightness);
      delay(16); // ~4s total
    }

    // Hold (7s): full brightness
    analogWrite(ledPin, 255);
    delay(7000);

    // Exhale (8s): fade out
    for (brightness = 255; brightness >= 0; brightness--) {
      analogWrite(ledPin, brightness);
      delay(31); // ~8s total
    }

    if (cycle < 2) delay(1000);
  }

  // Optional: temperature check after exercise
  sensors.requestTemperatures();
  float temperature = sensors.getTempCByIndex(0);
  Serial.print("Temperature: ");
  Serial.println(temperature);

  if (temperature > 35.0) {
    digitalWrite(buzzerPin, HIGH);
  } else {
    digitalWrite(buzzerPin, LOW);
  }
}
