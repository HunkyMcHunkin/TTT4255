  
//Vi tar først å definerer alle variablene.
  const int greenPin = 2;
  const int yellowPin = 3;
  const int redPin = 4;
  const int buttonPin = 8;

//Gir portene navn som sier hvilken lysdiode de tilhører. Disse er konstante, dvs at de ikke kan endres når programmet kompilerer. 
//Datatypen "int" tilsier at den tilgitte verdien er et heltall (integer).

  bool redLight = true;
  int waitTime = 200;

//Gir redLight verdien "true", vha datatypen bool som kan innholde enten "true" eller "false".
//Ventetiden blir satt til 200 milisekunder (???). 

void setup() {
  //Her får variablene definert sin funksjon i arduinoen. 
  pinMode(greenPin, OUTPUT);
  pinMode(yellowPin, OUTPUT);
  pinMode(redPin, OUTPUT);
  pinMode(buttonPin, INPUT);
  //De tre lysdiodene blir satt til å være output, mens knappen blir input. 
  
  digitalWrite(redPin, HIGH);
  //Sier at redPin skal være "true" når inngangen er logisk høy. 
}


//Her kommer selve loopen, det er den som kjører når programmet starter.

void loop() {
  //Hvis knappen trykkes ned, så vil første "if"-argunent kjøre. 
  if (digitalRead(buttonPin) == HIGH) {
    
    //Hvis det røde lyset er det som lyser fra før, altså at "redLight" er "true", vil denne koden kjøre.
    if (redLight) {

      digitalWrite(yellowPin, HIGH);
      //Det gule lyset "slåes på".
      digitalWrite(redPin, LOW);
      //Det røde lyset "slåes av".
      

      delay(waitTime);
      //Venter "waitTime" (200ms) før programmet fortsetter.

      digitalWrite(greenPin, HIGH);
      //Det grønne lyset slåes på.
      digitalWrite(yellowPin, LOW);
      //Det gule lyset slåes av.

      redLight = false;
      //"redLight" settes til false, slik at neste gang knappen trykkes, vil lysene gå fra grønn til rød.
      
    }
    else {
      
      digitalWrite(yellowPin, HIGH);
      //Det gule lyset "slåes på".
      digitalWrite(greenPin, LOW);
      //Det grønne lyset "slåes av".

      delay(waitTime);
      //Venter 200ms.

      digitalWrite(redPin, HIGH);
      //Det røde lyset "slåes på".
      digitalWrite(yellowPin, LOW);
      //Det gule lyset "slåes av".

      redLight = true;
      //Neste gang vil lysene gå fra rød til grønn.
    }
  }

  delay(waitTime);
  //Holder igjen, slik at man ikke kan trykke på knappen igjen før det er gått 200 ms (den vil hvertfall ikke reagere før den tid). 
}
