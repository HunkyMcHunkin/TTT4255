const int buttonPin = 13;
int receivedData;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  while(!Serial){}
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available() > 0) {
    receivedData = Serial.parseInt();

    Serial.print("Teller ned fra ");
    Serial.print(receivedData, DEC);
    Serial.println(" når du trykker på knappen");
  }

  if (digitalRead(buttonPin) == HIGH) {
    while (receivedData >= 0) {
      Serial.println(receivedData--);
      delay(1000);
    }
  }
  delay(200);
}
