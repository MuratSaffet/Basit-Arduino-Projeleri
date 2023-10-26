bool StatusValue;
void setup() {
  // put your setup code here, to run once:
  pinMode(4, OUTPUT);//Led
  pinMode(5, OUTPUT);//Led
  pinMode(6, OUTPUT);//Led
  pinMode(7, OUTPUT);//Led
  pinMode(8, OUTPUT);//Led

  pinMode(2, INPUT);//Buton
  pinMode(3, INPUT);//Buton

  StatusValue = false;
}

void loop() {
  // put your main code here, to run repeatedly:
  
  int pin2 = digitalRead(2);
  int pin3 = digitalRead(3);
  int value = analogRead(A0);//Potansiyometre

  if(pin2==1){
    StatusValue = false;
  }
  if(pin3==1){
    StatusValue = true;
  }

  if(StatusValue){
    leftToRight(value);
  }
  else{
    rightToLeft(value);
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
