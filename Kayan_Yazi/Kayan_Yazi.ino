#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C LCD(0x27, 16, 2);

bool SITUATION;
String TEXT = "BEN ARDUINO... ";

void setup() {
  // put your setup code here, to run once:
  LCD.init();
  LCD.backlight();

  pinMode(A0, INPUT); // Potansiyometre
  pinMode(2, INPUT); // Buton 1
  pinMode(3, INPUT); // Buton 2

  SITUATION = false;
}

void loop() {
  // put your main code here, to run repeatedly:
  if (digitalRead(2) == 1) {
    SITUATION = false;
  }

  if (digitalRead(3) == 1) {
    SITUATION = true;
  }

  int timeValue = analogRead(A0);
  if (SITUATION) {
    rightToLeft(timeValue);
  }
  else {
    leftToRight(timeValue);
  }
}

void leftToRight(int value) {
  int CHARACTER_NUMBER = TEXT.length();
  for (int K = CHARACTER_NUMBER + 1; K >= 0; K--) {
    String Subtext = "";
    for (int K2 = K; K2 < CHARACTER_NUMBER; K2++)
      Subtext += TEXT[K2];
    LCD.clear();
    LCD.setCursor(0, 0); // (SUTUN,SATIR)
    LCD.print(Subtext);
    delay(value);
  }

  for (int COLUMN = 0; COLUMN <= 16; COLUMN++) {
    LCD.clear();
    LCD.setCursor(COLUMN, 0);
    LCD.print(TEXT);
    delay(value);
  }
}

void rightToLeft(int value) {
  for (int COLUMN = 15; COLUMN > 0; COLUMN--) {
    LCD.clear();
    LCD.setCursor(COLUMN, 0);
    LCD.print(TEXT);
    delay(value);
  }

  int CHARACTER_NUMBER = TEXT.length();
  for (int K = 0; K < CHARACTER_NUMBER; K++) {
    String Subtext = "";
    for (int K2 = K; K2 < CHARACTER_NUMBER; K2++)
      Subtext += TEXT[K2];
    LCD.clear();
    LCD.setCursor(0, 0); // (SUTUN,SATIR)
    LCD.print(Subtext);
    delay(value);
  }
}
