const int led1 = 2;

const int buttonPin = 13;

void setup() {
  // put your setup code here, to run once:
  for (int i = 0; i < 6; i++) {
    pinMode(led1 + i, OUTPUT);
  }
  pinMode(buttonPin, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if ( digitalRead(buttonPin) == HIGH) {
    for (int i = 0; i < 6; i++) {
      digitalWrite(led1 + i, LOW);
    }
    int num = random(1, 7);

    switch (num) {
      case 6:
        digitalWrite(led1 + 5, HIGH);
      case 5:
        digitalWrite(led1 + 4, HIGH);
      case 4:
        digitalWrite(led1 + 3, HIGH);
      case 3:
        digitalWrite(led1 + 2, HIGH);
      case 2:
        digitalWrite(led1 + 1, HIGH);
      case 1:
        digitalWrite(led1, HIGH);
    }
    delay(500);
  }
  delay(20);
}
