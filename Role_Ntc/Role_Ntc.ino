void setup() {
  // put your setup code here, to run once:
  pinMode(9, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int value = analogRead(A2); // NTC
  Serial.println("NTC = " + String(value));
  
  if (value < 550)
  {
    digitalWrite(9, 0);
  }
  else
  {
    digitalWrite(9, 1);
  }

  delay(analogRead(A0)); //Potansiyometre
}
