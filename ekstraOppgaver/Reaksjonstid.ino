const int btnLeft = 4;     
const int btnRight = 7;     
const int btn3 = 2;     
const int ledLeft = 8;        
const int ledRight = 12;       

int buttonState1;             
int buttonState2;             
int buttonState3;             
int lastButtonState1 = LOW;    
int lastButtonState2 = LOW;    
int lastButtonState3 = LOW;   

unsigned long lastDebounceTime = 0;   
long debounceDelay = 20000;           // debounce tid i microsekunder, sjekker to ganger over kort tid at en knapp faktisk er trykt inn

int randNum;                // Random tall

unsigned long time1;
int button3Pressed = LOW;
int printcount = 0;

int takeReading = LOW;

int reading1, reading2, reading3;

void setup()
{
      pinMode(btnLeft, INPUT);
      pinMode(btnRight, INPUT);
      pinMode(btn3, INPUT);
      pinMode(ledLeft, OUTPUT);
      pinMode(ledRight, OUTPUT);
     
      Serial.begin(115200);
      
      digitalWrite(ledLeft, LOW);
      digitalWrite(ledRight, LOW);
    
      randomSeed(analogRead(0)); //Gjør at rekkefølgen på de tilfledige tallene i random() stokkes
}
    
void loop() 
{
      if( printcount == 0)
      {
          Serial.println("press button 3 when you are ready");
          printcount = 1;
          takeReading = LOW;    // btnLeft og btnRight skal ikke leses
      }
      if( button3Pressed == HIGH)
      {
          digitalWrite(ledLeft, LOW);
          digitalWrite(ledRight, LOW);
          randNum = random(1,3); 
          delay(random(1000,3000));    // Venter en tid mellom 1 og 3 sekunder før et lys slås på
          if ( randNum == 1)
          {
              digitalWrite(ledLeft, HIGH);
              digitalWrite(ledRight, LOW);
              time1 = micros();
          }
          else
          {
              digitalWrite(ledLeft, LOW);
              digitalWrite(ledRight, HIGH);
              time1 = micros();
          }
          button3Pressed = LOW;
      }

      reading3 = digitalRead(btn3);         //les btn3
      
      if(takeReading == HIGH) 
      {
          if(randNum == 1)//Bestemmer hvilket av lysene som skal lyse ut fra verdien av randNum
              reading1 = digitalRead(btnLeft);
          if(randNum == 2)    
              reading2 = digitalRead(btnRight);
      } 
    
      if (reading1 != lastButtonState1 || reading2 != lastButtonState2 || reading3 != lastButtonState3) // Hvis pushbuttonsene har forandret seg
      {
        lastDebounceTime = micros(); // setter ny debouncingtid
      }
      
      if ((micros() - lastDebounceTime) > debounceDelay) 
      {
          if (reading1 != buttonState1) // Hvis verdien til knappen har forandret seg
          {
                buttonState1 = reading1;
                if (buttonState1 == HIGH) 
                {
                  digitalWrite(ledLeft, LOW);
                  Serial.print("Your reaction time is: ");
                  Serial.print((lastDebounceTime - time1)/1000);
                  Serial.println("ms");
                  Serial.println();
                  printcount = 0;
                }
          }

          if (reading2 != buttonState2)
          {
                buttonState2 = reading2;
                if (buttonState2 == HIGH) 
                {
                  digitalWrite(ledRight, LOW);
                  Serial.print("Your reaction time is: ");
                  Serial.print((lastDebounceTime - time1)/1000);
                  Serial.println("ms");
                  Serial.println();
                  printcount = 0;
                }
          }
          if (reading3 != buttonState3)
          {
                buttonState3 = reading3;
                if (buttonState3 == HIGH) 
                {
                  Serial.println("READY TO GO");
                  button3Pressed = HIGH;
                  takeReading = HIGH;
                }
          }
      }
      lastButtonState1 = reading1; //Setter lik forrige lesing
      lastButtonState2 = reading2;
      lastButtonState3 = reading3;
}
 

