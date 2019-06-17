  #include <LiquidCrystal.h>
  LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

  const int sensorPin = A0;
  float sensorVal, temp, voltage;
  
void setup() {
  // put your setup code here, to run once:
  lcd.begin(16,2);

  pinMode(sensorPin, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  sensorVal = analogRead(sensorPin);
  voltage = sensorVal * (5000/1024);
  temp = (voltage/10);

  lcd.clear();
  lcd.print("Temperatur:");
  lcd.setCursor(0,1);
  lcd.print(temp);
  lcd.print(" C");
  lcd.setCursor(0,0);

  delay(1000);
}
