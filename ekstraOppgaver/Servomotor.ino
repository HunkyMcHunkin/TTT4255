#include <Servo.h>
Servo servo;

int data = 0;

void setup() {
  // put your setup code here, to run once:
  servo.attach(3);

  Serial.begin(9600);
  while(!Serial){}
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available() > 1) {
    data = Serial.parseInt();
    if (data <= 5) {
      data = 5;
    }
    if (data >= 180) {
      data = 180;
    }
    Serial.print("Setter servoen til ");
    Serial.print(data, DEC);
    Serial.println(" grader");
    servo.write(data);
  }
  delay(1000);
}
