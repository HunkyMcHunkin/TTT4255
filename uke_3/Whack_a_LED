//Pin der joysticken er koblet til
const int X_pin = A0;
const int Y_pin = A1;

//Globale variabler
int wins = 0;
int highscore = 0;

int ledPins[] = {2, 3, 4, 5, 6, 7};
int pinCount = 6;

void setup() {
  Serial.begin(115200);
  pinMode(X_pin, INPUT);
  pinMode(Y_pin, INPUT);

  for (int i = 0; i < pinCount; i++){
    //setter alle lysdiodene som utganger
    pinMode(ledPins[i], OUTPUT);
  }
}

void loop() {
  int rNum = random(4);
  delay(1500);

  digitalWrite(ledPins[rNum], HIGH); //Skrur på en lysdiode
  delay(500); //tiden du har til å reagere

  int x = analogRead(X_pin); //leser av joysticken
  int y = analogRead(Y_pin);

  int s = 4;
  if(x < 300){
    s = 3;
  }
  if(x > 800){
    s = 0;    
  }
  if (y < 300){
    s = 2;
  }
  if (y > 800){
    s = 1;
  }

  digitalWrite(ledPins[rNum], LOW); //slår av lysdioden
  if(s == rNum){ //ser om joysticken sto riktig
    wins++;
    digitalWrite(ledPins[4], HIGH); //Skrur av/på den grønne lysdioden
    delay(500);
    digitalWrite(ledPins[4], LOW);    
  }
else {
  if (wins > highscore){ //Ser om det er ny highscore
    highscore = wins ;
    Serial.println("Gratulerer du har satt ny rekord");
  }
  digitalWrite(ledPins[5], HIGH); //Skrur av/på den røde lysdioden
  delay(500);
  digitalWrite(ledPins[5], LOW);
  Serial.print("Correct: "); //Skriver ut resultatene
  Serial.print(wins);
  Serial.print(" Highscore: ");
  Serial.println(highscore);
  wins = 0;
}
delay(500);
}
