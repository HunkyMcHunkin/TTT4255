  const int sensorPin = A0;
  int sensorValue;
  float voltage;
  float temperature;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  
  pinMode(sensorPin, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  sensorValue = analogRead(sensorPin);
  voltage = sensorValue * (5.0/1024);
  temperature = (voltage - 0.5) * 100;

  Serial.print("sensorValue: ");
  Serial.print(sensorValue);
  Serial.print(" voltage: ");
  Serial.print(voltage);
  Serial.print(" temperature: ");
  Serial.println(temperature);

  delay(500);
}
