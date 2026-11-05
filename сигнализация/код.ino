const int ledPin = 9;
const int buzzerPin = 8;
const int armBtn = 10;
const int sensorBtn = 11;
const int potPin = A0;

bool armed = false;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);

  pinMode(armBtn, INPUT_PULLUP);
  pinMode(sensorBtn, INPUT_PULLUP);
}

void loop() {

  if (digitalRead(armBtn) == LOW) {
    armed = !armed;
    delay(300);

    while (digitalRead(armBtn) == LOW) {
      delay(10);
    }
  }

  if (armed && digitalRead(sensorBtn) == LOW) {

    int potValue = analogRead(potPin);
    int duration = map(potValue, 0, 1023, 1000, 5000);

    unsigned long start = millis();

    while (millis() - start < duration && armed) {

      // Check Arm button during alarm
      if (digitalRead(armBtn) == LOW) {
        armed = false;
        break;
      }

      digitalWrite(ledPin, HIGH);
      tone(buzzerPin, 1000);
      delay(200);

      digitalWrite(ledPin, LOW);
      noTone(buzzerPin);
      delay(200);
    }

    digitalWrite(ledPin, LOW);
    noTone(buzzerPin);

    while (digitalRead(sensorBtn) == LOW) {
      delay(10);
    }
  }
}
