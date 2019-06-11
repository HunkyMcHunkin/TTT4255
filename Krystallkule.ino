  #include <LiquidCrystal.h>
  LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

  const int buttonPin = 13;
  const int predictions = 7;
  int reply;
  
void setup() {
  // put your setup code here, to run once:
  lcd.begin(16,2);
  pinMode(buttonPin, INPUT);

  lcd.print("Spoer");
  lcd.setCursor(0,1);
  lcd.print("Krystallkulen!");
}

void loop() {
  // put your main code here, to run repeatedly:
  if (digitalRead(buttonPin) == HIGH) {
    reply = random(predictions);

    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Den sier: ");
    lcd.setCursor(0,1);

    switch(reply) {
      case 0:
        lcd.print("Ja!");
        break;
      case 1:
        lcd.print("Mest sannsynlig");
        break;
      case 2:
        lcd.print("Garantert");
        break;
      case 3:
        lcd.print("Nei!");
        break;
      case 4:
        lcd.print("Usikkert");
        break;
      case 5:
        lcd.print("Tviler");
        break;
      case 6:
        lcd.print("Tjaaaa");
        break;
    }
  }

  delay(1000);
}
