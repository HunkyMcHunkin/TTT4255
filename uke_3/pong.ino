#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h> 
//If using software SPI (the default case):
/*
#define OLED_MOSI 11 //D1
#define OLED_CLK 12 //D0
#define OLED_DC 9
#define OLED_CS 8
#define OLED_RESET 10
*/
#define OLED_RESET 10


int ball_x = 62;
int ball_y = 15;
int ball_dir_x = 1, ball_dir_y = 1;
int playerlScore = 0;
int player2Score = 0; 
// Adafruit_SSD1306 display(OLED_MOSI, OLED_CLK, OLED_DC, OLED_RESET, OLED_CS);
Adafruit_SSD1306 display(OLED_RESET);

void setup() {
  Serial.begin(9600);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.display();
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.drawFastVLine(ball_x, ball_y, 1, WHITE);
  updateScore(); 
}

void loop() {
  display.setCursor(0,0);
  display.clearDisplay(); 
  int a = analogRead(A1);
  float play1 = a/1023.0*15.0;
  int b = analogRead(A0);
  float play2 = b/1023.0*15.0;
  display.drawFastVLine(6, play1, 10, WHITE);
  display.drawFastVLine(118, play2,10, WHITE);
  
  ball_x += ball_dir_x;
  ball_y += ball_dir_y;
  display.drawFastVLine(ball_x, ball_y, 1, WHITE);
  
  if (ball_y == 0 || ball_y == 30){ // Ballen bytter retning nar den treffer øvre og nedre vegg
    ball_dir_y *=-1; 
  }
  if (ball_x == 0) {//Gir poeng + skifter retning hvis ballen gar ut
    player2Score++;
    ball_dir_x *=1;
    updateScore();
    ball_x = 62;
    ball_y = 15;
    delay(100);
  }
  if (ball_x == 124){
    playerlScore++;
    ball_dir_x *= -1;
    updateScore();
    ball_x = 62;
    ball_y = 15;
    delay(100); 
  }
  if ((ball_x == 6 && (play1 < ball_y) && (ball_y < (play1+9))) || (ball_x == 118 && (play2 < ball_y) && (ball_y < (play2+9)))){
    ball_dir_y *= -1;
    ball_dir_x *= -1; 
  }
  display.display();
}

void updateScore(){
  Serial.print("Player 1s score: ");
  Serial.println(playerlScore);
  Serial.print("Player 2s score: ");
  Serial.println(player2Score);
  Serial.println(" "); 
}
