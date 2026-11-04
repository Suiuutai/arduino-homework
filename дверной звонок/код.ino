const int ledPin = 9;
const int buzzerPin = 8;
const int buttonPin = 13;
const int potPin = A0;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
}

void loop() {

  if (digitalRead(buttonPin) == LOW) {

    int potValue = analogRead(potPin);

    int duration = map(potValue, 0, 1023, 1000, 5000);

    digitalWrite(ledPin, HIGH);

    tone(buzzerPin, 1000);

    delay(duration);

    digitalWrite(ledPin, LOW);

    noTone(buzzerPin);

    delay(200);
  }
}
