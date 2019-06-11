  const int startLed = 2;
  const int buttonPin = 13;

  const int numberOfLed = 6;

void setup() {
  // put your setup code here, to run once:
  for (int i = 0; i < numberOfLed; i++) {
    pinMode(startLed + i, OUTPUT);
  }

  pinMode(buttonPin, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (digitalRead(buttonPin) == HIGH) {
    for (int i = 0; i < numberOfLed; i++) {
      delay(1000);
      digitalWrite(startLed + i, LOW);
    }
  }
  delay(10);
}
