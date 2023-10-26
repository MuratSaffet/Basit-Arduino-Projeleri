int TimeValue;
int Value;

void setup() {
  // put your setup code here, to run once:
  pinMode(4, OUTPUT);//Led
  pinMode(5, OUTPUT);//Led
  pinMode(6, OUTPUT);//Led
  pinMode(7, OUTPUT);//Led
  pinMode(8, OUTPUT);//Led

  TimeValue=250;
  Value = 0;
}

void loop() {
  // put your main code here, to run repeatedly:
  int  valueP = analogRead(A0);//Potansiyometre

  while(valueP >= Value){
    leftToRight();
    Value = valueP;
    valueP = analogRead(A0);
  }

  while(valueP <= Value){
    rightToLeft();
    Value = valueP;
    valueP = analogRead(A0);
  }
}

void leftToRight(){
  digitalWrite(4, 1);
  delay(TimeValue);
  digitalWrite(4, 0);

  digitalWrite(5, 1);
  delay(TimeValue);
  digitalWrite(5, 0);

  digitalWrite(6, 1);
  delay(TimeValue);
  digitalWrite(6, 0);

  digitalWrite(7, 1);
  delay(TimeValue);
  digitalWrite(7, 0);

  digitalWrite(8, 1);
  delay(TimeValue);
  digitalWrite(8, 0);
}

void rightToLeft(){
  digitalWrite(8, 1);
  delay(TimeValue);
  digitalWrite(8, 0);

  digitalWrite(7, 1);
  delay(TimeValue);
  digitalWrite(7, 0);

  digitalWrite(6, 1);
  delay(TimeValue);
  digitalWrite(6, 0);

  digitalWrite(5, 1);
  delay(TimeValue);
  digitalWrite(5, 0);

  digitalWrite(4, 1);
  delay(TimeValue);
  digitalWrite(4, 0);
}
