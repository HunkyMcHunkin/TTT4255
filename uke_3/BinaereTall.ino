  #include <LiquidCrystal.h>

  const int pinButton = A4;
  int pins[] = {A3,A2,A1,A0}; //Setter koblingen til hver pushbutton i en liste.
  int value[] = {1,2,4,8};    //Setter de tilhørende verdiene i en liste. 2^0 ? 1, 2^1 = 2 osv...
  int pinCount = 4;

  int randNum;
  int binaryValue;
  int correctNumber = 0; //Settes til 1 om tallet er korrekt

  LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  // put your setup code here, to run once:
  lcd.begin(16, 2);
  for (int i = 0; i < pinCount; i++) {
    pinMode(pins[i], INPUT_PULLUP); //initialiserer hver knapp
  }
  pinMode(pinButton, INPUT_PULLUP);
  randNum = random(0,16); //Genererer random tall mellom 0 og 15

  lcd.print("Your number is: ");
  lcd.setCursor(0,1);
  lcd.print(randNum);
}

void checkNumber() {
  printBinary();
  for (int i = 0; i < pinCount; i++) {
    if (digitalRead(pins[i]) == LOW) {
      binaryValue += value[i];
    }
  }
  if (binaryValue == randNum){ //Sjekker om binaryValue er korrekt
    correctNumber = 1;
  }
}

void printBinary() {
  for (int i = 0; i < pinCount; i++) {
    if (digitalRead(pins[3-i]) == HIGH) {
      lcd.print("0");
    }else {
      lcd.print("1");
    }
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  binaryValue = 0;
  if (digitalRead(pinButton) == LOW) {
    lcd.setCursor(3, 1);

    checkNumber();

    if (correctNumber == 0) {
      lcd.clear();
      lcd.setCursor(0, 0);
      printBinary();
      delay(1000);
      lcd.clear();
      lcd.print("Try again");
      lcd.setCursor(0, 1);
      lcd.print(randNum);
    }
    if (correctNumber == 1) {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Correct!");
      lcd.setCursor(0, 1);
      lcd.print(randNum);
      lcd.print(" is ");

      printBinary();

      delay(3000);

      randNum = random(0, 15);

      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Your number is");
      lcd.setCursor(0, 1);
      lcd.print(randNum);

      correctNumber = 0;
    }
  }
}
