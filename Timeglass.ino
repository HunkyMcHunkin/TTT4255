  
//Variablene defineres og tildeles en pin på arduinoen.
const int startLed = 2;
const int buttonPin = 13;

//Antallet lysdioder som skal være med.
const int numberOfLed = 6;

void setup() {
  //Dette er bare en enkel måte å sette hver pin som er koblet opp til en diode til å være output. 
  //Den første pinnen er "startLed", altså 2, den neste er 3 o.s.v.
  for (int i = 0; i < numberOfLed; i++) {
    pinMode(startLed + i, OUTPUT);
  }
  
  //Knappen blir satt til å være input. 
  pinMode(buttonPin, INPUT);
}

void loop() {
  //Her skrives koden som kjøres i loop når programmet kjøres. 
  //Hvis knappen trykkes ned skal koden i "if"-krøllparantese kjøres. 
  //Her settes først alle lysdiodene til "HIGH", dvs at de "slås på".
  //Deretter slås de av en etter en, med et mellomrom på 1000ms.
  if (digitalRead(buttonPin) == HIGH) {
    for (int i = 0; i < numberOfLed; i++) {
      digitalWrite(startLed + i, HIGH);
    }
    for (int i = 0; i < numberOfLed; i++) {
      delay(1000);
      digitalWrite(startLed + i, LOW);
    }
  }

  delay(10);
}
