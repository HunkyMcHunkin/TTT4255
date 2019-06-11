  const int greenPin = 2;
  const int yellowPin = 3;
  const int redPin = 4;
  const int buttonPin = 8;

  bool redLight = true;
  int waitTime = 200;

void setup() {
  // put your setup code here, to run once:
  pinMode(greenPin, OUTPUT);
  pinMode(yellowPin, OUTPUT);
  pinMode(redPin, OUTPUT);
  pinMode(buttonPin, INPUT);

  digitalWrite(redPin, HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (digitalRead(buttonPin) == HIGH) {
    
    if (redLight) {

      digitalWrite(yellowPin, HIGH);
      digitalWrite(redPin, LOW);

      delay(waitTime);

      digitalWrite(greenPin, HIGH);
      digitalWrite(yellowPin, LOW);

      redLight = false;
    }
    else {

      digitalWrite(yellowPin, HIGH);
      digitalWrite(greenPin, LOW);

      delay(waitTime);

      digitalWrite(redPin, HIGH);
      digitalWrite(yellowPin, LOW);

      redLight = true;
    }
  }

  delay(waitTime);
}
