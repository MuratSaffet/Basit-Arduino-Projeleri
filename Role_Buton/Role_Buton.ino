void setup() {
  // put your setup code here, to run once:
  pinMode(9, OUTPUT);
  pinMode(2, INPUT); // Buton 1
  pinMode(3, INPUT); // Buton 2
}

void loop() {
  // put your main code here, to run repeatedly:
  if (digitalRead(2)) {
    digitalWrite(9, 1);
  }

  if (digitalRead(3)) {
    digitalWrite(9, 0);
  }

  delay(analogRead(A0));// Potansiyometre
}
