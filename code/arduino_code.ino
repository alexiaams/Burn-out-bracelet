#include <OneWire.h>
#include <DallasTemperature.h>

// Pin configuration
const int ledPin     = 10;
const int buttonPin  = 2;
const int buzzerPin  = 9;
const int oneWireBus = 4; // DS18B20 data pin connected here

// OneWire + DallasTemperature setup
OneWire oneWire(oneWireBus);
DallasTemperature sensors(&oneWire);

// Button debouncing variables
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
  sensors.begin(); // Start the DS18B20 sensor
}

void loop() {
  // Read temperature
  sensors.requestTemperatures();
  float temperature = sensors.getTempCByIndex(0);
  Serial.print("Temperature: ");
  Serial.println(temperature);

  // Gentle, pulsing tone if temperature high
  if (temperature > 34.13) {
    tone(buzzerPin, 400); // 400 Hz soft tone
    delay(300);
    noTone(buzzerPin);
    delay(700);
  } else {
    noTone(buzzerPin);
  }

  // Button debounce and breathing exercise trigger
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
  // Perform 3 cycles of 4-7-8 breathing
  for (int cycle = 0; cycle < 3; cycle++) {
    // Inhale (4s) – LED fade in
    for (brightness = 0; brightness <= 85; brightness++) {
      analogWrite(ledPin, brightness);
      delay(16); // ~4s total
    }

    // Hold (7s) – LED fully on
    analogWrite(ledPin, 255);
    delay(7000);

    // Exhale (8s) – LED fade out
    for (brightness = 255; brightness >= 0; brightness--) {
      analogWrite(ledPin, brightness);
      delay(31); // ~8s total
    }

    if (cycle < 2) delay(1000);
  }

  // Temperature check after breathing exercise
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
