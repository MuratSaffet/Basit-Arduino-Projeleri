void setup() {
  // put your setup code here, to run once:
  pinMode(4, OUTPUT);//Led
  pinMode(5, OUTPUT);//Led
  pinMode(6, OUTPUT);//Led
  pinMode(7, OUTPUT);//Led
  pinMode(8, OUTPUT);//Led
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(4, 1);
  delay(analogRead(A0));
  
  digitalWrite(5, 1);
  delay(analogRead(A0));

  digitalWrite(6, 1);
  delay(analogRead(A0));

  digitalWrite(7, 1);
  delay(analogRead(A0));

  digitalWrite(8, 1);
  delay(analogRead(A0));

  digitalWrite(4, 0);
  delay(analogRead(A0));
  
  digitalWrite(5, 0);
  delay(analogRead(A0));

  digitalWrite(6, 0);
  delay(analogRead(A0));

  digitalWrite(7, 0);
  delay(analogRead(A0));

  digitalWrite(8, 0);
  delay(analogRead(A0));
}
