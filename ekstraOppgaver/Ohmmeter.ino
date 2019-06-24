int readPin = A2;

int testR = 4700;
int testV = 5;

void setup() {
  // put your setup code here, to run once:
  pinMode(readPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int analogVal = analogRead(readPin);

  float voltage = analogVal * (5.0)/(1023);
  int ohm = (voltage*testR)/(testV - voltage);

  Serial.print("Spenning: ");
  Serial.print(voltage);
  Serial.print(" V Motstand: ");
  Serial.print(ohm);
  Serial.println(" Ohm");

  delay(1000);
}
