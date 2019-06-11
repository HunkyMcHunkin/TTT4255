//Vi tar først å definerer alle variablene.
//Vi gir disse variablene navn som sier hvilken komponent de tilhører.
//Variablene blir gitt en heltallsverdi (int) som er inngangspinnen de skal kobles til på mikrokontrolleren. (Se figurene i trinn 2)
//const betyr constant og betyr at variabelen ikke kan endres.
  const int greenPin = 2;
  const int yellowPin = 3;
  const int redPin = 4;
  const int buttonPin = 8;

  bool redLight = true;       //redLight er av datatypen bool. Denne datatypen kan inneholde "true" eller "false".
  int waitTime = 200;


//Oppsett før kjøring av selve koden i loop().
void setup() {
  //pinMode(pin, mode) er en funksjon som konfigurerer en pin til å oppføre seg som inngang/utgang (INPUT/OUTPUT).
  pinMode(greenPin, OUTPUT);  
  pinMode(yellowPin, OUTPUT);
  pinMode(redPin, OUTPUT);
  pinMode(buttonPin, INPUT); 
  
  //digitalWrite(pin, value) er en funksjon som endrer tilstanden til en pin, enten til HIGH eller LOW.
  //HIGH: Påtrykt spenning. LOW: Ingen spenning.
  digitalWrite(redPin, HIGH); 
}

//Her kommer selve loopen, det er den som kjører når programmet starter.
void loop() {
  //digitalRead(pin) er en funksjon som gir tilbake verdien til pinen (HIGH/LOW).
  //Når knappen (button) er trykket på, går det strøm og spenning igjennom knappen.
  //digitalRead(buttonPin) gir da HIGH når knappen trykkes på.
  //Hvis betingelsene inne i if-parantesen stemmer, dvs at knappen trykkes ned, vil koden inne i krøllparantesen kjøre.
  if (digitalRead(buttonPin) == HIGH) { 
    
    //Hvis betingelsene inne i if-parantesen stemmer, dvs at "redLight" er "true", vil koden inne i krøllparantesen kjøre.
    if (redLight) {

      digitalWrite(yellowPin, HIGH); //"yellowPin" blir påtrykt spenning.
      digitalWrite(redPin, LOW);     //"redPin" blir ikke påtrykt spenning.

      //delay(milliseconds) er en funksjon som pauser programmet. Hvor lenge programmet blir pauset er avhengig av parameteren "milliseconds".
      delay(waitTime);

      digitalWrite(greenPin, HIGH); //Den grønne lysdioden slås på.
      digitalWrite(yellowPin, LOW); //Den gule lysdioden slås av.

      //"redLight" settes til false, slik at neste gang knappen trykkes, vil lysene gå fra grønn til rød.
      redLight = false;
    }
    else { //Hvis betingelsene til if-testen ikke ble oppfylt -> else-koden kjøres.
      
      digitalWrite(yellowPin, HIGH);
      digitalWrite(greenPin, LOW);

      delay(waitTime);

      digitalWrite(redPin, HIGH);
      //Det røde lyset "slåes på".
      digitalWrite(yellowPin, LOW);
      //Det gule lyset "slåes av".

      //"redLight" settes til true, slik at neste gang knappen trykkes, vil lysene gå fra rød til grønn.
      redLight = true;
    }
  }

  delay(waitTime);
}
