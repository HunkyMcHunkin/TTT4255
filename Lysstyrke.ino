  const int ledPin = 3;
  const int buttonPin = 13;

  int var = 0;
  int x = 20;

void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin, OUTPUT);
  
  pinMode(buttonPin, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (digitalRead(buttonPin) == HIGH) {
    analogWrite(ledPin, var);
    var+= x;
    if (var + x > 255) {
      var = 0;
    }
    delay(300);
  }
  delay(50);
}
