  #include <CapacitiveSensor.h>
  CapacitiveSensor cap = CapacitiveSensor(4,2);

  const int ledPin = 10;
  const int threshold = 300;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  long sensorValue = cap.capacitiveSensor(30);

  Serial.println(sensorValue);

  if (sensorValue > threshold) {
    digitalWrite(ledPin, HIGH);
  }else {
    digitalWrite(ledPin, LOW);
  }
  delay(20);
}
