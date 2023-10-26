int Value;

void setup() {
  // put your setup code here, to run once:
  pinMode(4, OUTPUT);//Led
  pinMode(5, OUTPUT);//Led
  pinMode(6, OUTPUT);//Led
  pinMode(7, OUTPUT);//Led
  pinMode(8, OUTPUT);//Led

  Value = 0;
}

void loop() {
  // put your main code here, to run repeatedly:
  int  valueP = analogRead(A0);//Potansiyometre

  while(valueP >= Value){
    leftToRight(valueP);
    Value = valueP;
    valueP = analogRead(A0);
  }

  while(valueP <= Value){
    rightToLeft(valueP);
    Value = valueP;
    valueP = analogRead(A0);
  }
}

void leftToRight(int value){
  digitalWrite(4, 1);
  delay(value);
  digitalWrite(4, 0);

  digitalWrite(5, 1);
  delay(value);
  digitalWrite(5, 0);

  digitalWrite(6, 1);
  delay(value);
  digitalWrite(6, 0);

  digitalWrite(7, 1);
  delay(value);
  digitalWrite(7, 0);

  digitalWrite(8, 1);
  delay(value);
  digitalWrite(8, 0);
}

void rightToLeft(int value){
  digitalWrite(8, 1);
  delay(value);
  digitalWrite(8, 0);

  digitalWrite(7, 1);
  delay(value);
  digitalWrite(7, 0);

  digitalWrite(6, 1);
  delay(value);
  digitalWrite(6, 0);

  digitalWrite(5, 1);
  delay(value);
  digitalWrite(5, 0);

  digitalWrite(4, 1);
  delay(value);
  digitalWrite(4, 0);
}
