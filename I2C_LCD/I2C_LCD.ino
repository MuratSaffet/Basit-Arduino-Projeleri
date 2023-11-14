#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C LCD(0x27, 16, 2);
int WAITING_TIME;

void setup() {
  // put your setup code here, to run once:
  WAITING_TIME = 500;
  LCD.init();
  LCD.backlight();
}

void loop() {
  // put your main code here, to run repeatedly:
  readPot();
  delay(WAITING_TIME);

  readLdr();
  delay(WAITING_TIME);

  readNtc();
  delay(WAITING_TIME);
}

void writeLcd(String text, int value) {
  LCD.clear();
  LCD.setCursor(0, 0);

  LCD.print(text);

  LCD.setCursor(0, 1);
  LCD.print(value);
}

void readPot() {
  int value = analogRead(A0);
  writeLcd("POTANSIYOMETRE", value);
}

void readLdr() {
  int value = analogRead(A1);
  writeLcd("LDR", value);
}

void readNtc() {
  int value = analogRead(A2);
  writeLcd("NTC", value);
}
