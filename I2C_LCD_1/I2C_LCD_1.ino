#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C LCD(0x27, 16, 2);

int WAITING_TIME;

void setup() {
  // put your setup code here, to run once:
  LCD.init();
  LCD.backlight();

  WAITING_TIME = 500;
}

void loop() {
  // put your main code here, to run repeatedly:
  int POT = analogRead(A0);
  int LDR = analogRead(A1);
  int NTC = analogRead(A2);

  writeLcd("POT___LDR___NTC", POT, LDR, NTC);
  delay(WAITING_TIME);
}

void writeLcd(String text, int pot, int ldr, int ntc) {
  LCD.clear();
  LCD.setCursor(0, 0);
  LCD.print(text);

  LCD.setCursor(0, 1);
  LCD.print(pot);
  LCD.setCursor(6, 1);
  LCD.print(ldr);
  LCD.setCursor(12, 1);
  LCD.print(ntc);
}
