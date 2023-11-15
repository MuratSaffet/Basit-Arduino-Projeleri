#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C LCD(0x27, 16, 2);

const int TRIG = 8;
const int ECHO = 12;

float DISTANCE;

void setup() {
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);
  pinMode(A0, INPUT);

  LCD.init();
  LCD.backlight();
}

void loop() {
  // put your main code here, to run repeatedly:
  calculateDistance();
  printLcd();
  delay(analogRead(A0));
}

void calculateDistance() {
  digitalWrite(TRIG, 0);
  delayMicroseconds(10);
  digitalWrite(TRIG, 1);
  delayMicroseconds(10);
  digitalWrite(TRIG, 0);
  int delayValue = pulseIn(ECHO, 1);
  DISTANCE = delayValue * 0.034 / 2;
}

void printLcd() {
  LCD.clear();
  LCD.setCursor(0, 0);
  LCD.print("DISTANCE(CM):" + String(DISTANCE));
  LCD.setCursor(0, 1);
  LCD.print("DISTANCE(MT):" + String(DISTANCE / 100));
}
