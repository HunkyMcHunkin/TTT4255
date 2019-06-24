const int buttonPin = 13;
int receivedData;

void setup() {
  // put your setup code here, to run once:
  pinMode(buttonPin, INPUT);
  Serial.begin(9600);
  while(!Serial){}
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available() > 1) {
    receivedData = Serial.parseInt();

    Serial.print("Teller ned fra ");
    Serial.print(receivedData, DEC);
    Serial.println(" når du trykker på knappen");
    buttonWait(buttonPin);
  }

  if (digitalRead(buttonPin) == HIGH) {
    while (receivedData >= 0) {
      Serial.println(receivedData--);
      delay(1000);
    }
  }
  delay(200);
}

void buttonWait(int buttonPin){
  int buttonState = 0;
  while(1){
    buttonState = digitalRead(buttonPin);
    if (buttonState == HIGH) {
      return;
    }
  }
}
