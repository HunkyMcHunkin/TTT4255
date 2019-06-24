int redPin = 7;
int greenPin = 6;
int bluePin = 5;

int b1Pin = 13;
int b2Pin = 12;
int b3Pin = 11;

int code[3] = {3, 1, 2};
int answer[3] = {0, 0, 0};
int i = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);

  pinMode(b1Pin, INPUT);
  pinMode(b2Pin, INPUT);
  pinMode(b3Pin, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (i == 3) {
    bool check = true;
    for (int t = 0; t < 3; t++) {
      if (answer[t] != code[t]){
        check = false;
      }
    }
    if (check) {
      digitalWrite(greenPin, HIGH);
      delay(2000);
      digitalWrite(greenPin, LOW);
    }else {
      digitalWrite(redPin, HIGH);
      delay(2000);
      digitalWrite(redPin, LOW);
    }
    i = 0;
  }
  else if (digitalRead(b1Pin) == HIGH) {
    answer[i] = 1;
    i++;
    digitalWrite(bluePin, HIGH);
    delay(100);
    digitalWrite(bluePin, LOW);
  }
  else if (digitalRead(b2Pin) == HIGH) {
    answer[i] = 2;
    i++;
    digitalWrite(bluePin, HIGH);
    delay(100);
    digitalWrite(bluePin, LOW);
  }
  else if (digitalRead(b3Pin) == HIGH) {
    answer[i] = 3;
    i++;
    digitalWrite(bluePin, HIGH);
    delay(100);
    digitalWrite(bluePin, LOW);
  }
  delay(250);
}
