  #include <Servo.h>
  Servo servo;

  const int sensorPin1 = A0;
  const int sensorPin2 = A1;
  int angle = 90;
  int angleLen = 3;
  
void setup() {
  // put your setup code here, to run once:
  pinMode(sensorPin1, INPUT);
  pinMode(sensorPin2, INPUT);

  servo.attach(6);
}

void loop() {
  // put your main code here, to run repeatedly:
  int sensorVal1 = analogRead(sensorPin1);
  int sensorVal2 = analogRead(sensorPin2);

  if (sensorVal1 > sensorVal2) {
    if (angle + angleLen < 180) {
      angle += angleLen;
      servo.write(angle);
    }
  }
  else if (sensorVal1 < sensorVal2) {
    if (angle - angleLen > 0) {
      angle -= angleLen;
      servo.write(angle);
    }
  }
  delay(1000);
}
