  const int input = A0;
  const int led1 = 4;
  const int led2 = 5;

void setup() {
  // put your setup code here, to run once:
  pinMode(input, INPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int num = analogRead(input);
  Serial.println(num);

  if (100 < num && num < 1023) {
    digitalWrite(led1, LOW);
    digitalWrite(led2, HIGH);
  }
  delay(200);
}
