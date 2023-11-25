void setup() {
  // put your setup code here, to run once:
  pinMode(9, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int value = analogRead(A1);
  Serial.println("LDR = " + String(value));
  
  if (value < 500) // LDR
  {
    digitalWrite(9, 0);
  }
  else
  {
    digitalWrite(9, 1);
  }

  delay(analogRead(A0)); //Potansiyometre
}
